//
// Created by zhangjiayuan on 23-5-24.
//
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include "Util.h"
#include <set>
#include <unordered_set>
#include <numeric>

using namespace std;
/// Array String
// 55. Jump Game
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//
//Return true if you can reach the last index, or false otherwise.
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//Example 2:
//
//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
//
// [2,5，0,0]
bool canJump12(std::vector<int>& nums) {
    if (nums.size() == 1) return true;
    int cover = 0;
    for (int i = 0; i <= cover; ++i) {
        cover = std::max(cover, i + nums[i]);
        if (cover >= nums.size() - 1) return true;
    }
    return false;
}

// 45. Jump Game II
//You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
//
//Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
//
//    0 <= j <= nums[i] and
//    i + j < n
//
//Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
//
//
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//Example 2:
//
//Input: nums = [2,3,0,1,4]
//Output: 2

// [7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]
int jump2(std::vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int count = 0;
    int cur = 0;
    int next = 0;
    for (int i = 0; i < nums.size(); ++i) {
        next = std::max(i + nums[i], next);
        if (i == cur) {
            cur = next;
            ++count;
            if (cur >= nums.size() - 1) break;
        }
    }
    return count;
}


// 151. Reverse Words in a String
//Given an input string s, reverse the order of the words.
//
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//
//Return a string of the words in reverse order concatenated by a single space.
//
//Note that s may contain leading or trailing spaces or multiple spaces between two words.
//The returned string should only have a single space separating the words. Do not include any extra spaces.
//
//Example 1:
//
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//
//Example 2:
//
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//
//Example 3:
//
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
//
std::string reverseWords(std::string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        std::swap(s[i++], s[j--]);
    }

    // left strip
    int k = 0;
    while (s[k] == ' ') ++k;
    s.erase(s.begin(), s.begin() + k);

    // right strip
    k = 0;
    while (s[s.size() - 1 - k] == ' ') ++k;
    s.erase(s.end() - k, s.end());

    i = 0, j = 0;
    for (int k = 0; k < s.size() - 1; ++k) {
        if (s[k] == ' ' && s[k + 1] == ' ')  {
            ++k;
        }
    }

    i = 0, j = 0;
    for (auto elem: s) {
        if (elem == ' ') {
            std::reverse(s.begin() + i, s.begin() + i + j);
            j += 2;
            i = j;
            continue;
        }
        ++j;
    }
    return s;
}

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
    int low = INT32_MAX;
    int result = 0;
    for (int i = 0; i < prices.size(); i++) {
        low = min(low, prices[i]);  // 取最左最小价格
        result = max(result, prices[i] - low); // 直接取最大区间利润
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

// 28. Find the Index of the First Occurrence in a String
//
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//
//
//Example 1:
//
//Input: haystack = "sadbutsad", needle = "sad"
//Output: 0
//Explanation: "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
//
//Example 2:
//
//Input: haystack = "leetcode", needle = "leeto"
//Output: -1
//Explanation: "leeto" did not occur in "leetcode", so we return -1.
//

int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    if (haystack.empty()) return -1;

    int left = 0, right = 0;
    int index = -1;
    while (left < haystack.size()) {
        auto tmp_left = left;
        while (haystack[tmp_left] == needle[right]) {
            tmp_left++;
            right++;
        }
        if (right == needle.size()) {
            return left;
        }
        right = 0;
        ++left;
    }
    return index;
}

/// Two pointers
//392. Is Subsequence
//
//Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//
//
//
//Example 1:
//
//Input: s = "abc", t = "ahbgdc"
//Output: true
//
//Example 2:
//
//Input: s = "axc", t = "ahbgdc"
//Output: false

bool isSubsequence(string s, string t) {
    if (s.empty()) return true;
    if (t.empty()) return false;

    int l = 0, r = 0;
    while (l < s.size() && r < t.size()) {
        if (t[r] == s[l]) {
            ++l;
        }
        ++r;
    }
    return l == s.size();
}

/// Sliding window
/// Matrix
// 36. Valid Sudoku
//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//    Each row must contain the digits 1-9 without repetition.
//    Each column must contain the digits 1-9 without repetition.
//    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
//Note:
//
//    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//    Only the filled cells need to be validated according to the mentioned rules.
//
//
//
//Example 1:
//
//Input: board =
//[["5","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//Output: true
//
//Example 2:
//
//Input: board =
//[["8","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//Output: false
//Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
bool isValidSudoku(vector<vector<char>>& board) {
    std::vector<int> row(9, 0);
    std::vector<int> col(9, 0);
    std::vector<int> box(9, 0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;

            int elem = board[i][j] - '0';
            int pos = 1 << (elem - 1);

            if ((row[i] & pos) > 0) {
                return false;
            }
            row[i] |= pos;

            if ((col[j] & pos) > 0) {
                return false;
            }
            col[j] |= pos;

            auto k = (i / 3) * 3 + j / 3;
            if ((box[k] & pos) > 0) {
                return false;
            }
            box[k] |= pos;
        }
        row.clear();
    }
    return true;
}

/// HashMap
// 128. Longest Consecutive Sequence
//
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//
//You must write an algorithm that runs in O(n) time.
//
//
//
//Example 1:
//
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
//Example 2:
//
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
// 1 2 3 4 5 8 10 11 12 13 14 15
int longestConsecutive(std::vector<int>& nums) {
    if (nums.size() == 1) return 1;
    std::set<int> s;
    for (auto& elem: nums) {
        s.insert(elem);
    }

    int output = 0;
    for (const auto &elem: s) {
        if (!s.count(elem - 1)) {
            int var = 1;
            int tmp = elem;
            while (s.count(tmp + 1)) {
                ++var;
                ++tmp;
            }
            output = std::max(output, var);
        }
    }
    return output;
}
//
//    Time complexity : O(n)
//
//    Although the time complexity appears to be quadratic due to the while
//    loop nested within the for loop, closer inspection reveals it to be
//    linear. Because the while loop is reached only when currentNum marks
//    the beginning of a sequence (i.e. currentNum-1 is not present in
//    nums), the while loop can only run for n iterations throughout the
//    entire runtime of the algorithm. This means that despite looking like
//    O(n⋅n) complexity, the nested loops actually run in O(n+n)=O(n)
//    time. All other computations occur in constant time, so the overall
//    runtime is linear.
//
//    Space complexity : O(n)
//
//    In order to set up O(1) containment lookups, we allocate linear space
//    for a hash table to store the O(n) numbers in nums. Other than that,
//    the space complexity is identical to that of the brute force solution.
//
//
//
// 205. Isomorphic Strings
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
//
//
//
//Example 1:
//
//Input: s = "egg", t = "add"
//Output: true
//
//Example 2:
//
//Input: s = "foo", t = "bar"
//Output: false
//
//Example 3:
//
//Input: s = "paper", t = "title"
//Output: true
// "badc"
// "baba"
bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) return false;
    std::map<char, char> m;
    std::unordered_set<char> sets;
    for (int i = 0; i < s.size(); ++i) {
        if (m.find(s[i]) == m.end() && sets.find(t[i]) != sets.end()) {
            return false;
        }

        if (m.find(s[i]) != m.end() && m[s[i]] != t[i]) {
            return false;
        }
        m[s[i]] = t[i];
        sets.insert(t[i]);
    }
    return true;
}

// 290. Word Pattern
//Given a pattern and a string s, find if s follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
//
//Example 1:
//
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//
//Example 2:
//
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//
//Example 3:
//
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false

std::string findString(std::string s, int spaceCount) {
    int i = 0;
    while (spaceCount != 0) {
        if (s[i] == ' ') {
            --spaceCount;
        }
        ++i;
    }

    auto j = i;
    while (s[j] != ' ') {
        ++j;
    }
    return s.substr(i, j);
}

bool wordPattern(std::string pattern, std::string s) {
    int countSpace = 1;
    for (auto& elem: s) {
        if (elem == ' ') ++countSpace;
    }
    if (countSpace != pattern.size()) return false;
    std::map<char, std::string> m;
    std::unordered_set<std::string> sets;

    for (int i = 0; i < pattern.size(); ++i) {
        auto tmp = findString(s, i);
        if (m.find(pattern[i]) == m.end() && sets.find(tmp) != sets.end()) {
            return false;
        }

        if (m.find(pattern[i]) != m.end() && m[pattern[i]] != tmp) {
            return false;
        }
        m[pattern[i]] = tmp;
        sets.insert(tmp);
    }
    return true;
}

/// Intervals
/// Stack

/// TODO
// 224. Basic Calculator
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
//
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
//
// Example 1:
//
// Input: s = "1 + 1"
// Output: 2
//
// Example 2:
//
// Input: s = " 2-1 + 2 "
// Output: 3
//
// Example 3:
//
// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

// (3 + ( 3 - 2))
//  ))2 - 3 ( + 3 (
// 4
int calculate(std::string s) {
    int output = 0;
    std::stack<char> stack1;
    std::reverse(s.begin(), s.end());
    for (auto& elem: s) {
        if (elem == ')') {
            if (stack1.top() == '(') {
                stack1.pop();
                continue;
            }

        }
    }
}

// 150. Evaluate Reverse Polish Notation
//  You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//
//  Evaluate the expression. Return an integer that represents the value of the expression.
//
//  Note that:
//
//      The valid operators are '+', '-', '*', and '/'.
//      Each operand may be an integer or another expression.
//      The division between two integers always truncates toward zero.
//      There will not be any division by zero.
//      The input represents a valid arithmetic expression in a reverse polish notation.
//      The answer and all the intermediate calculations can be represented in a 32-bit integer.
//
//  Example 1:
//
//  Input: tokens = ["2","1","+","3","*"]
//  Output: 9
//  Explanation: ((2 + 1) * 3) = 9
//
//  Example 2:
//
//  Input: tokens = ["4","13","5","/","+"]
//  Output: 6
//  Explanation: (4 + (13 / 5)) = 6
//
//  Example 3:
//
//  Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//  Output: 22
//  Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//  = ((10 * (6 / (12 * -11))) + 17) + 5
//  = ((10 * (6 / -132)) + 17) + 5
//  = ((10 * 0) + 17) + 5
//  = (0 + 17) + 5
//  = 17 + 5
//  = 22
int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> s;
    for (auto& elem: tokens) {
        if (elem == "+" || elem == "-" || elem == "*" || elem == "/") {
            auto val1 = s.top();
            s.pop();
            auto val2 = s.top();
            s.pop();
            if (elem == "+") s.push(val2 + val1);
            if (elem == "-") s.push(val2 - val1);
            if (elem == "*") s.push(val2 * val1);
            if (elem == "/") s.push(val2 / val1);
        } else {
            s.push(std::stoi(elem));
        }
    }
    return s.top();
}

// 155. Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// Implement the MinStack class:
//
//     MinStack() initializes the stack object.
//     void push(int val) pushes the element val onto the stack.
//     void pop() removes the element on the top of the stack.
//     int top() gets the top element of the stack.
//     int getMin() retrieves the minimum element in the stack.
//
// You must implement a solution with O(1) time complexity for each function.
//
//
//
// Example 1:
//
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
//
// Output
// [null,null,null,null,-3,null,0,-2]
//
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
class MinStack {
public:
    MinStack() {
        s2.push(INT32_MAX);
    }

    void push(int val) {
        s1.push(val);
        if (s2.top() >= val) s2.push(val);
    }

    void pop() {
        if (s2.top() == s1.top()) s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
private:
    std::stack<int> s1;
    std::stack<int> s2;
};

/// 71 TODO
//  71. Simplify Path
//  Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
//  The canonical path should have the following format:
//
//      The path starts with a single slash '/'.
//      Any two directories are separated by a single slash '/'.
//      The path does not end with a trailing '/'.
//      The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
//
//  Return the simplified canonical path.
//
//  Example 1:
//
//  Input: path = "/home/"
//  Output: "/home"
//  Explanation: Note that there is no trailing slash after the last directory name.
//
//  Example 2:
//
//  Input: path = "/../"
//  Output: "/"
//  Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
//
//  Example 3:
//
//  Input: path = "/home//foo/"
//  Output: "/home/foo"
//  Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

// "/a/./b/../../c/"
// "/a/b/../../c"
// "/c"

// "/."
// "/"

// "/.."
// "/"

//  In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level,
//  and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.
//  For this problem, any other format of periods such as '...' are treated as file/directory names.
std::string simplifyPath(std::string path) {
    std::string output;
    std::stack<int> s;
    for (auto& elem: path) {
        if (!s.empty() && s.size() == 2 && elem == '.' && s.top() == '.') {
            s.pop();
            s.pop();
            continue;
        }

        if (!s.empty() && s.size() > 1 && elem == '.' && s.top() == '.') {
            s.pop();
            s.pop();
            s.pop();
            continue;
        }
        if (!s.empty() && elem == '/' && s.top() == '/') {
            continue;
        }

        if (!s.empty() && elem == '/' && s.top() == '.') {
            s.pop();
            continue;
        }
        s.push(elem);
    }

    if (s.empty()) return "/";
    if (s.top() == '/' && s.size() > 1) s.pop();
    if (s.top() == '.' && s.size() > 1) s.pop();

    while (!s.empty()) {
        output += s.top();
        s.pop();
    }
    std::reverse(output.begin(), output.end());
    return output;
}

// 20. Valid Parentheses
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//    Open brackets must be closed by the same type of brackets.
//    Open brackets must be closed in the correct order.
//    Every close bracket has a corresponding open bracket of the same type.
//
//Example 1:
//
//Input: s = "()"
//Output: true
//
//Example 2:
//
//Input: s = "()[]{}"
//Output: true
//
//Example 3:
//
//Input: s = "(]"
//Output: false
// "({[)"
bool isValid(std::string s) {
    std::stack<char> stack;
    for (auto& elem: s) {
        if (!stack.empty()) {
            if ((stack.top() == '(' && elem == ')') || (stack.top() == '[' && elem == ']') || (stack.top() == '{' && elem == '}')) {
                stack.pop();
                continue;
            }
        }
        stack.push(elem);
    }
    return stack.empty();
}
/// Link List
// 82. Remove Duplicates from Sorted List II
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
//
//
//
//Example 1:
//
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
//
//Example 2:
//
//Input: head = [1,1,1,2,3]
//Output: [2,3]
//
//Example 3:
//
//Input: head = [1,1,1,2,2,2,3]
//Output: [3]
//
//Input: head = [1,2,3,4,4,4,5,6]
//Output: [3]
struct ListNode {
    ListNode* next;
    double val;
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    auto dummyHead = new ListNode();
    dummyHead->next = head;
    auto slow = head;
    auto fast = head->next;
    auto prev = dummyHead;

    while (slow->val == fast->val) {
        fast = fast->next;
        if (fast == nullptr) return nullptr;
        if (fast->val != slow->val) {
            while (slow != fast) {
                auto tmp = slow;
                slow = slow->next;
                delete tmp;
            }
            fast = fast->next;
            prev->next = slow;
        }
    }

    while (fast != nullptr) {
        while (slow->val != fast->val) {
            slow = slow->next;
            fast = fast->next;
            prev = prev->next;
        }
        while (slow->val == fast->val) {
            fast = fast->next;
            if (fast == nullptr || fast->val != slow->val) {
                while (slow != fast) {
                    auto tmp = slow;
                    slow = slow->next;
                    delete tmp;
                }
                if (fast != nullptr) fast = fast->next;
                prev->next = slow;
                if (slow == nullptr) break;
            }
        }
    }
    return dummyHead->next;
}

// 138. Copy List with Random Pointer
//
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
//
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer
// of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
//
// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
//
// Return the head of the copied linked list.
//
// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
//
//     val: an integer representing Node.val
//     random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
//
// Example 1:
//
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
//
// Example 2:
//
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
//
// Example 3:
//
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]




class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

std::unordered_map<Node*, Node*> cacheMap;
Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    if (!cacheMap.count(head)) {
        auto N = new Node(head->val);
        cacheMap[head] = N;
        N->next = copyRandomList(head->next);
        N->random = copyRandomList(head->random);
    }
    return cacheMap[head];
}

Node* copyRandomList2(Node* head) {
    std::unordered_map<Node*, Node*> cacheMap;
    auto tmp = head;
    while (tmp != nullptr) {
        auto N = new Node(tmp->val);
        cacheMap[tmp] = N;
        tmp = tmp->next;
    }

    tmp = head;
    while (tmp != nullptr) {
        cacheMap[tmp]->next = cacheMap[tmp->next];
        cacheMap[tmp]->random = cacheMap[tmp->random];
        tmp = tmp->next;
    }
    return cacheMap[head];
}

Node* copyRandomList3(Node* head) {
    auto tmp = head;
    while (tmp->next != nullptr) {
        auto N = new Node(tmp->val);
        N->next = tmp->next->next;
        tmp->next = N;
        tmp = tmp->next->next;
    }

    tmp = head;
    while (tmp->next != nullptr) {
        tmp->next->random = tmp->random->next;
        tmp = tmp->next->next;
    }

    tmp = head;
    auto head_new = tmp->next;
    while (tmp->next != nullptr) {
        tmp->next->next = tmp->next->next->next;
        tmp->next = tmp->next->next;
        tmp = tmp->next->next;
    }
    tmp->next = nullptr;
    return head_new;
}


/// Binary Tree
/// BFS
// 103. Binary Tree Zigzag Level Order Traversal
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
//Example 1:
//
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[20,9],[15,7]]
//
//Example 2:
//
//Input: root = [1]
//Output: [[1]]
//
//Example 3:
//
//Input: root = []
//Output: []

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::queue<TreeNode*> q;
    std::vector<std::vector<int>> output;
    if (root == nullptr) return output;
    q.push(root);
    int c = 0;
    while (!q.empty()) {
        std::vector<int> a;
        int size = q.size();
        while (size) {
            auto t = q.front();
            q.pop();
            a.push_back(t->val);
            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
            --size;
            ++c;
        }
        if (c % 2 == 0) std::reverse(a.begin(), a.end());
        output.push_back(a);
    }
    return output;
}

std::vector<std::vector<int>> LevelOrder(TreeNode* root) {
    std::queue<TreeNode*> q;
    std::vector<std::vector<int>> output;
    if (root == nullptr) return output;
    q.push(root);
    while (!q.empty()) {
        std::vector<int> a;
        int size = q.size();
        while (size) {
            auto t = q.front();
            q.pop();
            a.push_back(t->val);
            if (t->left != nullptr) q.push(t->left);
            if (t->right != nullptr) q.push(t->right);
            --size;
        }
        output.push_back(a);
    }
    return output;
}



/// Binary search tree
/// Graph General
/// Graph BFS
/// Trie
// 208. Implement Trie (Prefix Tree)
//
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
// There are various applications of this data structure, such as autocomplete and spellchecker.
// Implement the Trie class:
//
//    Trie() Initializes the trie object.
//    void insert(String word) Inserts the string word into the trie.
//    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
//    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
//
// Example 1:
//
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]
//
// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

class Trie {
public:
    class TrieNode {
    public:
        bool _isLeaf{};
        std::map<char, TrieNode*> _sonMap;
    };

    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        auto tmp = root;
        for (auto& elem: word) {
            if (tmp->_sonMap.find(elem) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[elem];
                continue;
            }
            tmp->_sonMap[elem] = new TrieNode();
            tmp = tmp->_sonMap[elem];
        }
        tmp->_isLeaf = true;
    }

    bool search(std::string word) {
        auto tmp = root;
        for (auto& elem: word) {
            if (tmp->_sonMap.find(elem) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[elem];
            } else {
                return false;
            }
        }
        return tmp->_isLeaf;
    }

    bool startsWith(std::string prefix) {
        auto tmp = root;
        for (auto& elem: prefix) {
            if (tmp->_sonMap.find(elem) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[elem];
            } else {
                return false;
            }
        }
        return true;
    }

    TrieNode* root;
};

// 211. Design Add and Search Words Data Structure
// Design a data structure that supports adding new words and finding if a string matches any previously added string.
//
// Implement the WordDictionary class:
//
//     WordDictionary() Initializes the object.
//     void addWord(word) Adds word to the data structure, it can be matched later.
//     bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
//
// Example:
//
// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]
//
// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True

class WordDictionary {
public:
    class TrieNode {
    public:
        bool _isLeaf{};
        std::map<char, TrieNode*> _sonMap;
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(std::string word) {
        auto tmp = root;
        for (auto& elem: word) {
            if (tmp->_sonMap.find(elem) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[elem];
                continue;
            }
            tmp->_sonMap[elem] = new TrieNode();
            tmp = tmp->_sonMap[elem];
        }
        tmp->_isLeaf = true;
    }

    bool searchHelper(std::string word, TrieNode* inNode) {
        for (int i = 0; i <  word.size(); ++i) {
            auto elem = word[i];
            if (inNode->_sonMap.find(elem) != inNode->_sonMap.end()) {
                inNode = inNode->_sonMap[elem];
            } else {
                if (elem == '.') {
                    vector<char> keys;
                    for(auto & itr : inNode->_sonMap)
                        keys.push_back(itr.first);

                    for (auto val: keys)
                        if (searchHelper(val + word.substr(i + 1, word.size()), inNode))
                            return true;
                }
                return false;
            }
        }
        return inNode->_isLeaf;
    }

    bool search(std::string word) {
        WordDictionary();
        return searchHelper(word, root);
    }

};



/// Backtracking
// 22. Generate Parentheses
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
//Example 1:
//
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//
//Example 2:
//
//Input: n = 1
//Output: ["()"]

class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

/// Divide & Conquer
// 148. Sort List
//
//Given the head of a linked list, return the list after sorting it in ascending order.
//
//
//
//Example 1:
//
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//
//Example 2:
//
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
//
//Example 3:
//
//Input: head = []
//Output: []

//ListNode* at(ListNode* head, int index) {
//    auto tmp = head;
//    while (index != 0) {
//        tmp = tmp->next;
//        --index;
//    }
//    return tmp;
//}
//
//void myMerge(ListNode* head, int left, int mid, int right) {
//    ListNode* dummyTmpHead = new ListNode();
//    auto tmp = dummyTmpHead;
//    int i = left, j = mid + 1;
//    int k = 0;
//    while (i <= mid && j <= right) {
//        int val1 = at(head, i)->val;
//        int val2 = at(head, j)->val;
//        if (val1 <= val2) {
//            tmp->val = val1;
//            ++i;
//        } else {
//            tmp->val = val2;
//            ++j;
//        }
//
//        if (i <= mid || j <= right) {
//            tmp->next = new ListNode();
//            tmp = tmp->next;
//        }
//        ++k;
//    }
//
//    if (i <= mid) tmp->next = at(head, i);
//    if (j <= right) tmp->next = at(head, j);
//
//    tmp = dummyTmpHead;
//    auto tmpHead = head;
//    while (left != 0) {
//        tmpHead = tmpHead->next;
//        --left;
//    }
//
//    for (int w = 0; w < k; ++w) {
//        tmpHead->val = tmp->val;
//        tmpHead = tmpHead->next;
//        tmp = tmp->next;
//    }
//}
//
////Input: head = [4,2,1,3]
//
//void mySort(ListNode* head, int left, int right) {
//    if (left < right) {
//        int mid = (left + right) / 2;
//        mySort(head, left, mid);
//        mySort(head, mid + 1, right);
//        myMerge(head, left, mid, right);
//    }
//}
//
//
//ListNode* sortList(ListNode* head) {
//    if (head == nullptr) return nullptr;
//    int left = 0, right = -1;
//    auto tmp = head;
//    while (tmp != nullptr) {
//        tmp = tmp->next;
//        ++right;
//    }
//    mySort(head, left, right);
//    return head;

ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* dummyHead = new ListNode();
    ListNode* ptr = dummyHead;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if(list1) ptr->next = list1;
    else ptr->next = list2;
    return dummyHead->next;
}

ListNode* getMid(ListNode* head) {
    ListNode* midPrev = nullptr;
    while (head && head->next) {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
}



/// Kadane's Algorithm

// 53. Maximum Subarray
//Given an integer array nums, find the
//subarray
//with the largest sum, and return its sum.
//
//
//
//Example 1:
//
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: The subarray [4,-1,2,1] has the largest sum 6.
//
//Example 2:
//
//Input: nums = [1]
//Output: 1
//Explanation: The subarray [1] has the largest sum 1.
//
//Example 3:
//
//Input: nums = [5,4,-1,7,8]
//Output: 23
//Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

int maxSubArray(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = std::max(dp[i - 1], 0) + nums[i];
    }
    return *std::max(dp.begin(), dp.end());
}

int maxSubArrayOptimized(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int dp0 = nums[0];
    int dp2 = nums[0];
    int dp1 = 0;
    for (int i = 1; i < n; ++i) {
        dp1 = std::max(dp0, 0) + nums[i];
        dp0 = dp1;
        dp2 = std::max(dp2, dp1);
    }
    return dp2;
}

// 918. Maximum Sum Circular Subarray
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
//
//Example 1:
//
//Input: nums = [1,-2,3,-2]
//Output: 3
//Explanation: Subarray [3] has maximum sum 3.
//
//Example 2:
//
//Input: nums = [5,-3,5]
//Output: 10
//Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
//
//Example 3:
//
//Input: nums = [-3,-2,-3]
//Output: -2
//Explanation: Subarray [-2] has maximum sum -2.
// [1, 2, 3, 4, 5]

// [1,-2,3,-2]
int maxSubarraySumCircular(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int ans1;
    {
        int dp0 = nums[0];
        int dp2 = nums[0];
        int dp1 = 0;
        for (int i = 1; i < n; ++i) {
            dp1 = std::max(dp0, 0) + nums[i];
            dp0 = dp1;
            dp2 = std::max(dp2, dp1);
        }
        ans1 = dp2;
    }
    if (n == 2) return ans1;

    int ans2;
    {
        int dp0 = 0;
        int dp2 = 0;
        int dp1 = 0;
        for (int i = 1; i < n - 1; ++i) {
            dp1 = std::min(dp0, 0) + nums[i];
            dp0 = dp1;
            dp2 = std::min(dp2, dp1);
        }
        ans2 = std::accumulate(nums.begin(), nums.end(), 0) - dp2;
    }
    return std::max(ans1, ans2);
}

//int maxSubarraySumCircular(std::vector<int>& A) {
//    int n = A.size();
//    if(n == 1) return A[0];
//    // 单区间最大子段和
//    int sum = A[0], sum1 = A[0], ans1 = A[0];
//    for(int i = 1; i < n; ++i)
//    {
//        sum += A[i];
//        sum1 = A[i] + max(sum1, 0);
//        ans1 = max(ans1, sum1);
//    }
//    if(n == 2) return ans1;
//    // 双区间的最大字段和
//    int sum2 = A[1], ans2 = A[1];
//    for(int i = 1; i < n - 1; ++i)
//    {
//        sum2 = A[i] + min(sum2, 0);
//        ans2 = min(ans2, sum2);
//    }
//    ans2 = sum - ans2;
//    return max(ans1, ans2);
//}

/// Binary Search

// 35. Search Insert Position
//
//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You must write an algorithm with O(log n) runtime complexity.
//
//
//
//Example 1:
//
//Input: nums = [1,3,5,6], target = 5
//Output: 2
//
//Example 2:
//
//Input: nums = [1,3,5,6], target = 2
//Output: 1
//
//Example 3:
//
//Input: nums = [1,3,5,6], target = 7
//Output: 4

bool binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) right = mid -1;
        else left = mid + 1;
    }
    return left;
}

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 74. Search a 2D Matrix
//You are given an m x n integer matrix matrix with the following two properties:
//
//    Each row is sorted in non-decreasing order.
//    The first integer of each row is greater than the last integer of the previous row.
//
//Given an integer target, return true if target is in matrix or false otherwise.
//
//You must write a solution in O(log(m * n)) time complexity.
//
//
//
//Example 1:
//
//Input: matrix =
// [[1,3,5,7],
// [10,11,16,20],
// [23,30,34,60]], target = 3
//Output: true
//
//Example 2:
//
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
//
//
//
//Constraints:
//
//    m == matrix.length
//    n == matrix[i].length
//    1 <= m, n <= 100
//    -104 <= matrix[i][j], target <= 104

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (m == 0 && n == 0) return false;
    int left = 0, right = n * m - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        auto val = matrix[mid / m][mid % m];
        if (target == val) {
            return true;
        } else if (target < val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

// 162. Find Peak Element
//A peak element is an element that is strictly greater than its neighbors.
//
//Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
//
//You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
//
//You must write an algorithm that runs in O(log n) time.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,1]
//Output: 2
//Explanation: 3 is a peak element and your function should return the index number 2.
//
//Example 2:
//
//Input: nums = [1,2,1,3,5,6,4]
//Output: 5
//Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
//

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (nums.empty()) return -1;
    if (n == 1) return 0;
    if (n == 2) return (nums[0] > nums[1]) ? 0 : 1;

    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid == 0) {
            if (n >= 2 && nums[mid] > nums[mid + 1]) {
                return mid;
            }
        }

        if (mid == n - 1) {
            if (n >= 2 && nums[mid] > nums[mid - 1]) {
                return mid;
            }
        }

        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
            return mid;
        } else if (nums[mid] < nums[mid + 1]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

// 33. Search in Rotated Sorted Array
//
//There is an integer array nums sorted in ascending order (with distinct values).
//
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//
//You must write an algorithm with O(log n) runtime complexity.
//
//
//
//Example 1:
//
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
//
//Example 2:
//
//Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
//
//Example 3:
//
//Input: nums = [1], target = 0
//Output: -1
//
int search(vector<int>& nums, int target) {
    if (nums.size() == 1) return nums[0] == target;
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (l <= r) {
        m = (l + r) / 2;
        if (nums[m] == target) {
            return m;
        }

        if (nums[l] == target) {
            return l;
        }

        if (nums[r] == target) {
            return r;
        }

        if (nums[m] > nums[l]) {
            if (nums[m] > target && target > nums[l]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (nums[m] < target && target < nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    return -1;
}

// 34. Find First and Last Position of Element in Sorted Array
//
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//
//If target is not found in the array, return [-1, -1].
//
//You must write an algorithm with O(log n) runtime complexity.
//
//
//
//Example 1:
//
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//
//Example 2:
//
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//
//Example 3:
//
//Input: nums = [], target = 0
//Output: [-1,-1]
//
//Input: nums = [5,7,8,8,8,10], target = 8
//Output: [2,4]

int search(std::vector<int>& nums, int target, bool isLeft) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {

            if (isLeft) {
                if (m != 0 && nums[m - 1] == target) {
                    r = m - 1;
                } else {
                    return m;
                }
            } else {
                if (m != nums.size() - 1 && nums[m + 1] == target) {
                    l = m + 1;
                } else {
                    return m;
                }
            }

        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> output = {-1, -1};
    if (nums.empty()) return output;
    int l = search(nums, target, true);
    int r = search(nums, target, false);
    output[0] = l;
    output[1] = r;
    if (l == -1 && r != -1) {
        output[0] = r;
        output[1] = -1;
    }
    return output;
}

// 153. Find Minimum in Rotated Sorted Array
//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//
//    [4,5,6,7,0,1,2] if it was rotated 4 times.
//    [0,1,2,4,5,6,7] if it was rotated 7 times.
//
//Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//
//Given the sorted rotated array nums of unique elements, return the minimum element of this array.
//
//You must write an algorithm that runs in O(log n) time.
//
//
//
//Example 1:
//
//Input: nums = [3,4,5,1,2]
//Output: 1
//Explanation: The original array was [1,2,3,4,5] rotated 3 times.
//
//Example 2:
//
//Input: nums = [4,5,6,7,0,1,2]
//Output: 0
//Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
//
//Example 3:
//
//Input: nums = [11,13,15,17]
//Output: 11
//Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
//

int findMin(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        }
        else if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            break;
        }
    }
    return nums[left];
}

// 4. Median of Two Sorted Arrays
/// ???????????????????????
//
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
//The overall run time complexity should be O(log (m+n)).
//
//
//
//Example 1:
//
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//
//Example 2:
//
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// mergeSort
// time: O(n + m)
// space: O(1)
class Solution4 {
public:
    int p1 = 0, p2 = 0;

    // Get the smaller value between nums1[p1] and nums2[p2] and move the pointer forward.

    int getMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());

        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }

        return -1;
    }
};

/// Heap

// 215. Kth Largest Element in an Array
// Given an integer array nums and an integer k, return the kth largest element in the array.
//
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// You must solve it in O(n) time complexity.
//
// Example 1:
//
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
//
// Example 2:
//
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

int findKthLargest(std::vector<int>& nums, int k) {
    // default max heap
    std::priority_queue<int> pq(nums.begin(), nums.end());
    while (k != 1) {
        pq.pop();
        --k;
    }
    return pq.top();
}


// 295. Find Median from Data Stream
//
//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
//
//    For example, for arr = [2,3,4], the median is 3.
//    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
//
//Implement the MedianFinder class:
//
//    MedianFinder() initializes the MedianFinder object.
//    void addNum(int num) adds the integer num from the data stream to the data structure.
//    double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
//
//
//
//Example 1:
//
//Input
//["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
//[[], [1], [2], [], [3], []]
//Output
//[null, null, null, 1.5, null, 2.0]
//
//Explanation
//MedianFinder medianFinder = new MedianFinder();
//medianFinder.addNum(1);    // arr = [1]
//medianFinder.addNum(2);    // arr = [1, 2]
//medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
//medianFinder.addNum(3);    // arr[1, 2, 3]
//medianFinder.findMedian(); // return 2.0
//
//
//
//Constraints:
//
//    -105 <= num <= 105
//    There will be at least one element in the data structure before calling findMedian.
//    At most 5 * 104 calls will be made to addNum and findMedian.
//
//
//
//Follow up:
//
//    If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
//    If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

// find max/min time complexity O(1)
// insertion/deletion time complexit O(logn)

// vector
// sorted O(NlogN)
// find max/min O(n)
// insertion/deletion O(n)

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        return (left.size() != right.size()) ? left.top() : (left.top() + right.top()) / 2.0;
    }

private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, less<>> right;
};

// 502. IPO
//
//Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO.
// Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
//
//You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
//
//Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
//
//Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
//
//The answer is guaranteed to fit in a 32-bit signed integer.
//
//
//
//Example 1:
//
//Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
//Output: 4
//Explanation: Since your initial capital is 0, you can only start the project indexed 0.
//After finishing it you will obtain profit 1 and your capital becomes 1.
//With capital 1, you can either start the project indexed 1 or the project indexed 2.
//Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
//Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
//
//Example 2:
//
//Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
//Output: 6

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

}

class Solution502 {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<>> pq;
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(capital[i], profits[i]);
        }
        sort(arr.begin(), arr.end());//以first为准排序arr，默认为升序，即需求资本从小到大
        //大循环：投资k个项目
        for (int i = 0; i < k; ++i) {
            //将需求资本小于等于已有资本的项目的利润压入大顶堆
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }
        return w;
    }
};

// 373. Find K Pairs with Smallest Sums
//
//You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
//
//Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//
//Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
//
//
//
//Example 1:
//
//Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//Output: [[1,2],[1,4],[1,6]]
//Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
//Example 2:
//
//Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//Output: [[1,1],[1,1]]
//Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//Example 3:
//
//Input: nums1 = [1,2], nums2 = [3], k = 3
//Output: [[1,3],[2,3]]
//Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto comp = [](vector<int> &p1, vector<int> &p2) {
        return p1[0] + p1[1] < p2[0] + p2[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    for (auto x: nums1) {
        for (auto y: nums2) {
            pq.push({x, y});
            if (pq.size() > k) pq.pop();
        }
    }
    vector<vector<int>> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

/// Bit Manipulation
// 201. Bitwise AND of Numbers Range
//
//Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
//
//Example 1:
//
//Input: left = 5, right = 7
//Output: 4
//
//Example 2:
//
//Input: left = 0, right = 0
//Output: 0
//
//Example 3:
//
//Input: left = 1, right = 2147483647
//Output: 0

int rangeBitwiseAnd(int left, int right) {
    if (left == right) return left;
    if (left == 0 || right == 0) return 0;
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }
    return left << shift;
}

/// Math
// 172. Factorial Trailing Zeroes
// Given an integer n, return the number of trailing zeroes in n!.
//
// Example 1:
//
// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
//
// Example 2:
//
// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
//
// Example 3:
//
// Input: n = 0
// Output: 0

int math172(int n) {
    int count2 = 0;
    for (int i = 1; i <= n; ++i) {
        auto tmp = i;
        while (tmp % 2 == 0) {
            count2++;
            tmp /= 2;
        }
    }
    int count5 = 0;
    for (int i = 1; i <= n; ++i) {
        auto tmp = i;
        while (tmp % 5 == 0) {
            count5++;
            tmp /= 5;
        }
    }
    return std::min(count2, count5);
}
// 30
// O(log(n)), O(1)
int math172Optimized(int n) {
    int count = 0;
    int k = 5;
    while (n >= k) {
        count += n / k;
        k *= 5;
    }
    return count;
}

//  149. Max Points on a Line
//
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
//
//Example 1:
//
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//
//Example 2:
//
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
int maxPoints(vector<vector<int>>& points) {
    auto n = points.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int max = 0;
    for (int i = 0; i < n; ++i) {
        std::map<double, int> mp;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            auto angle = std::atan2(points[j][1] - points[i][1], points[j][0] - points[i][0]);
            mp[angle]++;
        }

        for (auto elem: mp) {
            max = std::max(elem.second, max);
        }
    }
    return max;
}

/// 1D DP
// 322 coin change
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.
//
// Example 1:
// 0 1 2 3 4 5
// 0 1 1     1
//
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
//
// Input: coins = [2], amount = 3
// Output: -1
//
// Example 3:
//
// Input: coins = [1], amount = 0
// Output: 0

// Input: coins = [2], amount = 1
// Output: -1

// [278,274,153,490]
// 8633

int coinChange(std::vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    std::vector<int> dp(amount + 1, 1e7);
    for (auto& elem: coins) {
        if (elem > amount) continue;
        dp[elem] = 1;
    }

    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        if (dp[i] == 1) continue;
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] >= 1e7 ? -1: dp[amount];
}

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

//  139. Word Break
//  Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//  Note that the same word in the dictionary may be reused multiple times in the segmentation.
//
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet","code"]
//  Output: true
//  Explanation: Return true because "leetcode" can be segmented as "leet code".
//
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple","pen"]
//  Output: true
//  Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//  Note that you are allowed to reuse a dictionary word.
//
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//  Output: false
//

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}


/// Multidimensional DP
// 72. Edit Distance
//
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
//
// You have the following three operations permitted on a word:
//
//     Insert a character
//     Delete a character
//     Replace a character
//
//
//
// Example 1:
//
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
// Example 2:
//
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')


int minDistance(std::string word1, std::string word2) {
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int> (word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= word2.size(); ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= word1.size(); ++i) {
        for (int j = 1; j <= word2.size(); ++j) {
            auto left = dp[i - 1][j] + 1;
            auto up = dp[i][j - 1] + 1;
            auto upleft = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
            dp[i][j] = std::min(std::min(left, up), upleft);
        }
    }
    return dp[word1.size()][word2.size()];
}

// 97. Interleaving String
//
//Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
//
//An interleaving of two strings s and t is a configuration where s and t are divided into n and m
//substrings
//respectively, such that:
//
//    s = s1 + s2 + ... + sn
//    t = t1 + t2 + ... + tm
//    |n - m| <= 1
//    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
//
//Note: a + b is the concatenation of strings a and b.
//
//
//
//Example 1:
//
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//Output: true
//Explanation: One way to obtain s3 is:
//Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
//Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
//Since s3 can be obtained by interleaving s1 and s2, we return true.
//
//Example 2:
//
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//Output: false
//Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
//
//Example 3:
//
//Input: s1 = "", s2 = "", s3 = ""
//Output: true

bool isInterLeave(std::string s1, int i, std::string s2, int j, std::string res, std::string s3) {
    if (res == s3 && i == s1.size() && j == s2.size()) return true;
    bool ans = false;

    if (i < s1.size()) {
        ans |= isInterLeave(s1, i + 1, s2, j, res + s1[i], s3);
    }

    if (j < s2.size()) {
        ans |= isInterLeave(s1, i, s2, j + 1, res + s2[j], s3);
    }
    return ans;
}

bool isInterLeave(std::string s1, std::string s2, std::string s3) {
    if ((s1.size() + s2.size()) == s3.size()) return false;
    return isInterLeave(s1, 0, s2, 0, "", s3);
}


void testing123() {
    isValid("({[)");
    simplifyPath("/a/./b/../../c/");
    simplifyPath("/home/");
    simplifyPath("/../");
    simplifyPath("/home//foo/");
    simplifyPath("/.");
    simplifyPath("/..");
    simplifyPath("/../..");
    simplifyPath("/../../..");
    minDistance("ros", "horse");
//    Trie trie;
//    trie.insert("apple");
//    trie.search("apple");   // return True
//    trie.search("app");     // return False
//    trie.startsWith("app"); // return True
//    trie.insert("app");
//    trie.search("app");     // return True
// [278,274,153,490]
// 8633
    std::vector<int> v = {2};
    coinChange(v, 1);

    std::vector<int> h = {3,2,1,5,6,4};
    findKthLargest(h, 2);
    isIsomorphic("badc", "baba");

    std::string s = "leetcode";
    std::vector<std::string> ss = {"leet", "code"};
    wordBreak(s,ss);

    std::vector<int> z = {1,2,3,4,5,8,10,11,12,13, 14, 15};
    longestConsecutive(z);
    reverseWords("    a good    example    ");
    math172Optimized(30);

    std::vector<int> ll = {2, 5, 0, 0};
    canJump12(ll);

    std::vector<int> jj = {2,3,0,1,4};
    jump2(jj);

    std::vector<int> lls = {-2,1,-3,4,-1,2,1,-5,4};
    maxSubArrayOptimized(lls);
    std::string s1 = "aaaa";
    std::string s2 = "dog cat cat dog";
    wordPattern(s1, s2);

    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    auto k1 = wordDictionary.search("pad"); // return False
    auto k2 = wordDictionary.search("bad"); // return True
    auto k3 = wordDictionary.search(".ad"); // return True
    auto k4 = wordDictionary.search("b.."); // return True
    int kkk = 0;

    std::vector<int> scs = {8,8,8,8,8,8};
    auto px = searchRange(scs, 8);
    int jkjj = 0;

    ListNode* h1 = new ListNode();
    h1->val = 4;
    ListNode* h2 = new ListNode();
    h2->val = 1;
    ListNode* h3 = new ListNode();
    h3->val = 3;
    ListNode* h4 = new ListNode();
    h4->val = 2;

    h1->next = h2;
    h2->next = h3;
    h3->next = h4;

    sortList(h1);
    int kkks = 0;

    std::vector<int> nums1 = {1,-2,3,-2}, nums2 = {3, 4, 3, 2, 1};
    findPeakElement(nums2);
    maxSubarraySumCircular(nums1);

    ListNode* r1 = new ListNode();
    ListNode* r2 = new ListNode();
    ListNode* r3 = new ListNode();
    ListNode* r4 = new ListNode();
    ListNode* r5 = new ListNode();
    ListNode* r6 = new ListNode();
    ListNode* r7 = new ListNode();
    r1->val = 1;
    r2->val = 2;
    r3->val = 3;
    r4->val = 3;
    r5->val = 4;
    r6->val = 4;
    r7->val = 4;
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;
    r4->next = r5;
    r5->next = r6;
    r6->next = r7;
    deleteDuplicates(r1);
}

