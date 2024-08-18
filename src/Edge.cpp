#include "Edge.hpp"
#include "Utils.hpp"

namespace triangulator {

Edge::Edge(const Point &pointA, const Point &pointB)
    : _pointA{pointA}, _pointB{pointB},
      _length{Point::distance(pointA, pointB)} {}

bool Edge::isCongruent(const Edge &other) const {
  return isEqual(_length, other._length);
}

bool Edge::isOpposite(const Edge &other) const {
  return (_pointA == other._pointB) && (_pointB == other._pointA);
}

bool Edge::operator==(const Edge &other) const {
  return (_pointA == other._pointA) && (_pointB == other._pointB);
}

bool Edge::operator<(const Edge &other) const {
  if (!isEqual(_length, other._length)) {
    return isLess(_length, other._length);
  }
  if (!(_pointA == other._pointA)) {
    return _pointA < other._pointA;
  }
  return _pointB < other._pointB;
}

Edge Edge::operator!() const { return {_pointB, _pointA}; }

} // namespace triangulator
