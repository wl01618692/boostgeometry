cmake_minimum_required(VERSION 3.23)
project(boostgeometry)

set(CMAKE_CXX_STANDARD 14)

add_executable(boostgeometry main.cpp test.cpp test.h boost_geometry.cpp boost_geometry.h complexNumber.cpp complexNumber.h testJson.cpp testJson.h algo.cpp algo.h Trie.cpp Trie.h linkedlist.cpp linkedlist.h Util.h dynamic_programming.cpp dynamic_programming.h double_ptr.cpp double_ptr.h array.cpp array.h backTrack.cpp backTrack.h greedy.cpp greedy.h stack_queue.cpp stack_queue.h hashTable.cpp hashTable.h unionfind.h binaryTree.cpp binaryTree.h geometry.cpp geometry.h Sort.cpp mystring.cpp mystring.h lc150mustdo.cpp lc150mustdo.h armailloTest.cpp armailloTest.h topologicalSort.cpp topologicalSort.h bitwiseOpr.cpp bitwiseOpr.h CORDIC.h FIRfilter.h graph.h buyAndSellStock.h houseRobber.h twoSum.h)
include_directories(/home/zhangjiayuan/桌面/boostgeometry/boost_1_81_0)
include_directories(/home/zhangjiayuan/桌面/json-3.11.2/include)
include_directories(/home/zhangjiayuan/桌面/armadillo-12.4.1/include)

