#include "src/Pslg.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fstream>
#include <initializer_list>
#include <nlohmann/json.hpp>
#include <string>

using namespace triangulator;

TEST_CASE("Test class Pslg") {
  const auto path2instances = std::string("data/example_instances_rev1/");
  for (const auto &jsonName :
       {"cgshop2025_examples_ortho_10_ff68423e.instance.json",
        "cgshop2025_examples_point-set_80_3d8b193e.instance.json",
        "cgshop2025_examples_simple-polygon-exterior_60_82e60438.instance.json",
        "cgshop2025_examples_simple-polygon-exterior-20_100_a61e9aed.instance."
        "json"}) {
    const auto pslgJson =
        nlohmann::json::parse(std::ifstream(path2instances + jsonName));
    const auto pslg = Pslg(pslgJson);
    const auto pslgJson1 = pslg.toJson();
    CHECK(pslgJson == pslgJson1);
    const auto pslg1 = Pslg(pslgJson1);
    CHECK(pslg == pslg1);
  }
}