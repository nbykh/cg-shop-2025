#include "src/Point.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace triangulator;

TEST_CASE("Test class Point.") {
  const auto point = Point(0.0, 0.0);
  CHECK(point.x() == Catch::Approx(0.0).margin(1e-16));
  CHECK(point.y() == Catch::Approx(0.0).margin(1e-16));

  const auto anotherPoint = Point(3.0, 4.0);
  CHECK(Point::distance(point, anotherPoint) ==
        Catch::Approx(5.0).epsilon(1e-10));

  const auto almostZeroPoint = Point(0.9e-10, 0.9e-10);
  CHECK(almostZeroPoint == point);
  CHECK(!(almostZeroPoint < point));
  CHECK(!(point < almostZeroPoint));

  CHECK(Point{-1.0, 1.0} < Point{-1 - 0.9e-10, 1.5});
}