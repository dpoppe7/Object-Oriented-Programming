#include "Window.hpp"
#include "Win32dow.hpp"

#include <stdexcept>

using namespace std;

namespace easywin {

  void Window::requestRepaint() { 
    InvalidateRect(hwnd, NULL, true); 
  }

  void Window::addMenu(string name) {
    HMENU hmenu = GetMenu(hwnd);
    if (hmenu == 0) {
      hmenu = CreateMenu();
    }

    HMENU hPopup = CreateMenu();

    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hPopup, name.c_str());

    if (SetMenu(hwnd, hmenu) == 0) {
      throw runtime_error("Cannot create menu");
    }
  }

  void Window::addMenuItem(int menuPos, std::string item, int id) {
    HMENU hmenu = GetMenu(hwnd);

    if (hmenu == 0) {
      throw logic_error("Called addMenuItem with invalid menuPos");
    }

    HMENU hPopup = GetSubMenu(hmenu, menuPos);

    if (hPopup == 0) {
      throw logic_error("Called addMenuItem with invalid menuPos");
    }

    AppendMenu(hPopup, MF_STRING, (UINT_PTR)id, item.c_str());
  }

  Window::Window(HINSTANCE hInstance, const char* className) {
    registerClass(hInstance, className);

    hwnd = CreateWindow(
      className,            // window class name
      "Window",             // window caption
      WS_OVERLAPPEDWINDOW,  // window style
      CW_USEDEFAULT,        // initial x position
      CW_USEDEFAULT,        // initial y position
      CW_USEDEFAULT,        // initial x size
      CW_USEDEFAULT,        // initial y size
      NULL,                 // parent window handle
      NULL,                 // window menu handle
      hInstance,            // program instance handle
      this
    );
  }

  int Window::run() {
    ShowWindow(hwnd, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    return (int)msg.wParam;
  }

  string Window::getTitle() {
    char buffer[200];
    GetWindowText(hwnd, buffer, 200);
    return buffer;
  }

  void Window::setTitle(const string& title) {
    SetWindowText(hwnd, title.c_str());
  }

  void Window::paint(Canvas& canvas) {
    RECT client;
    GetClientRect(hwnd, &client);

    canvas.drawRectangle(0, 0, client.right, client.bottom, 0xffffff, 0xffffff);
  }

  void Window::mouseMove(int x, int y) { }

  void Window::mouseButtonDown(int x, int y) { }

  void Window::mouseButtonUp(int x, int y) { }

  void Window::mouseButtonDoubleClick(int x, int y) { }

  void Window::mouseWheel(int x, int y, bool up) { }

  void Window::menuSelect(int i) { }

}  // namespace easywin