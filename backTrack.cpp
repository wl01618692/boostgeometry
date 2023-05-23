//
// Created by zhangjiayuan on 23-5-5.
//

#include "backTrack.h"

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

class permutationSolution {

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
            backtracking_optimized(n, k, i + 1);
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
};


/// 216
// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
//说明：
//
//    所有数字都是正整数。
//    解集不能包含重复的组合。
//
//示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]
//
//示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]
//
//
class Solution216 {

    std::vector<std::vector<int>> result; // 存放符合条件结果的集合
    std::vector<int> path; // 用来存放符合条件结果

    void backTrack216(int n, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i) {
            if (sum > n) {
                return;
            }
            sum += i;
            path.push_back(i);
            backTrack216(n, k, sum, startIndex + 1);
            path.pop_back();
        }
    }

    std::vector<std::vector<int>> lc216(int k, int n) {
        backTrack216(k, n, 0, 1);
        return result;
    }
};

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
