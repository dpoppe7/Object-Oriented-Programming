#pragma once
#undef UNICODE
#include <windows.h>

#include "Window.hpp"

namespace easywin {
  
  void registerClass(HINSTANCE hInstance, const char* className);

};

