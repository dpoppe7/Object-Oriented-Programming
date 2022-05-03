#include "../Shapes/Shape.hpp"
#include "../Shapes/ShapeManager.hpp"
#include "TestCanvas.hpp"
#include <gtest/gtest.h>

const easywin::Color BLUE = easywin::rgb(0, 0, 255);
const easywin::Color BLACK = 0;

TEST(Circle, BoundingBox) {
  auto p = shapes::ShapeManager::makeShape(
    shapes::ShapeManager::ShapeType::Circle,
    123,
    456,
    200,
    BLUE
  );

  ASSERT_EQ(p->x(), 123);
  ASSERT_EQ(p->y(), 456);
  ASSERT_EQ(p->size(), 200);
}

TEST(Circle, Drawing) {
  auto p = shapes::ShapeManager::makeShape(
    shapes::ShapeManager::ShapeType::Circle,
    123,
    456,
    200,
    BLUE
  );
  easywin::TestCanvas canvas;

  p->draw(canvas);

  ASSERT_EQ(canvas.size(), 1);
  // center is over size/2, down size/2
  // radius is size/2
  ASSERT_EQ(canvas[0], (easywin::DrawEllipse{ { 223, 556 }, 100, BLACK, BLUE }));
}
