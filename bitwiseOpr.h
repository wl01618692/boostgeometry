//
// Created by zhangjiayuan on 23-7-11.
//

#ifndef BOOSTGEOMETRY_BITWISEOPR_H
#define BOOSTGEOMETRY_BITWISEOPR_H

#include <set>
#include <algorithm>
#include "Util.h"
// leetcode 268
// 二、leetcode No268. Missing Number
//
//Question：
//
//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//For example,
//Given nums = [0, 1, 3] return 2.
//
int leetcod268(std::vector<int> nums) {
    int output = 0;
    for (int i = 0; i <= nums.back(); ++i) {
        output ^= i;
    }

    for (auto& elem: nums) {
        output ^= elem;
    }
    return output;
}

// leetcode No136. Single Number
//Question：
//Given an array of integers, every element appears twice except for one. Find that single one.
//
int leetcod136(std::vector<int> nums) {
    int output = 0;
    for (auto& elem: nums) {
        output ^= elem;
    }
    return output;
}


// 137. Single Number II
//
//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//
//You must implement a solution with a linear runtime complexity and use only constant extra space.
//
//
//
//Example 1:
//
//Input: nums = [2,2,3,2]
//Output: 3
//
//Example 2:
//
//Input: nums = [0,1,0,1,0,1,99]
//Output: 99
//
//
//
//Constraints:
//
//    1 <= nums.length <= 3 * 104
//    -231 <= nums[i] <= 231 - 1
//    Each element in nums appears exactly three times except for one element which appears once.

// 1: hashmap
// 2: sort
// 3: math
// 4: bitset


int singleNumberHashmap(std::vector<int>& nums) {
    std::map<int, int> mp;
    for (auto elem: nums) {
        mp[elem]++;
    }

    for (auto elem: mp) {
        if (elem.second == 1) {
            return elem.first;
        }
    }
    return -1;
}

int singleNumberSort(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n;) {
        if ((i + 1) > (n - 1) || (i + 2) > (n - 1)) return i;
        if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
            i += 3;
            continue;
        } else {
            return i;
        }
    }
    return -1;
}

int singleNumberMath(std::vector<int>& nums) {
    std::set<int> s(nums.begin(), nums.end());
    int s_sum = 0;

    for (auto elem: s) {
        s_sum += elem;
    }

    int sum = 0;
    for (auto elem: nums) {
        sum += elem;
    }
    return (3 * s_sum - sum) / 2;
}


int singleNumberBit(std::vector<int>& nums) {
    int output = 0;
    for (int shift = 0; shift < 32; ++shift) {
        int bitSum = 0;
        for (auto elem: nums) {
            bitSum += ((elem >> shift) & 1);
        }
        bitSum %= 3;
        output |= (bitSum << shift);
    }
    return output;
}

// leetcode No260. Single Number III
//Question：
//
//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
//For example:
//
//Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//  1、按照Single Number的方法，对所有元素异或，那么得到的是这两个元素异或值xor_two
//  2、如何将两个元素分开，由于值不同的位异或为1，所以我们不妨可以找出xor_two的最后一个1（-xor_two为其补码），把两个元素区别，然后再分别对两个数组异或
//
std::vector<int> singleNumber(std::vector<int> &nums) {
    int xor_two = nums[0];
    int last_bit = 0;
    std::vector<int> result = {0, 0};
    for (int i = 1; i < nums.size(); i++)
        xor_two ^= nums[i];
    last_bit = xor_two & (~(xor_two - 1)); //相异为1，取异或的最后一个1，把两个元素区分，然后分别对两个数组异或
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] & last_bit)
            result[0] ^= nums[i];
        else
            result[1] ^= nums[i];
    }
    return result;
}


#endif //BOOSTGEOMETRY_BITWISEOPR_H
