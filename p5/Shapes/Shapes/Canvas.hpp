#pragma once
#include <string>
#include <vector>

namespace easywin {

  using Color = unsigned long;

  constexpr Color rgb(int red, int green, int blue) {
    return (red & 0xFF) | ((green & 0xFF) << 8) | ((blue & 0xFF) << 16);
  }

  struct Point {
    long x, y;
  };

  class Canvas {
  public:
    virtual ~Canvas() { }

    virtual void drawRectangle(
      int left,
      int top,
      int right,
      int bottom,
      Color lineColor,
      Color fillColor
    ) = 0;

    virtual void drawEllipse(
      Point center,
      unsigned int radius,
      Color lineColor,
      Color fillColor
    ) = 0;

    virtual void drawPolygon(
      const std::vector<Point>& points,
      Color lineColor,
      Color fillColor
    ) = 0;

    virtual void drawText(
      Point topLeft,
      const std::string& text,
      Color textColor,
      Color fillColor
    ) = 0;
  };

}  // namespace easywin
