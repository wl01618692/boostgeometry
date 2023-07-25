//
// Created by zhangjiayuan on 23-7-25.
//

#ifndef BOOSTGEOMETRY_HOUSEROBBER_H
#define BOOSTGEOMETRY_HOUSEROBBER_H
#include "Util.h"
// 198. House Robber
//
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
//the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected
//and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given an integer array nums representing the amount of money of each house,
//return the maximum amount of money you can rob tonight without alerting the police.
//
//Example 1:
//
//Input: nums = [1,2,3,1]
// [0，1,2,3,1]
//Output: 4
//Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//Total amount you can rob = 1 + 3 = 4.
//
//Example 2:
//
//Input: nums = [2,7,9,3,1]
//Output: 12
//Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//Total amount you can rob = 2 + 9 + 1 = 12.

int rob(std::vector<int>& nums) {
    std::vector<int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); ++i) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
}

int robOptimized(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int d0 = 0;
    int d1 = nums[0];
    int d2 = nums[0];
    for (int i = 2; i <= nums.size(); ++i) {
        d2 = std::max(d1, d0 + nums[i - 1]);
        d0 = d1;
        d1 = d2;
    }
    return d2;
}


#endif //BOOSTGEOMETRY_HOUSEROBBER_H
