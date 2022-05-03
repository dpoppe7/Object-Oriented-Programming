#pragma once
#include "ShapeManager.hpp"
#include "Window.hpp"

namespace shapes {

  using easywin::Canvas;
  using easywin::Color;
  using easywin::Point;

  // I'm only declaring it; you need to define it
  class Shape{
  public:
      Shape(int x, int y, int size, Color color) : xCoord(x), yCoord(y), shapeSize(size), a_color(color) {}
      virtual ~Shape() = default;
      int x() const { return xCoord; }
      int y() const { return yCoord; }
      int size() const { return shapeSize; }
      Color color() const { return a_color; };


      void move(int x, int y);
      void resize(int size);
      std::shared_ptr<Shape> clone() const;

      bool contains(int x, int y) const;
      void draw(easywin::Canvas& canvas) const;


      bool operator == (const Shape& other) const {
          return equalTo(other);
      }
      bool operator !=(const Shape&) const;

      virtual bool equalTo(const Shape& other) const = 0;
      virtual bool doEqualTo(const Circle& other) const { return false; }
      virtual bool doEqualTo(const Rectangle& other) const { return false;


  protected:
      int xCoord;
      int yCoord;
      int shapeSize;
      Color a_color;
  };

}