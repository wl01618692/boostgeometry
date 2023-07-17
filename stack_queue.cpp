//
// Created by zhangjiayuan on 23-5-12.
//

#include <stack>
#include <algorithm>
#include "stack_queue.h"
#include <queue>
#include <unordered_map>

/// lc 150
// 根据 逆波兰表示法，求表达式的值。
//
//有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//说明：
//
//整数除法只保留整数部分。 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//
//示例 1：
//
//    输入: ["2", "1", "+", "3", " * "]
//    输出: 9
//    解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//
//示例 2：
//
//    输入: ["4", "13", "5", "/", "+"]
//    输出: 6
//    解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
//
//示例 3：
//
//    输入: ["10", "6", "9", "3", "+", "-11", " * ", "/", " * ", "17", "+", "5", "+"]
//
//    输出: 22
//
//    解释:该算式转化为常见的中缀算术表达式为：

//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//  = ((10 * (6 / (12 * -11))) + 17) + 5
//  = ((10 * (6 / -132)) + 17) + 5
//  = ((10 * 0) + 17) + 5
//  = (0 + 17) + 5
//  = 17 + 5
//  = 22

int output150(const std::vector<std::string>& tokens) {
    std::stack<int> s;

    for (auto &elem: tokens) {
        if (elem == "+" || elem == "-" || elem == "*" || elem == "/") {
            auto val1 = s.top();
            s.pop();
            auto val2 = s.top();
            s.pop();
            if (elem == "+") s.push(val2 + val1);
            if (elem == "/") s.push(val2 / val1);
            if (elem == "-") s.push(val2 - val1);
            if (elem == "*") s.push(val2 * val1);
        } else {
            s.push(std::stoi(elem));
        }
    }
    return s.top();
}

/// lc 1047
//  给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//
//  在 S 上反复执行重复项删除操作，直到无法继续删除。
//
//  在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//
//  示例：
//
//      输入："abbaca"
//      输出："ca"
//      解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
//
//  提示：
//
//      1 <= S.length <= 20000
//      S 仅由小写英文字母组成。
//
// abba
std::string output1047(const std::string& nums) {
    std::stack<char> s;

    for (auto &elem: nums) {
        if (s.empty() || s.top() != elem) {
            s.push(elem);
        } else {
            s.pop();
        }
    }

    std::string output;
    while (!s.empty()) {
        output += s.top();
        s.pop();
    }
    std::reverse(output.begin(), output.end());
    return output;
}

/// lc 20
//      给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//      有效字符串需满足：
//
//          左括号必须用相同类型的右括号闭合。
//          左括号必须以正确的顺序闭合。
//          注意空字符串可被认为是有效字符串。
//
//      示例 1:
//
//          输入: "()"
//          输出: true
//
//      示例 2:
//
//          输入: "()[]{}"
//          输出: true
//
//      示例 3:
//
//          输入: "(]"
//          输出: false
//
//      示例 4:
//
//          输入: "([)]"
//          输出: false
//
//      示例 5:
//
//          输入: "{[]}"
//          输出: true
//

bool output20(const std::string& nums) {
    if (nums.empty()) return true;
    std::stack<char> s;

    for (auto &elem: nums) {
        if (s.empty()) {
            s.push(elem);
            continue;
        }
        if (s.top() == '(' && elem == ')' || s.top() == '[' && elem == ']'|| s.top() == '{' && elem == '}') {
            s.pop();
        } else {
            s.push(elem);
        }
    }
    return s.empty();
}

/// lc 232
//  232.用栈实现队列
//
//  使用栈实现队列的下列操作：
//
//  push(x) -- 将一个元素放入队列的尾部。
//  pop() -- 从队列首部移除元素。
//  peek() -- 返回队列首部的元素。
//  empty() -- 返回队列是否为空。

//说明:
//
//    你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
//    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//    假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
//

//  MyQueue queue = new MyQueue();
//  queue.push(1);
//  queue.push(2);
//  queue.peek();  // 返回 1
//  queue.pop();   // 返回 1
//  queue.empty(); // 返回 false

class queue {
public:
    void push(int input) {
        s1.push(input);
        while (!s2.empty()) {
            s2.pop();
        }
        auto tmp = s1;
        while (!tmp.empty()) {
            s2.push(tmp.top());
            tmp.pop();
        }
    }

    void pop() {
        s2.pop();
        while (!s1.empty()) {
            s1.pop();
        }
        auto tmp = s2;
        while (!tmp.empty()) {
            s1.push(tmp.top());
            tmp.pop();
        }
    }

    bool empty() {
        return s1.empty();
    }

    int peek() {
        return s2.top();
    }
private:
    std::stack<int> s1;
    std::stack<int> s2;
};

/// lc 225
// 使用队列实现栈的下列操作：
//
//    push(x) -- 元素 x 入栈
//    pop() -- 移除栈顶元素
//    top() -- 获取栈顶元素
//    empty() -- 返回栈是否为空
//
//注意:
//
//    你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
//    你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//    你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//
// 225

// stack
// queue
// priority_queue
// monotone_queue
// monotone_stack

// deque

class stack {
public:
    stack(){};

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int size = q.size() - 1;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            q.push(q.front());
            q.pop();
        }
        int result = q.front(); // 此时弹出的元素顺序就是栈的顺序了
        q.pop();
        return result;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};

/// lc 347
//  给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
//  示例 1:
//
//      输入: nums = [1,1,1,2,2,3], k = 2
//      输出: [1,2]
//
//  示例 2:
//
//      输入: nums = [1], k = 1
//      输出: [1]
//
//  提示：
//
//      你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//      你的算法的时间复杂度必须优于 $O(n \log n)$ , n 是数组的大小。
//      题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
//      你可以按任意顺序返回答案。
//

// 小顶堆
// less<T> 大顶堆
// greater<T> 小顶堆
using namespace std;
class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    // 要统计元素出现频率
    unordered_map<int, int> map; // map<nums[i],对应出现的次数>
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }

    // 对频率排序
    // 定义一个小顶堆，大小为k
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

    // 用固定大小为k的小顶堆，扫面所有频率的数值
    for (auto it = map.begin(); it != map.end(); it++) {
        pri_que.push(*it);
        if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
            pri_que.pop();
        }
    }

    // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
        result[i] = pri_que.top().first;
        pri_que.pop();
    }
    return result;
}

/// lc 239
// 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//
//返回滑动窗口中的最大值。
//


// nums = [1,3,-1,-3, 5, 3, 6, 7] k = 3
// output = [3, 3, 5, 5, 6, 7]
class monotone_queue {
public:
    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    void push(int num) {
        while (!q.empty()) {
            if (num > q.back()) {
                q.pop();
            } else {
                break;
            }
        }
        q.push(num);
    }

    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    monotone_queue mq;
    std::vector<int> output;
    for (int i = 0; i < k; ++i) {
        mq.push(nums[i]);
    }
    output.push_back(mq.top());

    for(int i = 0; i < nums.size() - k; ++i) {
        if (mq.top() == nums[i]) {
            mq.pop();
        }
        mq.push(nums[i + k]);
        output.push_back(mq.top());
    }
    return output;
}

/// lc 739
//  请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//
//  例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
//
//  提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
//
std::vector<int> lc739(std::vector<int> temp) {
    std::stack<int> s;
    std::vector<int> output(temp.size(), 0);
    for (int i = 0; i < temp.size(); ++i) {
        while ((!s.empty()) || temp[i] > temp[s.top()]) {
            auto tmp = s.top();
            output[tmp] = i - tmp;
            s.pop();
        }
        s.push(i);
    }
    return output;
}

// lc 496
// 给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
//
//请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
//
//nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
//
//示例 1:
//
//输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
//输出: [-1,3,-1]
//解释:
//对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
//对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
//对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
//
//示例 2:
//输入: nums1 = [2,4], nums2 = [1,2,3,4].
//输出: [3,-1]
//解释:
//对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
//对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出-1 。

std::vector<int> lc496(std::vector<int> vec1, std::vector<int> vec2) {
    std::stack<int> s;
    std::map<int, int> m;
    std::vector<int> output(vec1.size(), 0);
    for (const auto& elem: vec2) {
        while (!s.empty() && elem > s.top()) {
            m[s.top()] = elem;
            s.pop();
        }
        s.push(elem);
    }

    while (!s.empty()) {
        m[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < vec1.size(); ++i) {
        output[i] = m[vec1[i]];
    }
    return output;
}

// lc503
// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
//
//示例 1:
//
//    输入: [1,2,1]
//    输出: [2,-1,2]
//    解释: 第一个 1 的下一个更大的数是 2；数字 2 找不到下一个更大的数；第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
//
//提示:
//
//    1 <= nums.length <= 10^4
//    -10^9 <= nums[i] <= 10^9

vector<int> nextGreaterElements(vector<int>& nums) {
    std::vector<int> result(2 * nums.size(), 0);
    std::vector<int> nums1(nums.begin(), nums.end());
    nums1.insert(nums1.end(), nums.begin(), nums.end());

    std::stack<int> s;
    for (int i = 0; i < nums1.size(); ++i) {
        auto elem = nums1[i];
        while (!s.empty() && nums1[s.top()] < elem) {
            auto val = s.top();
            s.pop();
            result[val] = elem;
        }
        s.push(i);
    }
    while (!s.empty()) {
        auto val = s.top();
        s.pop();
        result[val] = -1;
    }
    result.resize(result.size() / 2);
    return result;
}

// 844.比较含退格的字符串
//
//
//给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
//
//注意：如果对空文本输入退格字符，文本继续为空。


// "a##c"
// "#a#c"
bool lc844(std::string s, std::string t) {
    std::stack<int> s1;
    std::stack<int> s2;
    for (auto& elem: s) {
        if (elem == '#') {
            if (s1.empty()) continue;
            s1.pop();
        } else {
            s1.push(elem);
        }
    }

    for (auto& elem:t) {
        if (elem == '#') {
            if (s2.empty()) continue;
            s2.pop();
        } else {
            s2.push(elem);
        }
    }

    if (s1.size() != s2.size()) return false;
    while (!s1.empty() || !s2.empty()) {
        if (s1.top() != s2.top()) {
            return false;
        }
        s1.pop();
        s2.pop();
    }
    return true;
}

//
//示例 1：
//
//    输入：s = "ab#c", t = "ad#c"
//    输出：true
//    解释：s 和 t 都会变成 “ac”。
//
//示例 2：
//
//    输入：s = "ab##", t = "c#d#"
//    输出：true
//    解释：s 和 t 都会变成 “”。
//
//示例 3：
//
//    输入：s = "a##c", t = "#a#c"
//    输出：true
//    解释：s 和 t 都会变成 “c”。
//
//示例 4：
//
//    输入：s = "a#c", t = "b"
//    输出：false
//    解释：s 会变成 “c”，但 t 仍然是 “b”。
bool backspaceCompare(string s, string t) {
    int i = s.size() - 1;
    int j = t.size() - 1;
    while (true) {
        {
            int count = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    ++count;
                    --i;
                } else {
                    if (count > 0) {
                        --i;
                        --count;
                    } else break;
                }
            }
        }

        {
            int count = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    ++count;
                    --j;
                } else {
                    if (count > 0) {
                        --j;
                        --count;
                    } else break;
                }
            }
        }

        if (i < 0 || j < 0) break;
        if (s[i] != t[j]) return false;
        --i;
        --j;
    }

    if (i == -1 && j == -1) return true;
    return false;
}

/// 2390
// You are given a string s, which contains stars *.
//
// In one operation, you can:
//
//    Choose a star in s.
//    Remove the closest non-star character to its left, as well as remove the star itself.
//
// Return the string after all stars have been removed.

//Example 1:
//
//Input: s = "leet**cod*e"
//Output: "lecoe"
//Explanation: Performing the removals from left to right:
//- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
//- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
//- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
//There are no more stars, so we return "lecoe".
//
//Example 2:
//
//Input: s = "erase*****"
//Output: ""
//Explanation: The entire string is removed, so we return an empty string.

std::string lc2390(std::string s) {
    if (s.size() == 1) return s;
    std::string output;
    int n = s.size() - 1;
    int count = 0;
    while (n >= 0) {
        if (s[n] != '*' && count == 0) {
            output.push_back(s[n]);
            --n;
            continue;
        }

        if (s[n] == '*') {
            ++count;
            --n;
        } else {
            if (count > 0) {
                --count;
                --n;
            }
        }
    }
    std::reverse(output.begin(), output.end());
    return output;
}


