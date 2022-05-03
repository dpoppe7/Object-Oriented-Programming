#include "TestCanvas.hpp"
#include <algorithm>

namespace easywin {

  void TestCanvas::drawRectangle(int left, int top, int right, int bottom, Color lineColor, Color fillColor) {
    push_back(DrawRectangle{ left, top, right, bottom, lineColor, fillColor });
  }

  void TestCanvas::drawEllipse(Point center, unsigned int radius, Color lineColor, Color fillColor) {
    push_back(DrawEllipse{ center, radius, lineColor, fillColor });
  }

  void TestCanvas::drawPolygon(const std::vector<Point>& points, Color lineColor, Color fillColor) {
    push_back(DrawPolygon{ points, lineColor, fillColor });
  }

  void TestCanvas::drawText(Point topLeft, const std::string& text, Color textColor, Color fillColor) {
    push_back(DrawText{ topLeft, text, textColor, fillColor });
  }

  bool operator==(const DrawPolygon& a, const DrawPolygon& b) noexcept {
    if (a.points.size() != b.points.size()) return false;
    std::vector<Point> aa;
    aa.reserve(a.points.size() * 2);
    std::copy(a.points.begin(), a.points.end(), std::back_inserter(aa));
    std::copy(a.points.begin(), a.points.end(), std::back_inserter(aa));
    auto itr = std::search(aa.begin(), aa.end(), b.points.begin(), b.points.end());
    if (itr != aa.end()) {
      return true;
    }
    itr = std::search(aa.begin(), aa.end(), b.points.rbegin(), b.points.rend());
    if (itr != aa.end()) {
      return true;
    }
    return false;
  }

  std::ostream& operator<<(std::ostream& out, const DrawRectangle& r) {
    return out << std::dec << std::setfill('0') << std::right
      << "drawRectangle(" << r.left << ", " << r.top << ", " << r.right << ", " << r.bottom << ", 0x"
      << std::hex << std::setw(6) << r.lineColor << ", 0x" << std::setw(6) << r.fillColor << ")" << std::dec;
  }

  std::ostream& operator<<(std::ostream& out, const DrawEllipse& e) {
    return out << std::dec << std::setfill('0') << std::right
      << "drawEllipse({ " << e.center.x << ", " << e.center.y << " }, " << e.radius << ", 0x"
      << std::hex << std::setw(6) << e.lineColor << ", 0x" << std::setw(6) << e.fillColor << ")";
  }

  std::ostream& operator<<(std::ostream& out, const DrawPolygon& p) {
    out << std::dec << std::setfill('0') << std::right
      << "drawPolygon({ ";
    bool first = true;
    for (auto& point : p.points) {
      if (first) first = false;
      else out << ", ";
      out << "{ " << point.x << ", " << point.y << " }";
    }
    return out << " }, 0x" << std::hex << std::setw(6) << p.lineColor << ", 0x" << std::setw(6) << p.fillColor << ")";
  }

  std::ostream& operator<<(std::ostream& out, const DrawText& t) {
    return out << "drawText";
  }

}