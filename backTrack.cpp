//
// Created by zhangjiayuan on 23-5-5.
//

#include "backTrack.h"
using namespace std;

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

/// lc 77
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
        // k - path <= n - i + 1
        // i <= n - k + path.size() + 1
        // 4 3 0, n - k + path = 1, i = 1
        // 举个例子，n = 4，k = 3， 目前已经选取的元素为0（path.size为0），n - (k - 0) + 1 即 4 - ( 3 - 0) + 1 = 2。
        //从2开始搜索都是合理的，可以是组合[2, 3, 4]。
        for (int i = startIndex; i <= n - k + path.size() + 1; ++i) {
            path.push_back(i);
            backtracking_optimized(n, k, i + 1);
            path.pop_back();
        }
    }

    // 1 2 3 4
    // 234 34 4
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

    void backTrack216(int size, int target, int sum, int startIndex) {
        if (path.size() == size) {
            if (sum == target) result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (size - path.size()) + 1; ++i) {
            if (sum > target) {
                return;
            }
            sum += i;
            path.push_back(i);
            backTrack216(size, target, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    std::vector<std::vector<int>> lc216(int k, int n) {
        backTrack216(k, n, 0, 1);
        return result;
    }
};


//vector<vector<int>> combinationSum3(int k, int n) {
//    result.clear(); // 可以不加
//    path.clear();   // 可以不加
//    backtracking(n, k, 0, 1);
//    return result;
//}

// 39. 组合总和
//
//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//
//说明：
//
//    所有数字（包括 target）都是正整数。
//    解集不能包含重复的组合。
//
//示例 1：
//
//    输入：candidates = [2,3,6,7], target = 7,
//    所求解集为： [ [7], [2,2,3] ]
//
//示例 2：
//
//    输入：candidates = [2,3,5], target = 8,
//    所求解集为： [ [2,2,2,2], [2,3,3], [3,5] ]
//
vector<vector<int>> output;
vector<int> path;
void backTracking39(std::vector<int> nums, int startIndex, int sum, int target) {
    if (sum > target) {
        return;
    }

    if (sum == target) {
        output.push_back(path);
        return;
    }

    for (int i = startIndex; i < nums.size() && sum + nums[i] <= target; ++i) {
        sum += nums[i];
        path.push_back(nums[i]);
        backTracking39(nums, i, sum, target);
        path.pop_back();
        sum -= nums[i];
    }
}

vector<vector<int>> entry39(std::vector<int> nums, int target) {
    output.clear();
    path.clear();
    backTracking39(nums, 0, 0, target);
    return output;
}

// 40.组合总和II
//
//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次。
//
//说明： 所有数字（包括目标数）都是正整数。解集不能包含重复的组合。
//
//    示例 1:
//    输入: candidates = [10,1,2,7,6,1,5], target = 8,
//    所求解集为:
// [
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

}

// 131
// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]
class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking (const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};




// 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
//
//示例 1：
//
//    输入：s = "25525511135"
//    输出：["255.255.11.135","255.255.111.35"]
//
//示例 2：
//
//    输入：s = "0000"
//    输出：["0.0.0.0"]
//
//示例 3：
//
//    输入：s = "1111"
//    输出：["1.1.1.1"]
//
//示例 4：
//
//    输入：s = "010010"
//    输出：["0.10.0.10","0.100.1.0"]
//
//示例 5：
//
//    输入：s = "101023"
//    输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//提示：
//
//    0 <= s.length <= 3000
//    s 仅由数字组成



