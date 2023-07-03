//
// Created by zhangjiayuan on 23-5-15.
//

#include "hashTable.h"
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

/// lc 242
//
//  给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//  示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
//
//  示例 2: 输入: s = "rat", t = "car" 输出: false
//
//  说明: 你可以假设字符串只包含小写字母。

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    if (s.empty() && t.empty()) return true;
    std::unordered_map<char, int> m;
    for (auto c: s) {
        m[c]++;
    }

    for (auto c: t) {
        m[c]--;
    }

    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        if (itr->second != 0) {
            return false;
        }
    }
    return true;
}


/// lc 349
//  题意：给定两个数组，编写一个函数来计算它们的交集。
//
//  349. 两个数组的交集
//
//  说明： 输出结果中的每个元素一定是唯一的。 我们可以不考虑输出结果的顺序。

// set insert duplicate => error
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> output; // 存放结果，之所以用set是为了给结果集去重
    std::unordered_set<int> m(nums1.begin(), nums1.end());
    for (auto& elem: nums2) {
        if (m.find(elem) != m.end()) {
            output.insert(elem);
        }
    }
    return std::vector<int> (output.begin(), output.end());
}

//
//在C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：
//集合 	底层实现 	是否有序 	数值是否可以重复 	能否更改数值 	查询效率 	增删效率
//std::set 	红黑树 	有序 	否 	否 	O(log n) 	O(log n)
//std::multiset 	红黑树 	有序 	是 	否 	O(logn) 	O(logn)
//std::unordered_set 	哈希表 	无序 	否 	否 	O(1) 	O(1)
//
//std::unordered_set底层实现为哈希表，std::set 和std::multiset 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以只能删除和增加。
//映射 	底层实现 	是否有序 	数值是否可以重复 	能否更改数值 	查询效率 	增删效率
//std::map 	红黑树 	key有序 	key不可重复 	key不可修改 	O(logn) 	O(logn)
//std::multimap 	红黑树 	key有序 	key可重复 	key不可修改 	O(log n) 	O(log n)
//std::unordered_map 	哈希表 	key无序 	key不可重复 	key不可修改 	O(1) 	O(1)
//



/// lc 202
//   「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
//
//   如果 n 是快乐数就返回 True ；不是，则返回 False 。
//
//   示例：
//
//   输入：19
//   输出：true
//   解释：
//   1^2 + 9^2 = 82
//   8^2 + 2^2 = 68
//   6^2 + 8^2 = 100
//   1^2 + 0^2 + 0^2 = 1
//   #
int calFunc(int num) {
    int output = 0;
    while (num != 0) {
        output += std::pow((num % 10), 2);
        num /= 10;
    }
    return output;
}

bool isHappy(int num) {
    if (num == 0) return false;
    std::unordered_set<int> s;
    s.insert(num);
    int res = num;
    while (res != 1) {
        res = calFunc(res);
        if (s.find(res) != s.end()) return false;
        s.insert(res);
    }
    return true;
}

//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
//
//注意：
//
//你可以假设两个字符串均只含有小写字母。
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true

bool lc383(std::string str1, std::string str2) {
    std::unordered_map<char, int> m;
    for (auto c: str2) {
        m[c]++;
    }

    for (auto c: str1) {
        m[c]--;
        if (m[c] < 0) {
            return false;
        }
    }
    return true;
}

bool lc383_optimized(std::string str1, std::string str2) {
    int record[26] = {0};
    for (auto c: str2) {
        record[c - 'a']++;
    }

    for (auto c: str1) {
        record[c - 'a']--;
        if (record[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}




/// lc15
//
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//
//给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// [-4, -1, -1, 0, 1, 2]，
//满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    // 找出a + b + c = 0
    // a = nums[i], b = nums[j], c = -(a + b)
    for (int i = 0; i < nums.size(); i++) {
        // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
            continue;
        }
        std::unordered_set<int> set;
        for (int j = i + 1; j < nums.size(); j++) {
            if (j > i + 2
                && nums[j] == nums[j-1]
                && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                continue;
            }
            int c = 0 - (nums[i] + nums[j]);
            if (set.find(c) != set.end()) {
                result.push_back({nums[i], nums[j], c});
                set.erase(c);// 三元组元素c去重
            } else {
                set.insert(nums[j]);
            }
        }
    }
    return result;
}










