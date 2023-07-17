//
// Created by zhangjiayuan on 23-4-25.
//
#include <iostream>
#include "Trie.h"

void Trie_Test() {
    Trie t;
    t.insert("dog");
    t.insert("dar");
    std::cout << t.find("ca") << std::endl;
    std::cout << t.find("do") << std::endl;
    std::cout << t.find("dog") << std::endl;
}

