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

}  // namespace shapes