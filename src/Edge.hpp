#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "Point.hpp"

namespace triangulator {
class Edge {
public:
  Edge() = default;

  Edge(const Point &pointA, const Point &pointB);

  [[nodiscard]] double getLength() const { return _length; }

  [[nodiscard]] bool isCongruent(const Edge &other) const;

  [[nodiscard]] bool isOpposite(const Edge &other) const;

  [[nodiscard]] bool operator==(const Edge &other) const;

  [[nodiscard]] bool operator<(const Edge &other) const;

  [[nodiscard]] Edge operator!() const;

private:
  Point _pointA{};
  Point _pointB{};
  double _length{0.0};
};
} // namespace triangulator

#endif // _EDGE_HPP_