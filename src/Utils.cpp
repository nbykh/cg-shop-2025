#include "Utils.hpp"

namespace triangulator {

bool isEqual(const double a, const double b) {
  return !isLess(a, b) && !isLess(b, a);
}

bool isLess(const double a, const double b) { return a < b - accuracy; }

bool isGreater(double a, double b) { return isLess(b, a); }

bool isLessOrEqual(const double a, const double b) { return !isGreater(a, b); }

bool isGreaterOrEqual(double a, double b) { return !isLess(a, b); }

} // namespace triangulator
