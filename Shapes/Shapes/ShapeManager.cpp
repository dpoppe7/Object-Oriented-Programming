#include "ShapeManager.hpp"
#include <stdexcept>
#include <algorithm>

namespace shapes {
  const std::map<ShapeManager::ShapeType, std::string> ShapeManager::shapeTypes = {
    { ShapeManager::ShapeType::Square,   "Square"  },
    { ShapeManager::ShapeType::Circle,   "Circle"  },
    { ShapeManager::ShapeType::Triangle, "Triangle"}
  };

  // Write your methods here:
  static std::shared_ptr<Shape> ShapeManager::makeShape(ShapeType type, int x, int y, int size, Color color) {
      Shape myShape(x, y, size, color);
      myShape.setShapeType(type);
        //type?
      a_shape = myShape;
      return std::make_shared<Shape>(a_shape);
  }

  void ShapeManager::addShape(std::shared_ptr<Shape> shape){
      shapes.push_back(shape);
  }

  std::shared_ptr<Shape> ShapeManager::select(int x, int y){
      for (const auto&  e : shapes){
          if (std::static_pointer_cast<Shape>( ( e->x() ) ) == x &&
              std::static_pointer_cast<Shape>( ( e->y() ) ) == y ){

              shapes.insert(shapes.begin(), e);
              shapes.erase(e);

              return std::static_pointer_cast<Shape>(e)
          }
      }
      return nullptr;
  }

  void ShapeManager::drawShapes(Canvas& canvas) const{
        //if square, circle ...
        if ()
  }

}  // namespace shapes