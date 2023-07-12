//
// Created by zhangjiayuan on 23-7-11.
//

#ifndef BOOSTGEOMETRY_BITWISEOPR_H
#define BOOSTGEOMETRY_BITWISEOPR_H
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
