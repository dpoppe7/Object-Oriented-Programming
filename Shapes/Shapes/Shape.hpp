#pragma once
#include "ShapeManager.hpp"
#include "Window.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"


namespace shapes {

  using easywin::Canvas;
  using easywin::Color;
  using easywin::Point;

  // I'm only declaring it; you need to define it
  class Shape{
  protected:
      int xCoord;
      int yCoord;
      int shapeSize;
      Color a_color;
      ShapeManager::ShapeType shapeType;

  public:
      Shape(int x, int y, int size, Color color) {
          xCoord = x;
          yCoord = x;
          shapeSize = size;
          a_color = color;
      }
      virtual ~Shape() = default;
      int x() const;
      int y() const;
      int size() const;
      Color color() const;


      void move(int x, int y);
      void resize(int size);
      std::shared_ptr <Shape> clone() const;

      //Defines type
      void setShapeType(ShapeManager::ShapeTypes type){
          this->shapeType = type;
      }

      bool contains(int x, int y) const;
      void draw(easywin::Canvas& canvas) const;

      bool operator == (const Shape& other) const {
          return equalTo(other);
      }
      bool operator !=(const Shape&) const{
          return !equalTo(other);
      }
      using ShapePtr = Shape *;
  }

}