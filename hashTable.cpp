//
// Created by zhangjiayuan on 23-5-15.
//

#include "hashTable.h"
#include <map>
#include <unordered_map>
#include <unordered_set>

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
