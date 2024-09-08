#ifndef _PSLG_HPP_
#define _PSLG_HPP_

#include "Edge.hpp"
#include "Point.hpp"
#include <nlohmann/json.hpp>
#include <string>

namespace triangulator {

class Pslg {
public:
  explicit Pslg(const nlohmann::json &json);

  [[nodiscard]] nlohmann::json toJson() const;

  [[nodiscard]] const std::string &getInstanceUid() const;

  [[nodiscard]] const std::vector<Point> &getPoints() const { return _points; }

  [[nodiscard]] const std::vector<size_t> &getBoundary() const;

  [[nodiscard]] const std::vector<std::pair<size_t, size_t>> &getEdges() const;

private:
  std::string _instanceUid{};
  std::vector<Point> _points{};
  std::vector<size_t> _boundary{};
  std::vector<std::pair<size_t, size_t>> _edges{};
};

} // namespace triangulator

#endif // _PSLG_HPP_