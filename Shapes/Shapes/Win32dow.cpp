#define _WIN32_WINNT 0x500
#include "Win32dow.hpp"
#include "GdiCanvas.hpp"

#include <windowsx.h>
#include <stdexcept>
#include <string>
#include <typeinfo>

namespace easywin {

  BOOL onCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {
    Window* window = (Window*)lpCreateStruct->lpCreateParams;
    SetWindowLongPtr(hwnd, 0, (LONG_PTR)window);
    std::string name = typeid(*window).name();
    return true;
  }

  void onPaint(HWND hwnd) {
    Window* window = (Window*)GetWindowLongPtr(hwnd, 0);

    RECT client;
    GetClientRect(hwnd, &client);

    PAINTSTRUCT ps;
    HDC screenHdc = BeginPaint(hwnd, &ps);

    HDC hdc = CreateCompatibleDC(screenHdc);
    HBITMAP bitmap =
        CreateCompatibleBitmap(screenHdc, client.right + 1, client.bottom + 1);
    HGDIOBJ oldBitmap = SelectObject(hdc, bitmap);

    BitBlt(hdc, 0, 0, client.right + 1, client.bottom + 1, screenHdc, 0, 0, SRCCOPY);

    SelectObject(hdc, GetStockObject(DC_PEN));
    SelectObject(hdc, GetStockObject(DC_BRUSH));

    GdiCanvas canvas(hdc);

    window->paint(canvas);

    BitBlt(screenHdc, 0, 0, client.right + 1, client.bottom + 1, hdc, 0, 0, SRCCOPY);

    EndPaint(hwnd, &ps);

    SelectObject(hdc, oldBitmap);
    DeleteObject(bitmap);
    DeleteDC(hdc);
  }

  void onLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) {
    Window* window = (Window*)GetWindowLongPtr(hwnd, 0);

    if (fDoubleClick) {
      window->mouseButtonDoubleClick(x, y);
    } 
    else {
      window->mouseButtonDown(x, y);
    }

    SetCapture(hwnd);
  }

  void onMouseMove(HWND hwnd, int x, int y, UINT keyFlags) {
    Window* window = (Window*)GetWindowLongPtr(hwnd, 0);

    window->mouseMove(x, y);
  }

  void onLButtonUp(HWND hwnd, int x, int y, UINT keyFlags) {
    Window* window = (Window*)GetWindowLongPtr(hwnd, 0);

    window->mouseButtonUp(x, y);

    ReleaseCapture();
  }

  void onMouseWheel(HWND hwnd, int xPos, int yPos, int zDelta, UINT fwKeys) {
    Window* window = (Window*)GetWindowLongPtr(hwnd, 0);

    POINT p = {xPos, yPos};

    ScreenToClient(hwnd, &p);

    window->mouseWheel(p.x, p.y, zDelta > 0);
  }

  void onCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {
    Window* window = (Window*)GetWindowLongPtr(hwnd, 0);

    if (hwndCtl == 0 && codeNotify == 0) {
      window->menuSelect(id);
    }
  }

  void onDestroy(HWND hwnd) { 
    PostQuitMessage(0); 
  }

  LRESULT CALLBACK wndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
      HANDLE_MSG(hwnd, WM_CREATE, onCreate);
      HANDLE_MSG(hwnd, WM_PAINT, onPaint);
      HANDLE_MSG(hwnd, WM_LBUTTONDOWN, onLButtonDown);
      HANDLE_MSG(hwnd, WM_MOUSEMOVE, onMouseMove);
      HANDLE_MSG(hwnd, WM_LBUTTONUP, onLButtonUp);
      HANDLE_MSG(hwnd, WM_MOUSEWHEEL, onMouseWheel);
      HANDLE_MSG(hwnd, WM_LBUTTONDBLCLK, onLButtonDown);
      HANDLE_MSG(hwnd, WM_COMMAND, onCommand);
      HANDLE_MSG(hwnd, WM_DESTROY, onDestroy);
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
  }

  void registerClass(HINSTANCE hInstance, const char* className) {
    WNDCLASS wndclass;
    memset(&wndclass, 0, sizeof(WNDCLASS));

    if (hInstance == 0)
      throw std::logic_error("Cannot create windows until you initialized hInstance");

    if (GetClassInfo(hInstance, className, &wndclass) == 0) {
      wndclass.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
      wndclass.lpfnWndProc = wndProc;
      wndclass.cbClsExtra = 0;
      wndclass.cbWndExtra = sizeof(Window*);
      wndclass.hInstance = hInstance;
      wndclass.hIcon = NULL;
      wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
      wndclass.hbrBackground = NULL;
      wndclass.lpszMenuName = NULL;
      wndclass.lpszClassName = className;

      if (RegisterClass(&wndclass) == 0)
        throw std::runtime_error(std::string("Unable to register class ") + className);
    }
  }

}  // namespace Win32dow
