#pragma once
#include "../Shapes/Canvas.hpp"
#include <vector>
#include <string>
#include <variant>
#include <ostream>
#include <iomanip>

namespace easywin {

  inline
    bool operator ==(const Point& a, const Point& b) noexcept {
    return a.x == b.x && a.y == b.y;
  }

  struct DrawRectangle {
    int left, top, right, bottom;
    Color lineColor, fillColor;
  };

  struct DrawEllipse {
    Point center;
    unsigned int radius;
    Color lineColor, fillColor;
  };

  struct DrawPolygon {
    std::vector<Point> points;
    Color lineColor, fillColor;
  };

  struct DrawText {
    Point topLeft;
    std::string text;
    Color textColor, fillColor;
  };

  using DrawRecord = std::variant<DrawRectangle, DrawEllipse, DrawPolygon, DrawText>;

  inline bool operator ==(const DrawRectangle& a, const DrawRectangle& b) noexcept {
    return a.left == b.left && a.top == b.top && a.right == b.right &&
      a.bottom == b.bottom && a.lineColor == b.lineColor && a.fillColor == b.fillColor;
  }

  inline bool operator ==(const DrawEllipse& a, const DrawEllipse& b) noexcept {
    return a.center == b.center && a.radius == b.radius &&
      a.lineColor == b.lineColor && a.fillColor == b.fillColor;
  }

  inline bool operator ==(const DrawPolygon& a, const DrawPolygon& b) noexcept;

  inline bool operator ==(const DrawText& a, const DrawText& b) noexcept {
    return a.topLeft == b.topLeft && a.text == b.text &&
      a.textColor == b.textColor && a.fillColor == b.fillColor;
  }

  template <typename T>
  inline bool operator ==(const DrawRecord& a, const T& b) noexcept {
    return std::holds_alternative<T>(a) && std::get<T>(a) == b;
  }

  std::ostream& operator <<(std::ostream& out, const DrawRectangle& r);
  std::ostream& operator <<(std::ostream& out, const DrawEllipse& e);
  std::ostream& operator <<(std::ostream& out, const DrawPolygon& p);
  std::ostream& operator <<(std::ostream& out, const DrawText& t);
  inline
    std::ostream& operator <<(std::ostream& out, const DrawRecord& rec) {
    return std::visit([&out](auto& v) -> auto& { return out << v; }, rec);
  }

  class TestCanvas : private std::vector<DrawRecord>, public Canvas {

  public:
    auto& operator[](size_t i) const noexcept {
      return this->std::vector<DrawRecord>::operator[](i);
    }
    auto begin() const noexcept {
      return this->std::vector<DrawRecord>::begin();
    }
    auto end() const noexcept {
      return this->std::vector<DrawRecord>::end();
    }
    auto size() const noexcept {
      return this->std::vector<DrawRecord>::size();
    }

    void drawRectangle(
      int left,
      int top,
      int right,
      int bottom,
      Color lineColor,
      Color fillColor
    ) override;

    virtual void drawEllipse(
      Point center,
      unsigned int radius,
      Color lineColor,
      Color fillColor
    ) override;

    virtual void drawPolygon(
      const std::vector<Point>& points,
      Color lineColor,
      Color fillColor
    ) override;

    virtual void drawText(
      Point topLeft,
      const std::string& text,
      Color textColor,
      Color fillColor
    ) override;

  };

}