#include "Pslg.hpp"
#include <exception>
#include <iostream>

namespace triangulator {

Pslg::Pslg(const nlohmann::json &json) {
  // check consistency
  const auto numPoints = json["num_points"].get<size_t>();
  const auto numEdges = json["num_constraints"].get<size_t>();
  if (json["points_x"].size() != numPoints ||
      json["points_y"].size() != numPoints ||
      json["additional_constraints"].size() != numEdges) {
    throw std::logic_error("invalid json");
  }
  // initialise
  _instanceUid = json["instance_uid"];
  for (size_t iPoint = 0; iPoint < numPoints; ++iPoint) {
    _points.emplace_back(json["points_x"].at(iPoint),
                         json["points_y"].at(iPoint));
  }
  for (auto iBoundaryPoint = 0U;
       iBoundaryPoint < json["region_boundary"].size(); ++iBoundaryPoint) {
    _boundary.emplace_back(json["region_boundary"].at(iBoundaryPoint));
  }
  for (size_t iEdge = 0; iEdge < numEdges; ++iEdge) {
    _edges.emplace_back(json["additional_constraints"].at(iEdge)[0],
                        json["additional_constraints"].at(iEdge)[1]);
  }
}

nlohmann::json Pslg::toJson() const {
  auto json = nlohmann::json{};
  json["instance_uid"] = _instanceUid;
  json["num_points"] = _points.size();
  for (size_t iPoint = 0; iPoint < _points.size(); ++iPoint) {
    const auto &point = _points.at(iPoint);
    json["points_x"][iPoint] = point.x();
    json["points_y"][iPoint] = point.y();
  }
  for (size_t iBoundaryPoint = 0; iBoundaryPoint < _boundary.size();
       ++iBoundaryPoint) {
    json["region_boundary"][iBoundaryPoint] = _boundary.at(iBoundaryPoint);
  }
  json["num_constraints"] = _edges.size();
  json["additional_constraints"] = nlohmann::json::array();
  for (size_t iEdge = 0; iEdge < _edges.size(); ++iEdge) {
    const auto &edge = _edges.at(iEdge);
    json["additional_constraints"][iEdge] = {edge.first, edge.second};
  }
  return json;
}

const std::string &Pslg::getInstanceUid() const { return _instanceUid; }

const std::vector<size_t> &Pslg::getBoundary() const { return _boundary; }

const std::vector<std::pair<size_t, size_t>> &Pslg::getEdges() const {
  return _edges;
}

} // namespace triangulator