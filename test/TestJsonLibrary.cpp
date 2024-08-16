#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Test nlohmann/json library.") {
    auto json = nlohmann::json{};
    const auto value = 42;
    json["node1"]["value"] = value;

    const auto values = std::vector<int>{1,3,5,6,9};
    json["node1"]["values"] = {1,3,5,6,9};

    std::ofstream("test.json") << json.dump();
    const auto json1 = nlohmann::json::parse(std::ifstream("test.json"));
    std::system("rm test.json");

    CHECK(json["node1"]["value"] == value);
    CHECK(json1["node1"]["value"] == value);
    CHECK(json["node1"]["values"].size() == values.size());
    CHECK(json1["node1"]["values"].size() == values.size());
    auto iValue = 0;
    for (const auto valueFromList : values) {
        CHECK(json["node1"]["values"].at(iValue) == valueFromList);
        CHECK(json1["node1"]["values"].at(iValue++) == valueFromList);
    }
}
