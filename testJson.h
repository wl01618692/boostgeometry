//
// Created by zhangjiayuan on 23-4-14.
//

#ifndef BOOSTGEOMETRY_TESTJSON_H
#define BOOSTGEOMETRY_TESTJSON_H
#include <nlohmann/json.hpp>
#include "Util.h"

using json = nlohmann::json;
void json_test();
namespace ns {
    // a simple struct to model a person
    struct person {
        person(std::string string, std::string string1, int i) {
            name = string;
            address = string1;
            age = i;
        }

        std::string name;
        std::string address;
        int age;
    };
}


#endif //BOOSTGEOMETRY_TESTJSON_H
