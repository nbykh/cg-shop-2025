#include "src/Pslg.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>
#include <string>

using namespace triangulator;

TEST_CASE("Test class Pslg") {
  // TODO(Nikolai): find out how to access project root directory
  const auto json = std::string(
      "{\"instance_uid\":\"cgshop2025_examples_ortho_10_ff68423e\",\"num_"
      "points\":10,\"points_x\":[0,383537,383537,667036,667036,1000000,1000000,"
      "1000000,1000000,0],\"points_y\":[0,0,-232707,-232707,0,0,422972,834548,"
      "1000000,1000000],\"region_boundary\":[0,1,2,3,4,5,6,7,8,9],\"num_"
      "constraints\":0,\"additional_constraints\":[]}");
  const auto pslgJson = nlohmann::json::parse(json);
  const auto pslg = Pslg(pslgJson);
  const auto pslgJson1 = pslg.toJson();
  CHECK(pslgJson == pslgJson1);
  const auto pslg1 = Pslg(pslgJson1);
  CHECK(pslg == pslg1);
}