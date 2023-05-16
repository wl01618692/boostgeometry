//
// Created by zhangjiayuan on 23-4-14.
//

#include "testJson.h"
void to_json(json& j, const ns::person& p) {
    j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
}

void from_json(const json& j, ns::person& p) {
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("age").get_to(p.age);
}

void json_test() {
    // from json from a file
    std::ifstream f("/home/zhangjiayuan/CLionProjects/boostgeometry/test.json");
    json data = json::parse(f);
    json ex1 = json::parse(R"(
  {
    "pi": 3.141,
    "happy": true
  }
)");

    json ex3 = {
            {"happy", true},
            {"pi",    3.141},
    };

// {
//  "pi": 3.141,
//  "happy": true,
//  "name": "Niels",
//  "nothing": null,
//  "answer": {
//    "everything": 42
//  },
//  "list": [1, 0, 2],
//  "object": {
//    "currency": "USD",
//    "value": 42.99
//  }
// }

// create an empty structure (null)
    json j;

// add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

// add a Boolean that is stored as bool
    j["happy"] = true;

// add a string that is stored as std::string
    j["name"] = "Niels";

// add another null object by passing nullptr
    j["nothing"] = nullptr;

// add an object inside the object
    j["answer"]["everything"] = 42;

// add an array that is stored as std::vector (using an initializer list)
    j["list"] = { 1, 0, 2 };

// add another object (using an initializer list of pairs)
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

// instead, you could also write (which looks very similar to the JSON above)
    json j2 = {
            {"pi", 3.141},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {
                           {"everything", 42}
                   }},
            {"list", {1, 0, 2}},
            {"object", {
                           {"currency", "USD"},
                         {"value", 42.99}
                   }}
    };


    ns::person p("person1", "add1", 12);
}