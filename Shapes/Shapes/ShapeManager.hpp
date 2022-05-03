#pragma once
#include <memory>
#include <map>
#include <string>
#include "Canvas.hpp"
#include "Shape.hpp"

namespace shapes {

  class ShapeManager {
  public:
    enum class ShapeType { Square, Circle, Triangle };
    const static std::map<ShapeType, std::string> shapeTypes;

    static std::shared_ptr<Shape> makeShape(ShapeType type, int x, int y, int size, Color color);
    void addShape(std::shared_ptr<Shape> shape);
    std::shared_ptr<Shape> select(int x, int y);
    void drawShapes(Canvas& canvas) const;

  private

    std::vector<std::shared_ptr<Shape>> shapes;
  };

}