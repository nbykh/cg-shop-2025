#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "Edge.hpp"
#include "Point.hpp"
#include <set>

namespace triangulator {
class Triangle {
public:
  explicit Triangle(const std::set<Point> &corners);

  [[nodiscard]] bool nonObtuse() const;
  [[nodiscard]] bool isCongruent(const Triangle &other) const;
  [[nodiscard]] bool operator==(const Triangle &other) const;

private:
  static constexpr int _numEdges = 3;

  std::set<Edge> _edges{};

  [[nodiscard]] const Edge &getEdge(size_t iEdge) const;
};
} // namespace triangulator

#endif // _TRIANGLE_HPP_