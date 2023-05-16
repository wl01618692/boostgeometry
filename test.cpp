//
// Created by zhangjiayuan on 23-4-14.
//

#include "test.h"
#include <iostream>

template <typename T>
void show(T t) {
    std::cout << t << std::endl;
}

void demo() {
    show(5);
}
