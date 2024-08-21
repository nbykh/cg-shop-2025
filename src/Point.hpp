#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <vector>

namespace triangulator {
class Point {
public:
  Point() = default;
  Point(const double x, const double y) : _x{x}, _y{y} {}

  [[nodiscard]] double x() const { return _x; }
  [[nodiscard]] double y() const { return _y; }
  [[nodiscard]] bool operator<(const Point &otherPoint) const;
  [[nodiscard]] bool operator==(const Point &otherPoint) const;

  [[nodiscard]] static double distance(const Point &pointA,
                                       const Point &pointB);

private:
  double _x{0.0};
  double _y{0.0};
};
} // namespace triangulator

#endif // _POINT_HPP_