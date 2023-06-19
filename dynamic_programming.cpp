//
// Created by zhangjiayuan on 23-4-28.
//

#include <algorithm>
#include <numeric>
#include "dynamic_programming.h"
int fib(int N) {
    if (N <= 1) return N;
    std::vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int fib1(int N) {
    if (N <= 1) return N;
    std::vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[2] = dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}

// 1-> 1
// 2-> 2, 1 + 1
// 3-> 3
// 4-> 5, 1 1 1 1, 2 2, 1 2 1, 1 1 2, 2 1 1
int stairCase(int N) {
    std::vector<int> dp(N + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

int stairCase_optimized(int N) {
    std::vector<int> dp(2);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 3; i <= N; ++i) {
        auto tmp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = tmp;
    }
    return dp[1];
}

//    输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//    输出：6
//    解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
int minCostClimbingStairs(std::vector<int> cost) {
    int N = cost.size();
    std::vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[N];
}

int minCostClimbingStairs_optimized(std::vector<int> cost) {
    int dp0 = 0;
    int dp1 = 0;
    for (int i = 2; i <= cost.size(); i++) {
        int dpi = std::min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
        dp0 = dp1;
        dp1 = dpi;
    }
    return dp1;
}

int different_path(int m, int n) {
    std::vector<std::vector<int>> vec(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) vec[i][0] = 1;
    for (int i = 0; i < n; ++i) vec[0][i] = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
        }
    }
    return vec[m - 1][n - 1];
}

int different_path_optimized(int m, int n) {
    std::vector<int> dp(n);
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            dp[i] += dp[i - 1];
        }
    }
    return dp[n - 1];
}

long long different_path_combinatorics(int m, int n) {
    long long res = 1;
    // m + n - 2 C m - 1
    for (int i = m; i <= m + n - 2 ; ++i) {
        res *= i;
    }
    return res;
}

int different_path2(std::vector<std::vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
    std::vector<std::vector<int>> vec(m, std::vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) vec[i][0] = 1;
    for (int i = 0; i < n && obstacleGrid[0][i] == 0; ++i) vec[0][i] = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) continue;
            vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
        }
    }
    return vec[m - 1][n - 1];
}

int different_path2_optimized(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1)
        return 0;
    std::vector<int> dp(obstacleGrid[0].size());
    for (int j = 0; j < dp.size(); ++j)
        if (obstacleGrid[0][j] == 1)
            dp[j] = 0;
        else if (j == 0)
            dp[j] = 1;
        else
            dp[j] = dp[j - 1];

    for (int i = 1; i < obstacleGrid.size(); ++i)
        for (int j = 0; j < dp.size(); ++j) {
            if (obstacleGrid[i][j] == 1)
                dp[j] = 0;
            else if (j != 0)
                dp[j] += dp[j-1];
        }
    return dp.back();
}

// 10 = 3 + 3 + 4
// <= 4 -> not break
int integerBreak(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    int res = 1;
    while (n > 4) {
        n -= 3;
        res *= 3;
    }
    res *= n;
    return res;
}

// weight 0 1 2 3 4
// item0: 0 15 15 15 15
// item1: 0 15 15 20 35
// item2: 0 15 15 20 35

// 一个商品如果可以重复多次放入是完全背包，而只能放入一次是01背
int bagWeight() {
    std::vector<int> weight = {1, 3, 4};
    std::vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // 二维数组
    std::vector<std::vector<int>> dp(weight.size(), std::vector<int>(bagweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for (int i = 1; i < weight.size(); i++) { // 遍历物品
        for (int j = 1; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    std::cout << dp[weight.size() - 1][bagweight] << std::endl;
}

// dp[i][j] = max(dp[i][j], dp[i][j - weight[i]] + value[i])
int bagWeight_optimized() {
    std::vector<int> weight = {1, 3, 4};
    std::vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    std::vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    std::cout << dp[bagWeight] << std::endl;
}

/// 416
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
// 注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
//
// 示例 1:
//
//    输入: [1, 5, 11, 5]
//    输出: true
//    解释: 数组可以分割成 [1, 5, 5] 和 [11].
//
// 示例 2:
//
//    输入: [1, 2, 3, 5]
//    输出: false
//    解释: 数组不能分割成两个元素和相等的子集.

//01背包中，dp[j] 表示： 容量为j的背包，所背的物品价值最大可以为dp[j]。
//
//本题中每一个元素的数值既是重量，也是价值。
//
//套到本题，dp[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为dp[j]。
//
//那么如果背包容量为target， dp[target]就是装满 背包之后的重量，所以 当 dp[target] == target 的时候，背包就装满了。
//拿输入数组 [1, 5, 11, 5]，举例， dp[7] 只能等于 6，因为 只能放进 1 和 5。
//
//而dp[6] 就可以等于6了，放进1 和 5，那么dp[6] == 6，说明背包装满了。
//
//01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
//
//本题，相当于背包里放入数值，那么物品i的重量是nums[i]，其价值也是nums[i]。
//
//所以递推公式：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
bool lc416(std::vector<int> nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int bagWeight = sum / 2; // 11

    std::vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i <= bagWeight; i++) { // 遍历物品
        for (int j = bagWeight; j >= nums[i]; j--) { // 遍历背包容量
            dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return dp[bagWeight] == bagWeight;
}

//    [1, 5, 11, 5]
//    [1, 5, 11, 5]
//    22, 11
//    背包的体积为sum / 2
//    背包要放入的商品（集合里的元素）重量为 元素的数值，价值也为元素的数值
//    背包如果正好装满，说明找到了总和为 sum / 2 的子集。
//    背包中每一个元素是不可重复放入。

/// lc 72
// edit distance
// s1 = "horse" s2 = "ros", // output = 3
int minDis(const std::string& s1, const std::string& s2) {
    int n = s1.size();
    int m = s2.size();
    if (n * m == 0) return std::max(n, m);

    std::vector<std::vector<int>> dp(n + 1, std::vector<int> (m + 1, 0));
    for (int i = 0; i < n + 1; ++i) {
        dp[i][0] = i;
    }

    for (int i = 1; i < m + 1; ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            int left = dp[i - 1][j] + 1;
            int down = dp[i][j - 1] + 1;
            int left_down = dp[i - 1][j - 1];
            if (s1[i - 1] != s2[j - 1]) left_down += 1;
            dp[i][j] = std::min(left, std::min(down, left_down));
        }
    }
    return dp[n][m];
}


/// lc42
// [0,1,0,2,1,0,1,3,2,1,2,1]
int trapWater1(std::vector<int> height) {
    int res = 0;
    std::vector<int> lmax(height.size(), 0);
    std::vector<int> rmax(height.size(), 0);
    for (int i = 1; i < height.size(); ++i) {
        lmax[i] = std::max(lmax[i - 1], height[i - 1]);
    }

    for (int i = height.size() - 2; i >= 0; --i) {
        rmax[i] = std::max(rmax[i + 1], height[i + 1]);
    }

    for (int i = 1; i < height.size(); ++i) {
        auto tmp = std::min(lmax[i], rmax[i]) - height[i];
        if (tmp > 0) res += tmp;
    }
    return res;
}

/// 64
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
int minPathSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int> (n, 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
}

int minPathSumOptimized(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    std::vector<int> dp(n, 0);

    dp[0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i] = grid[0][i] + dp[i - 1];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                dp[j] = dp[0] + grid[i][0];
            } else {
                dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
    }
    return dp[n - 1];
}

// 740. Delete and Earn
//You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
//
//Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
//
//Return the maximum number of points you can earn by applying the above operation some number of times.
//
//Example 1:
//
//Input: nums = [3,4,2]
//Output: 6
//Explanation: You can perform the following operations:
//- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
//- Delete 2 to earn 2 points. nums = [].
//You earn a total of 6 points.
//
//Example 2:
//
//Input: nums = [2,2,3,3,3,4]
//Output: 9
//Explanation: You can perform the following operations:
//- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
//- Delete a 3 again to earn 3 points. nums = [3].
//- Delete a 3 once more to earn 3 points. nums = [].
//You earn a total of 9 points.

// 0 4 4 9 9 9 9
// 状态定义：f[i] 为数组中数字 1 ~ i 通过操作能获取的最大分值。
//
//状态转移：
//
//    对于数字 i，如果选（即删除并获取分值），得分为 f[i - 2] + i * c[i]
//    对于数字 i，如果不选（即放弃操作），的氛围 f[i - 1]
int deleteAndEarn(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int maxVal = 0;
    std::map<int, int> mp;
    for (auto & elem: nums) {
        if (elem > maxVal) {
            maxVal = elem;
        }
        mp[elem]++;
    }
    std::vector<int> dp(maxVal + 1, 0);
    if (mp.find(1) != mp.end()) dp[1] = mp[1];
    for (int i = 2; i <= maxVal; ++i) {
        dp[i] = std::max(mp[i] * i + dp[i - 2], dp[i - 1]);
    }
    return dp[maxVal];
}

int deleteAndEarnOptimized(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int maxVal = 0;
    std::map<int, int> mp;
    for (auto & elem: nums) {
        if (elem > maxVal) {
            maxVal = elem;
        }
        mp[elem]++;
    }
    int dp0 = 0;
    int dp1 = 0;
    int dp2 = 0;
    if (mp.size() == 1) return mp.begin()->first * mp.begin()->second;
    if (mp.find(1) != mp.end()) dp1 = mp[1];
    for (int i = 2; i <= maxVal; ++i) {
        dp2 = std::max(mp[i] * i + dp0, dp1);
        dp0 = dp1;
        dp1 = dp2;
    }
    return dp2;
}

// 120. Triangle
//Given a triangle array, return the minimum path sum from top to bottom.
//
//For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
//
//
//
//Example 1:
//
//Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//Output: 11
//Explanation: The triangle looks like:
// 2
// 3 4
// 6 5 7
// 4 1 8 3
//The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
//
//Example 2:
//
//Input: triangle = [[-10]]
//Output: -10
// [[7],[-5,9],[6,5,2],[-8,-2,-7,3],[-2,6,-6,-1,4]]
// 7
// -5 9
// 6 5 2
// -8,-2,-7,3
// -2,6,-6,-1,4
int minimumTotal(std::vector<std::vector<int>>& triangle) {
    if (triangle.size() == 1) return triangle[0][0];
    int n = triangle.size();
    int m = triangle.back().size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
                continue;
            }
            if (dp[i - 1][j] == 0 && i == j) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                continue;
            }
            dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
    }

    int minVal = INT32_MAX;
    for (auto & elem: dp[n - 1]) {
        minVal = std::min(minVal, elem);
    }
    return minVal;
}

int minimumTotalOptimized(std::vector<std::vector<int>>& triangle) {
    if (triangle.size() == 1) return triangle[0][0];
    int n = triangle.size();
    int m = triangle.back().size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
                continue;
            }
            if (dp[i - 1][j] == 0) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                continue;
            }
            dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
    }

    int minVal = INT32_MAX;
    for (auto & elem: dp[n - 1]) {
        minVal = std::min(minVal, elem);
    }
    return minVal;
}

void test_dp() {
    std::cout << fib(2) << std::endl;
    std::cout << fib(4) << std::endl;
    std::cout << fib(6) << std::endl;
    std::cout << fib1(2) << std::endl;
    std::cout << fib1(4) << std::endl;
    std::cout << fib1(6) << std::endl;
    std::cout << stairCase(2) << std::endl;
    std::cout << stairCase(4) << std::endl;
    std::cout << stairCase(6) << std::endl;
    std::cout << minDis("horse", "ros") << std::endl;
    std::vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    std::vector<int> v1 = {1, 3, 1};
    std::vector<int> v2 = {1, 5, 1};
    std::vector<int> v3 = {4, 2, 1};
    std::vector<std::vector<int>> grid;
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);
    minPathSumOptimized(grid);

    std::vector<int> k1 = {1, 2, 3};
    std::vector<int> k2 = {4, 5, 6};
    grid.clear();
    grid.push_back(k1);
    grid.push_back(k2);
    minPathSumOptimized(grid);

    trapWater1(v);

    std::vector<int> nums123 = {2,2,3,3,3,4};
    deleteAndEarnOptimized(nums123);

    std::vector<int> v4 = {7};
    std::vector<int> v5 = {-5,9};
    std::vector<int> v6 = {6,5,2};
    std::vector<int> v7 = {-8,-2,-7,3};
    std::vector<int> v8 = {-2,6,-6,-1,4};
    std::vector<std::vector<int>> kk= {v4, v5, v6, v7, v8};
    minimumTotal(kk);
}
