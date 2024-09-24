#include "Edge.hpp"
#include "Utils.hpp"

namespace triangulator {

Edge::Edge(const Point &pointA, const Point &pointB)
    : _points{pointA, pointB}, _length{Point::distance(pointA, pointB)} {}

bool Edge::isCongruent(const Edge &other) const {
  return isEqual(_length, other._length);
}

bool Edge::operator==(const Edge &other) const {
  return (getPoint(0) == other.getPoint(0)) &&
         (getPoint(1) == other.getPoint(1));
}

bool Edge::operator<(const Edge &other) const {
  if (!isEqual(_length, other._length)) {
    return isLess(_length, other._length);
  }
  if (!(getPoint(0) == other.getPoint(0))) {
    return getPoint(0) < other.getPoint(0);
  }
  return getPoint(1) == other.getPoint(1);
}

const Point &Edge::getPoint(const size_t iPoint) const {
  return *std::next(_points.cbegin(), iPoint % _numPoints);
}

} // namespace triangulator
