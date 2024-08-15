#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>

int main() {
    auto json = nlohmann::json{};
    const auto value = 42;
    json["node1"]["value"] = value;
    const auto values = std::vector<int>{1,3,5,6,9};
    json["node1"]["values"] = {1,3,5,6,9};
    std::ofstream("test.json") << json.dump();
    const auto json1 = nlohmann::json::parse(std::ifstream("test.json"));
    std::system("rm test.json");
    if (json1["node1"]["value"] != 42) {
        return -1;
    }
    if (json1["node1"]["values"].size() != values.size()) {
        return -1;
    }
    auto iValue = 0;
    for (const auto valueFromList : values) {
        if (json1["node1"]["values"].at(iValue++) != valueFromList) {
            return -1;
        }
    }
    return 0;
}