#include "src/Edge.hpp"
#include "src/Point.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace triangulator;

TEST_CASE("Test class Edge.") {
  const auto zeroEdge = Edge({}, {});
  CHECK(zeroEdge.getLength() == Catch::Approx(0.0).margin(1e-10));
  CHECK(zeroEdge == !zeroEdge);
  CHECK(zeroEdge.isCongruent({{1.0, 0.0}, {1.0, 0.0}}));
  CHECK(zeroEdge.isOpposite(zeroEdge));

  const auto edge = Edge({1.0, 2.0}, {4.0, 6.0});
  CHECK(edge.getLength() == Catch::Approx(5.0).margin(1e-10));
  CHECK(!(edge == !edge));
  CHECK(edge.isOpposite(!edge));
  CHECK(edge.isCongruent({{0.0, 4.0}, {3.0, 0.0}}));

  CHECK(Edge{{0.0, 4.0}, {3.0, 0.0}} < Edge{{0.0, 4.0}, {3.0, -0.1}});
}