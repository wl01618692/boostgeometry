//
// Created by zhangjiayuan on 23-5-5.
//

#include "backTrack.h"

std::vector<std::vector<int>> result; // 存放符合条件结果的集合
std::vector<int> path; // 用来存放符合条件结果

// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
// 示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
void permutation_brute_force(int n, int k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++  j) {
            std::cout << i << " " << j << std::endl;
        }
    }
}

void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i <= n; ++i) {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}

void backtracking_optimized(int n, int k, int startIndex) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }

    // path
    // k - path
    // k - path <= n - i
    // i <= n - k + path.size()
    // 4 3 0, n - k + path = 1, i = 1
    for (int i = startIndex; i <= n - k + path.size() + 1; ++i) {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}

void permutation(int n, int k) {
    backtracking(4, 2, 1);
    for (auto elem: result) {
        for (auto c: elem) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

const std::string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
};

std::vector<std::string> result_str;
std::string s;

std::vector<std::string> phoneNumber(int num) {
//    phoneNumberBackTrack( , 1);
    return result_str;
}

void phoneNumberBackTrack(std::string s, int index) {

}

// void backtracking(参数) {
//    if (终止条件) {
//        存放结果;
//        return;
//    }
//
//    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//        处理节点;
//        backtracking(路径，选择列表); // 递归
//        回溯，撤销处理结果
//    }
//}
