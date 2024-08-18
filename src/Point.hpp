#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <cstddef>
#include <functional>
#include <vector>

namespace triangulator {
class Point {
public:
  static constexpr double accuracy = 1e-10;

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

template <> struct std::hash<triangulator::Point> {
  std::size_t operator()(const triangulator::Point &point) {
    return 31 * (31 * std::hash<double>{}(point.x()) + 17) +
           std::hash<double>{}(point.y());
  }
};

#endif // _POINT_HPP_