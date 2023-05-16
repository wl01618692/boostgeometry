//
// Created by zhangjiayuan on 23-4-28.
//

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
//
// 提示：
//
//    1 <= nums.length <= 200
//    1 <= nums[i] <= 100
//
// 416

// 01 backpack
// bagweight = sum / 2
// use each element once
// value = weight
//


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
    int n = height.size();
    std::vector<int> lmax(n+1, 0);
    for (int i = 0; i < n; ++i) {
        lmax[i+1] = std::max(height[i], lmax[i]);
    }
    int rmax = 0, res = 0;
    for (int i = n-1; i >= 0; --i) {
        rmax = std::max(rmax, height[i]);
        res += std::min(lmax[i+1], rmax) - height[i];
    }
    return res;
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
    trapWater1(v);
}
