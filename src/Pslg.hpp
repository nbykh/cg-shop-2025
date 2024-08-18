#ifndef _PSLG_HPP_
#define _PSLG_HPP_

#include "Edge.hpp"
#include "Point.hpp"
#include <nlohmann/json.hpp>
#include <string>

namespace triangulator {

class Pslg {
public:
  Pslg(const nlohmann::json &json);

  [[nodiscard]] nlohmann::json toJson() const;

  [[nodiscard]] bool operator==(const Pslg &other) const;

private:
  std::string _instanceUid{};
  std::vector<Point> _points{};
  std::vector<size_t> _boundary{};
  std::vector<std::pair<size_t, size_t>> _edges{};
};

} // namespace triangulator

#endif // _PSLG_HPP_