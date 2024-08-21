#include "Point.hpp"
#include "Utils.hpp"
#include <cmath>

namespace triangulator {
double Point::distance(const Point &pointA, const Point &pointB) {
  return (pointA == pointB) ? 0.0
                            : std::sqrt(std::pow(pointA._x - pointB._x, 2) +
                                        std::pow(pointA._y - pointB._y, 2));
}

bool Point::operator<(const Point &otherPoint) const {
  if (!isEqual(_x, otherPoint._x)) {
    return isLess(_x, otherPoint._x);
  }
  return isLess(_y, otherPoint._y);
}

bool Point::operator==(const Point &otherPoint) const {
  return isEqual(_x, otherPoint._x) && isEqual(_y, otherPoint._y);
}
} // namespace triangulator