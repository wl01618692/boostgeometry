//
// Created by zhangjiayuan on 23-7-24.
//

#ifndef BOOSTGEOMETRY_BUYANDSELLSTOCK_H
#define BOOSTGEOMETRY_BUYANDSELLSTOCK_H
#include "Util.h"

// 121. Best Time to Buy and Sell Stock
//
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//
//
//
//Example 1:
//
//Input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
//
//Example 2:
//
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transactions are done and the max profit = 0.

int maxProfit(vector<int>& prices) {
    int result = 0;
    int low = INT32_MAX;
    for (auto elem: prices) {
        low = std::min(elem, low);
        result = std::max(result, elem - low);
    }
    return result;
}

// 122. Best Time to Buy and Sell Stock II
//
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
//
//On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
//
//Find and return the maximum profit you can achieve.
//
//
//
//Example 1:
//
//Input: prices = [7,1,5,3,6,4]
//Output: 7
//Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
//Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
//Total profit is 4 + 3 = 7.
//
//Example 2:
//
//Input: prices = [1,2,3,4,5]
//Output: 4
//Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//Total profit is 4.
//
//Example 3:
//
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
//
//
//
//Constraints:
//
//    1 <= prices.length <= 3 * 104
//    0 <= prices[i] <= 104

int maxProfit122(vector<int>& prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] - prices[i - 1] > 0) {
            res += prices[i] - prices[i - 1];
        }
    }
    return res;
}

// 123. Best Time to Buy and Sell Stock III
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
//Find the maximum profit you can achieve. You may complete at most two transactions.
//
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//
//
//
//Example 1:
//
//Input: prices = [3,3,5,0,0,3,1,4]
//Output: 6
//Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
//Example 2:
//
//Input: prices = [1,2,3,4,5]
//Output: 4
//Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
//
//Example 3:
//
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
//
//
//Constraints:
//
//    1 <= prices.length <= 105
//    0 <= prices[i] <= 105

int maxProfitIII(vector<int>& prices) {
    int n = prices.size();
    std::vector<int> dp(prices.size(), 0);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length <= 1) return 0;

        int leftMin = prices[0];
        int rightMax = prices[length - 1];

        vector<int> leftProfits(length, 0);
        vector<int> rightProfits(length + 1, 0);

        // construct the bidirectional DP array
        for (int l = 1; l < length; ++l) {
            leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
            leftMin = min(leftMin, prices[l]);

            int r = length - 1 - l;
            rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
            rightMax = max(rightMax, prices[r]);
        }

        int maxProfit = 0;
        for (int i = 0; i < length; ++i) {
            maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
        }
        return maxProfit;
    }
};

// 188. Best Time to Buy and Sell Stock IV
//
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
//
//Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
//
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//
//
//
//Example 1:
//
//Input: k = 2, prices = [2,4,1]
//Output: 2
//Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
//Example 2:
//
//Input: k = 2, prices = [3,2,6,5,0,3]
//Output: 7
//Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//
//
//
//Constraints:
//
//    1 <= k <= 100
//    1 <= prices.length <= 1000
//    0 <= prices[i] <= 1000
int maxProfit(int k, vector<int>& prices) {

}

#endif //BOOSTGEOMETRY_BUYANDSELLSTOCK_H
