//
// Created by zhangjiayuan on 23-5-5.
//

#ifndef BOOSTGEOMETRY_ARRAY_H
#define BOOSTGEOMETRY_ARRAY_H

#include "Util.h"
// 示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。
// 示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
int removeElement(std::vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (val != nums[fastIndex]) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}

// 75. Sort Colors
//
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//
//You must solve this problem without using the library's sort function.
//
//
//
//Example 1:
//
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
//
//Example 2:
//
//Input: nums = [2,0,1]
//Output: [0,1,2]

void sortColors(vector<int>& nums) {
    // for all idx < p0 : nums[idx < p0] = 0
    // curr is an index of element under consideration
    int p0 = 0, curr = 0;
    // for all idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
        if (nums[curr] == 0) {
            swap(nums[curr++], nums[p0++]);
        } else if (nums[curr] == 2) {
            swap(nums[curr], nums[p2--]);
        } else curr++;
    }
}
#endif //BOOSTGEOMETRY_ARRAY_H
