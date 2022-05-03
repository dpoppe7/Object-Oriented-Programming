#include "ShapesWindow.hpp"
#include "Shape.hpp"
#include <Windows.h>
using namespace std;

namespace shapes {

  ShapesWindow::ShapesWindow(HINSTANCE hInstance) : Window(hInstance, "ShapesWindow"), engine(std::random_device{}()) {
    setTitle("My Shapes Window");

    addMenu("&Shapes");
    for (auto type : ShapeManager::shapeTypes) {
      addMenuItem(0, "New &" + type.second, (int)type.first);
    }
  }

  void ShapesWindow::paint(Canvas& canvas) {
    Window::paint(canvas);

    shapeManager.drawShapes(canvas);
  }

  void ShapesWindow::mouseMove(int x, int y) {
    if (selected) {
      int xOffset = x - lastx;
      int yOffset = y - lasty;
      selected->move(selected->x() + xOffset, selected->y() + yOffset);
      requestRepaint();
      lastx = x;
      lasty = y;
    }
  }

  void ShapesWindow::mouseButtonDown(int x, int y) {
    selected = shapeManager.select(x, y);
    if (selected) {
      requestRepaint();
      lastx = x;
      lasty = y;
    }
  }

  void ShapesWindow::mouseButtonUp(int x, int y) {
    selected = nullptr;
  }

  void ShapesWindow::mouseButtonDoubleClick(int x, int y) {
    auto shape = shapeManager.select(x, y);
    if (shape) {
      auto copy = shape->clone();
      copy->move(100, 100);
      shapeManager.addShape(copy);
      requestRepaint();
    }
  }

  void ShapesWindow::mouseWheel(int x, int y, bool up) {
    auto shape = shapeManager.select(x, y);

    if (shape) {
      shape->resize(shape->size() + (up ? 10 : -10));
      requestRepaint();
    }
  }

  void ShapesWindow::menuSelect(int id) {
    const int x = 100, y = 100, size = 100;
    const std::uniform_int_distribution<unsigned int> randByte(0, 255);
    const COLORREF color =
      RGB(randByte(engine), randByte(engine), randByte(engine));

    auto shape = shapeManager.makeShape((ShapeManager::ShapeType)id, x, y, size, color);
    shapeManager.addShape(shape);
    requestRepaint();
  }

}  // namespace shapes