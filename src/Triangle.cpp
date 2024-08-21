#include "Triangle.hpp"
#include "Utils.hpp"
#include <stdexcept>
#include <cmath>

namespace triangulator {
Triangle::Triangle(const std::set<Point> &corners) {
  if (corners.size() != _numEdges) {
    throw std::logic_error(
        "invalid number of corners or some corners are the same");
  }
  for (size_t iEdge = 0; iEdge < _numEdges; ++iEdge) {
    _edges.insert({*std::next(corners.cbegin(), (iEdge + 1) % _numEdges),
                   *std::next(corners.cbegin(), (iEdge + 2) % _numEdges)});
  }
  if (_edges.size() != _numEdges) {
    throw std::logic_error(
        "invalid number of edges or some corners are the same");
  }
}

bool Triangle::nonObtuse() const {
  return isGreaterOrEqual(std::pow(getEdge(0).getLength(), 2) +
                              std::pow(getEdge(1).getLength(), 2),
                          std::pow(getEdge(2).getLength(), 2));
}

bool Triangle::isCongruent(const Triangle &other) const {
  for (size_t iEdge = 0; iEdge < _numEdges; ++iEdge) {
    if (!isEqual(getEdge(iEdge).getLength(),
                 other.getEdge(iEdge).getLength())) {
      return false;
    }
  }
  return true;
}

bool Triangle::operator==(const Triangle &other) const {
  for (size_t iEdge = 0; iEdge < _numEdges; ++iEdge) {
    if (!(getEdge(iEdge) == other.getEdge(iEdge))) {
      return false;
    }
  }
  return true;
}

const Edge &Triangle::getEdge(const size_t iEdge) const {
  return *std::next(_edges.cbegin(), iEdge % _numEdges);
}

} // namespace triangulator
