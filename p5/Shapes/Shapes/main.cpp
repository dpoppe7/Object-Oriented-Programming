#undef UNICODE
#include <time.h>
#include <windows.h>
#include <windowsx.h>

#include <exception>

#include "ShapesWindow.hpp"
#include "Win32dow.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
  int status = 0;

  try {
    shapes::ShapesWindow window(hInstance);
    status = window.run();
  } 
  catch (std::exception &e) {
    MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
  }

  return status;
}
