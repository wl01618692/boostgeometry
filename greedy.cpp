//
// Created by zhangjiayuan on 23-5-8.
//

#include <algorithm>
#include <numeric>
#include "greedy.h"

/// lc 397
// 力扣397. 整数替换
//
//这是原题：
//给定一个正整数 n ，你可以做如下操作：
//如果 n 是偶数，则用 n / 2替换 n 。
//如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
//n 变为 1 所需的最小替换次数是多少？
//同时还给出了三个示例：
//示例 1：
//输入：n = 8
//输出：3
//解释：8 -> 4 -> 2 -> 1
//示例 2：
//输入：n = 7
//输出：4
//解释：7 -> 8 -> 4 -> 2 -> 1
//或 7 -> 6 -> 3 -> 2 -> 1
//示例 3：
//输入：n = 4
//输出：2
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
            continue;
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

//int maxSubArray(std::vector<int>& nums) {
//    int result = INT32_MIN;
//    int count = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//        count += nums[i];
//        if (count > result) {
//            result = count;
//        }
//        if (count < 0) count = 0;
//    }
//    return result;
//}

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
    int ans = 0;
    int curDis = 0, nextDis = 0;
    for (int i = 0; i < nums.size(); ++i) {
        nextDis = std::max(nextDis, i + nums[i]);
        if (curDis == i) {
            if (curDis < nums.size()) {
                curDis = nextDis;
                ++ans;
                if (nextDis >= nums.size() - 1) break;
            } else break;
        }
    }
    return ans;
}


/// lc 738
// 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//
//（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
//
//示例 1:
//
//    输入: N = 10
//    输出: 9
//
//示例 2:
//
//    输入: N = 1234
//    输出: 1234
//
//示例 3:
//
//    输入: N = 332
//    输出: 299
//
//说明: N 是在 [0, 10^9] 范围内的一个整数。
//
// 94 -> 89
// 332 -> 329 -> 299 back to front
// 332 -> 329 front to back
// 4111 -> 3999
int monotoneIncreasingDigits(int N) {
    std::string N_str = std::to_string(N);
    int flag = 0;
    for (int i = N_str.size() - 1; i >= 1; --i) {
        if (N_str[i] < N_str[i - 1]) {
            flag = i;
            N_str[i - 1] -= 1;
        }
    }

    while (flag != N_str.size()) {
        N_str[flag] = '9';
        ++flag;
    }

    return std::stoi(N_str);
}

/// 105
//给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）
//
//以这种方式修改数组后，返回数组可能的最大和。
//
//示例 1：
//
//    输入：A = [4,2,3], K = 1
//    输出：5
//    解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
//
//示例 2：
//
//    输入：A = [3,-1,0,2], K = 3
//    输出：6
//    解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
//
//示例 3：
//
//    输入：A = [2,-3,-1,5,-4], K = 2
//    输出：13
//    解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
//
//提示：
//
//    1 <= A.length <= 10000
//    1 <= K <= 10000
//    -100 <= A[i] <= 100
//
//#

static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}

int lc105(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= 0 && k > 0) {
            nums[i] *= -1;
            --k;
        }
    }
    if (k % 2 == 1) {
        nums[nums.size() - 1] *= -1;
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
}

/// 134
// 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//
//如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
//
//说明:
//
//    如果题目有解，该答案即为唯一答案。
//    输入数组均为非空数组，且长度相同。
//    输入数组中的元素均为非负数。
//
//示例 1: 输入:
//
//    gas = [1,2,3,4,5]
//    cost = [3,4,5,1,2]
//
//输出: 3 解释:
//
//    从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//    开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//    开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//    开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//    开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//    开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//    因此，3 可为起始索引。
//
//示例 2: 输入:
//
//    gas = [2,3,4]
//
//    cost = [3,4,3]
//
//    输出: -1
//
//    解释: 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油。开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油。开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油。你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。因此，无论怎样，你都不可能绕环路行驶一周。
//

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    for (int i = 0; i < cost.size(); i++) {
        int rest = gas[i] - cost[i];
        int index = (i + 1) % cost.size();
        while (rest > 0 && index != i) { // 模拟以i为起点行驶一圈（如果有rest==0，那么答案就不唯一了）
            rest += gas[index] - cost[index];
            index = (index + 1) % cost.size();
        }
        // 如果以i为起点跑一圈，剩余油量>=0，返回该起始位置
        if (rest >= 0 && index == i) return i;
    }
    return -1;
}

int canCompleteCircuit1(std::vector<int>& gas, std::vector<int>& cost) {
    int curSum = 0;
    int min = INT32_MAX; // 从起点出发，油箱里的油量最小值
    for (int i = 0; i < gas.size(); i++) {
        int rest = gas[i] - cost[i];
        curSum += rest;
        if (curSum < min) {
            min = curSum;
        }
    }
    // 直接从全局进行贪心选择，情况如下：
    //
    //    情况一：如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
    //
    //    情况二：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。
    //
    //    情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能把这个负数填平，能把这个负数填平的节点就是出发节点。
    if (curSum < 0) return -1;  // 情况1
    if (min >= 0) return 0;     // 情况2
    // 情况3
    for (int i = gas.size() - 1; i >= 0; i--) {
        int rest = gas[i] - cost[i];
        min += rest;
        if (min >= 0) {
            return i;
        }
    }
    return -1;
}

/// 406
// 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//
//请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
//
//示例 1：
//
//    输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
//    输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
//      7,0 7,1 6,1, 5,0 5,2 4,4

//      7,0
//      7,0 7,1
//      7,0 6,1 7,1
//      5,0 7,0 6,1 7,1
//      5,0 7,0 6,1 7,1
//      5,0 7,0 5,2 6,1 7,1
//      5,0 7,0 5,2 6,1 4,4 7,1
//    解释：
//        编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
//        编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
//        编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
//        编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//        编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
//        编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//        因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
//
//示例 2：
//
//    输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
//    输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
//
//提示：
//
//    1 <= people.length <= 2000
//    0 <= hi <= 10^6
//    0 <= ki < people.length
//
//题目数据确保队列可以被重建

bool comp(std::vector<int> lhs, std::vector<int> rhs) {
    if (lhs[0] == rhs[0]) {
        return rhs > lhs;
    }
    return lhs[0] > rhs[0];
}


std::vector<std::vector<int>> lc406(std::vector<std::vector<int>> people) {
    std::sort(people.begin(), people.end(), comp);
    std::vector<std::vector<int>> output;
    for (auto elem: people) {
        if (output.size() <= elem[1]) {
            output.push_back(elem);
        } else {
            output.insert(output.begin() + elem[1], elem);
        }
    }
    return output;
}



// 806
// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
//
//顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//
//注意，一开始你手头没有任何零钱。
//
//如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
//
//示例 1：
//
//    输入：[5,5,5,10,20]
//    输出：true
//    解释：
//        前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
//        第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
//        第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
//        由于所有客户都得到了正确的找零，所以我们输出 true。
//
//示例 2：
//
//    输入：[5,5,10]
//    输出：true
//
//示例 3：
//
//    输入：[10,10]
//    输出：false
//
//示例 4：
//
//    输入：[5,5,10,10,20]
//    输出：false
//    解释：
//        前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
//        对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
//        对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
//        由于不是每位顾客都得到了正确的找零，所以答案是 false。
//
//提示：
//
//    0 <= bills.length <= 10000
//    bills[i] 不是 5 就是 10 或是 20
//

bool lemonadeChange(std::vector<int>& bills) {
    int count5 = 0, count10 = 0, count20 = 0;
    for (auto elem: bills) {
        if (elem == 5) {
            count5++;
            continue;
        } else if (elem == 10) {
            if (count5 == 0) {
                return false;
            } else {
                count10++;
                count5--;
            }
        } else {
            if (count10 >= 1 && count5 >= 1) {
                count10--;
                count5--;
                count20++;
            } else if (count5 >= 3) {
                count5 -=3;
                count20++;
            } else {
                return false;
            }
        }
    }
    return true;
}

//452. 用最少数量的箭引爆气球
//
//在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
//
//一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
//
// 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
//
//给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
//
//示例 1：
//
//    输入：points = [[10,16],[2,8],[1,6],[7,12]]
//    输出：2
//    解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
//
// [1,6]    [2,8]   [7,12]      [10,16]
//示例 2：
//
//    输入：points = [[1,2],[3,4],[5,6],[7,8]]
//    输出：4
//
//示例 3：
//
//    输入：points = [[1,2],[2,3],[3,4],[4,5]]
//    输出：2
//
//示例 4：
//
//    输入：points = [[1,2]]
//    输出：1
//
//示例 5：
//
//    输入：points = [[2,3],[2,3]]
//    输出：1
//
//提示：
//
//    0 <= points.length <= 10^4
//    points[i].length == 2
//    -2^31 <= xstart < xend <= 2^31 - 1

//     时间复杂度：O(nlog n)，因为有一个快排
//    空间复杂度：O(1)，有一个快排，最差情况(倒序)时，需要n次递归调用。因此确实需要O(n)的栈空间

bool mySort(std::vector<int> lhs, std::vector<int> rhs) {
    if (lhs[0] == rhs[0]) {
        return lhs[1] < rhs[1];
    }
    return lhs[0] < rhs[0];
}


int findMinArrowShots(std::vector<std::vector<int>>& points) {
    int count = 0;
    std::sort(points.begin(), points.end(), mySort);
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0] > points[i - 1][1]) {
            ++count;
            continue;
        } else {
            points[i][1] = std::min(points[i - 1][1], points[i][1]);
        }
    }
    return count;
}


//435. 无重叠区间
//
//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//
//注意: 可以认为区间的终点总是大于它的起点。 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
//
//示例 1:
//
//    输入: [ [1,2], [2,3], [3,4], [1,3] ]
//    输出: 1
//    解释: 移除 [1,3] 后，剩下的区间没有重叠。
//
//示例 2:
//
//    输入: [ [1,2], [1,2], [1,2] ]
//    输出: 2
//    解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
//
//示例 3:
//
//    输入: [ [1,2], [2,3] ]
//    输出: 0
//    解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
//


//     时间复杂度：O(nlog n) ，有一个快排
//    空间复杂度：O(n)，有一个快排，最差情况(倒序)时，需要n次递归调用。因此确实需要O(n)的栈空间

class Solution435 {
public:
    static bool cmp (const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0]; // 左边界排序
    }
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        std::sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; // 注意这里从0开始，因为是记录重叠区间
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end)  end = intervals[i][1]; // 无重叠的情况
            else { // 重叠情况
                end = std::min(end, intervals[i][1]);
                count++;
            }
        }
        return count;
    }

    int eraseOverlapIntervals2(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        std::sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; // 注意这里从0开始，因为是记录重叠区间
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) { //重叠情况
                intervals[i][1] = std::min(intervals[i - 1][1], intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};


//763.划分字母区间
//
//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
//
//示例：
//
//    输入：S = "ababcbacadefegdehijhklij"
//    输出：[9,7,8] 解释： 划分结果为 "ababcbaca", "defegde", "hijhklij"。 每个字母最多出现在一个片段中。 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//
//提示：
//
//    S的长度在[1, 500]之间。
//    S只包含小写字母 'a' 到 'z' 。
//

std::vector<int> partitionLabels(std::string S) {

}

