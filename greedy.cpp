//
// Created by zhangjiayuan on 23-5-8.
//

#include <algorithm>
#include "greedy.h"

/// lc 397
int integerReplacement(int n) {
    int ans = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            ++ans;
            continue;
        }

        if (n == 3) {
            ++ans;
            --n;
        } else if (n == 2147483647) {
            ans = 32;
            break;
        }

        if ((n + 1) % 4 == 0) {
            ++n;
            ++ans;
        } else {
            --n;
            ++ans;
        }
    }
    return ans;
}

// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
// 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
//示例 1:
//    输入: g = [1,2,3], s = [1,1]
//    输出: 1
//    解释:你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。所以你应该输出1。
//
//示例 2:
//    输入: g = [1,2], s = [1,2,3]
//    输出: 2
//    解释:你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。你拥有的饼干数量和尺寸都足以让所有孩子满足。所以你应该输出2.

// 【1，2】 【1，2，3，4】
// 【1，2，3，4】 【1，2】
// 【1，2，3，4】 【1，2，3，4】
int distriuteCookie(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int count = 0;
    for (int i = 0, j = 0; i < g.size() && j < s.size(); ++i) {
        if (s[i] >= g[j]) {
            ++count;
            ++j;
        } else {
            while (j < s.size()) {
                ++j;
                if (s[i] >= g[j]) {
                    ++count;
                    break;
                }
            }
        }
    }
    return count;
}


// 例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
//
//给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
//
//示例 1:
//
//    输入: [1,7,4,9,2,5]
//    输出: 6
//    解释: 整个序列均为摆动序列。
//
//示例 2:
//
//    输入: [1,17,5,10,13,15,10,5,16,8]
//    输出: 7
//    解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
//
//示例 3:
//
//    输入: [1,2,3,4,5,6,7,8,9]
//    输出: 2

int wiggleMaxLength(std::vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    int curDiff = 0; // 当前一对差值
    int preDiff = 0; // 前一对差值
    int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
    for (int i = 0; i < nums.size() - 1; i++) {
        curDiff = nums[i + 1] - nums[i];
        // 出现峰值
        if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
            result++;
            preDiff = curDiff;
        }
    }
    return result;
}


// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
// 示例:
//
//    输入: [-2,1,-3,4,-1,2,1,-5,4]
//    输出: 6
//    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
//

//    时间复杂度：O(n^2)
//    空间复杂度：O(1)
int maxSubArray_bf(std::vector<int> &nums) {
    int result = INT32_MIN;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) { // 设置起始位置
        count = 0;
        for (int j = i; j < nums.size(); j++) { // 每次从起始位置i开始遍历寻找最大值
            count += nums[j];
            result = count > result ? count : result;
        }
    }
    return result;
}

int maxSubArray(std::vector<int>& nums) {
    int result = INT32_MIN;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        count += nums[i];
        if (count > result) {
            result = count;
        }
        if (count < 0) count = 0;
    }
    return result;
}

/// lc 122
// 示例 1:
//
//     输入: [7,1,5,3,6,4]
//     输出: 7
//     解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4。随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
//
// 3 6 4 7 1 12
// 示例 2:
//
//     输入: [1,2,5,8,15]
//     输出: 4
//     解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
//
// 示例 3:
//
//     输入: [7,6,4,3,1]
//     输出: 0
//     解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//
// 提示：
//
//     1 <= prices.length <= 3 * 10 ^ 4
//     0 <= prices[i] <= 10 ^ 4
//
int sellStock(std::vector<int>& v) {
    int res = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        res += std::max(0, v[i + 1] - v[i]);
    }
    return res;
}


/// lc 55
// jump game
// 给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个位置。
//
//示例 1:
//
//    输入: [2,3,1,1,4]
//    输出: true
//    解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
//
//示例 2:
//
//    输入: [3,2,1,0,4]
//    输出: false
//    解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

bool canJump(std::vector<int>& nums) {
    int cover = 0;
    if (nums.size() == 1) return true; // 只有一个元素，就是能达到
    for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
        cover = std::max(i + nums[i], cover);
        if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
    }
    return false;
}


/// lc 45
// jump game 2
// 给定一个非负整数数组，你最初位于数组的第一个位置。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
// 示例:
//
//     输入: [2,3,1,1,4]
//     输出: 2
//     解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//
// 说明: 假设你总是可以到达数组的最后一个位置


int jump(std::vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int curDistance = 0;    // 当前覆盖最远距离下标
    int ans = 0;            // 记录走的最大步数
    int nextDistance = 0;   // 下一步覆盖最远距离下标
    for (int i = 0; i < nums.size(); i++) {
        nextDistance = std::max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
        if (i == curDistance) {                         // 遇到当前覆盖最远距离下标
            if (curDistance < nums.size() - 1) {       // 如果当前覆盖最远距离下标不是终点
                ans++;                                  // 需要走下一步
                curDistance = nextDistance;             // 更新当前覆盖最远距离下标（相当于加油了）
                if (nextDistance >= nums.size() - 1) break; // 下一步的覆盖范围已经可以达到终点，结束循环
            } else break;                               // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
        }
    }
    return ans;
}



