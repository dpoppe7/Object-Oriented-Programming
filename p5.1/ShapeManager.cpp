#include "ShapeManager.hpp"
#include <stdexcept>
#include <map>
#include <algorithm>

namespace shapes {
  const std::map<ShapeManager::ShapeType, std::string> ShapeManager::shapeTypes = {
    { ShapeManager::ShapeType::Square,   "Square"  },
    { ShapeManager::ShapeType::Circle,   "Circle"  },
    { ShapeManager::ShapeType::Triangle, "Triangle"}
  };

  // Write your methods here:
  static std::shared_ptr<Shape> makeShape(ShapeType type, int x, int y, int size, Color color){
      std::shared_ptr<Shape> shape = ShapeManager::shapeTypes.find(type);
      return shape;
      /*for (auto ; itr != ShapeManager::shapeTypes.end(); itr++) {
          std::shared_ptr<Shape> shape = itr->first;
      }*/
  }
  void addShape(std::shared_ptr<Shape> shape){
      shapes.push_back(shape);
  }
  std::shared_ptr<Shape> select(int x, int y);
  void drawShapes(Canvas& canvas) const;

}  // namespace shapes