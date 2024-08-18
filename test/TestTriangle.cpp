#include "src/Point.hpp"
#include "src/Triangle.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <exception>

using namespace triangulator;

TEST_CASE("Test class Triangle.") {
  CHECK_THROWS_AS(Triangle{std::set<Point>{}}, std::logic_error);
  CHECK_THROWS_AS(Triangle({{}, {}, {}}), std::logic_error);

  CHECK(Triangle{{{0.0, 0.0}, {0.0, 3.0}, {4.0, 0.0}}}.nonObtuse());
  CHECK(!Triangle{{{0.0, 0.0}, {0.0, 3.0}, {4.0, -0.1}}}.nonObtuse());

  CHECK(Triangle{{{0.0, 0.0}, {0.0, 3.0}, {4.0, 0.0}}}.isCongruent(
      Triangle{{{1.0, 0.5}, {1.0, 3.5}, {5.0, 0.5}}}));
}