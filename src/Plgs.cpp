#include "Pslg.hpp"
#include <exception>
#include <iostream>

namespace triangulator {

Pslg::Pslg(const nlohmann::json &json) {
  _instanceUid = json["instance_uid"];
  const auto numPoints = json["num_points"].get<size_t>();
  if (json["points_x"].size() != numPoints ||
      json["points_y"].size() != numPoints) {
    throw std::logic_error("invalid json");
  }
  for (auto iPoint = 0U; iPoint < numPoints; ++iPoint) {
    _points.emplace_back(json["points_x"].at(iPoint),
                         json["points_y"].at(iPoint));
  }
  for (auto iBoundaryPoint = 0U;
       iBoundaryPoint < json["region_boundary"].size(); ++iBoundaryPoint) {
    _boundary.emplace_back(json["region_boundary"].at(iBoundaryPoint));
  }
  const auto numEdges = json["num_constraints"].get<size_t>();
  if (json["additional_constraints"].size() != numEdges) {
    throw std::logic_error("invalid json");
  }
  for (auto iEdge = 0U; iEdge < numEdges; ++iEdge) {
    _edges.emplace_back(json["additional_constraints"].at(iEdge)[0],
                        json["additional_constraints"].at(iEdge)[1]);
  }
}

nlohmann::json Pslg::toJson() const {
  auto json = nlohmann::json{};
  json["instance_uid"] = _instanceUid;
  json["num_points"] = _points.size();
  for (auto iPoint = 0U; iPoint < _points.size(); ++iPoint) {
    const auto &point = _points.at(iPoint);
    json["points_x"][iPoint] = point.x();
    json["points_y"][iPoint] = point.y();
  }
  for (auto iBoundaryPoint = 0U; iBoundaryPoint < _boundary.size();
       ++iBoundaryPoint) {
    json["region_boundary"][iBoundaryPoint] = _boundary.at(iBoundaryPoint);
  }
  json["num_constraints"] = _edges.size();
  json["additional_constraints"] = nlohmann::json::array();
  for (auto iEdge = 0U; iEdge < _edges.size(); ++iEdge) {
    const auto &edge = _edges.at(iEdge);
    json["additional_constraints"].at(iEdge) = {edge.first, edge.second};
  }
  return json;
}

bool Pslg::operator==(const Pslg &other) const {
  return _instanceUid == other._instanceUid && _points == other._points &&
         _boundary == other._boundary && _edges == other._edges;
}

} // namespace triangulator