#pragma once
#include "ShapeManager.hpp"
#include "Window.hpp"
#include <random>

namespace shapes {
  class ShapesWindow : public easywin::Window {
    ShapeManager shapeManager;
    std::shared_ptr<Shape> selected;
    int lastx = 0, lasty = 0;
    std::default_random_engine engine;

   public:
    ShapesWindow(HINSTANCE hInstance);

    void paint(easywin::Canvas& canvas) override;
    void mouseMove(int x, int y) override;
    void mouseButtonDown(int x, int y) override;
    void mouseButtonUp(int x, int y) override;
    void mouseButtonDoubleClick(int x, int y) override;
    void mouseWheel(int x, int y, bool up) override;
    void menuSelect(int id) override;
  };

}  // namespace shapes
