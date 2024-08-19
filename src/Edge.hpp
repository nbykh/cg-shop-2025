#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "Point.hpp"
#include <set>

namespace triangulator {
class Edge {
public:
  Edge() = default;

  Edge(const Point &pointA, const Point &pointB);

  [[nodiscard]] double getLength() const { return _length; }

  [[nodiscard]] bool isCongruent(const Edge &other) const;

  [[nodiscard]] bool operator==(const Edge &other) const;

  [[nodiscard]] bool operator<(const Edge &other) const;

private:
  static constexpr size_t numPoints = 2;

  std::set<Point> _points{};
  double _length{0.0};

  [[nodiscard]] const Point &getPoint(size_t iPoint) const;
};
} // namespace triangulator

#endif // _EDGE_HPP_