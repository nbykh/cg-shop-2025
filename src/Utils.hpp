#ifndef _UTILS_HPP_
#define _UTILS_HPP_

namespace triangulator {

constexpr static double accuracy = 1e-10;

[[nodiscard]] bool isEqual(double a, double b);
[[nodiscard]] bool isLess(double a, double b);
[[nodiscard]] bool isGreater(double a, double b);
[[nodiscard]] bool isLessOrEqual(double a, double b);
[[nodiscard]] bool isGreaterOrEqual(double a, double b);

} // namespace triangulator

#endif // _UTILS_HPP_