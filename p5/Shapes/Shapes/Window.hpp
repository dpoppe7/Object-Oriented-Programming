#pragma once
#undef UNICODE
#include <windows.h>
#include <string>
#include <vector>
#include "Canvas.hpp"

namespace easywin {

  class Window {
    HWND hwnd;

   protected:
    Window(HINSTANCE hInstance, const char* className);
    void requestRepaint();
    void addMenu(std::string name);
    void addMenuItem(int menuPos, std::string name, int id);

   public:
    Window(HINSTANCE hInstance) : Window(hInstance, "Window") { }
    int run();
    std::string getTitle();
    void setTitle(const std::string& title);

    virtual void paint(Canvas& canvas);
    virtual void mouseMove(int x, int y);
    virtual void mouseButtonDown(int x, int y);
    virtual void mouseButtonUp(int x, int y);
    virtual void mouseButtonDoubleClick(int x, int y);
    virtual void mouseWheel(int x, int y, bool up);
    virtual void menuSelect(int id);
  };

}  // namespace easywin
