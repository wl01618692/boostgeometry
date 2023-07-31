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
#include <list>

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
bool canJump12(std::vector<int> &nums) {
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
int jump2(std::vector<int> &nums) {
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

// modify in-place
// AC
void reverseString(std::string &s, int i, int j) {
    while (i <= j) {
        std::swap(s[i++], s[j--]);
    }
}

std::string reverseWords(std::string s) {
    int k = 0;
    while (s[k] == ' ') ++k;
    s.erase(s.begin(), s.begin() + k);

    k = 0;
    while (s[s.size() - 1 - k] == ' ') ++k;
    s.erase(s.end() - k, s.end());

    k = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (k == -1 && s[i] == ' ' && s[i + 1] == ' ') {
            k = i;
        }

        if (k != -1 && s[i + 1] != ' ') {
            s.erase(s.begin() + k, s.begin() + i);
            k = -1;
            i -= (i - k);
        }
    }

    for (int i = 0; i < s.size() / 2; ++i) {
        std::swap(s[i], s[s.size() - 1 - i]);
    }

    for (int i = 0, j = 0; i < s.size(); ++i) {
        if (i == s.size() - 1 || s[i + 1] == ' ') {
            reverseString(s, j, i);
            j = i + 2;
            i++;
        }
    }
    return s;
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

// 274. H-Index
//
//Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
//
//According to the definition of h-index on Wikipedia:
// The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
//
//
//
//Example 1:
//
//Input: citations = [3,0,6,1,5]
//Output: 3
//Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
//Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
// 0 1 3 5 6
//
//Example 2:
//
//Input: citations = [1,3,1]
//Output: 1
// 1 1 3

// complexity
// time: O(NlogN)
// space: O(1)
int hIndex(vector<int> &citations) {
    int left = 0;
    std::sort(citations.begin(), citations.end());
    while (left < citations.size() && citations[citations.size() - 1 - left] > left) {
        ++left;
    }
    return left;
}

// time complexity: O(n)
// space complexity: O(n)
int hIndexCountingSort(vector<int> &citations) {
    int n = citations.size();
    std::vector<int> counter(n + 1, 0);
    for (auto elem: citations) {
        counter[std::min(n, elem)]++;
    }

    int k = n;
    for (int s = counter[n]; k > s; s += counter[k]) {
        --k;
    }
    return k;
}

std::vector<int> countingSort(std::vector<int> vec) {
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (auto elem: vec) {
        max = std::max(max, elem);
        min = std::min(min, elem);
    }
    std::vector<int> count(vec.size(), 0);
    for (auto elem: vec) {
        count[elem - min]++;
    }

    std::vector<int> output(vec.size(), 0);
    for (int i = 0, j = 0; i < vec.size(); ++i) {
        while (count[i] > 0) {
            output[j++] = i + min;
            --count[i];
        }
    }
    return output;
}

// 238. Product of Array Except Self
//
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
//You must write an algorithm that runs in O(n) time and without using the division operation.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,4]
//Output: [24,12,8,6]
//
//Example 2:
//
//Input: nums = [-1,1,0,-3,3]
//Output: [0,0,9,0,0]
//
//
//
//Constraints:
//
//    2 <= nums.length <= 105
//    -30 <= nums[i] <= 30
//    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
//
//
//Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums;
    std::vector<int> left(n, 0);
    std::vector<int> right(n, 0);
    std::vector<int> output(n, 0);
    left[0] = 1;
    for (int i = 1; i < n; ++i) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[n - 1] = 1;
    for (int i = n - 1; i >= 1; --i) {
        right[i - 1] = right[i] * nums[i];
    }

    for (int i = 0; i < n; ++i) {
        output[i] = right[i] * left[i];
    }
    return output;
}

vector<int> productExceptSelfOptimized(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums;
    std::vector<int> output(n, 0);
    output[0] = 1;
    for (int i = 1; i < n; ++i) {
        output[i] = output[i - 1] * nums[i - 1];
    }
    int R = 1;
    for (int i = n - 1; i >= 0; --i) {
        output[i] *= R;
        R *= nums[i];
    }
    return output;
}

// 380. Insert Delete GetRandom O(1)
//
//Implement the RandomizedSet class:
//
//    RandomizedSet() Initializes the RandomizedSet object.
//    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
//    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
//    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
//
//You must implement the functions of the class such that each function works in average O(1) time complexity.
//
//Example 1:
//
//Input
//["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
//[[], [1], [2], [2], [], [1], [2], []]
//Output
//[null, true, false, true, 2, true, false, 2]
//
//Explanation
//RandomizedSet randomizedSet = new RandomizedSet();
//randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
//randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
//randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
//randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
//randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
//randomizedSet.insert(2); // 2 was already in the set, so return false.
//randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
//
//
//
//Constraints:
//
//    -231 <= val <= 231 - 1
//    At most 2 * 105 calls will be made to insert, remove, and getRandom.
//    There will be at least one element in the data structure when getRandom is called.

class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        v.push_back(val);
        mp.insert({val, v.size() - 1});
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int lastElement = v[v.size() - 1];
        int idx = mp[val];
        v[idx] = lastElement;
        mp[lastElement] = idx;

        v.erase(v.end() - 1, v.end());
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }

    std::unordered_map<int, int> mp;
    std::vector<int> v;
};

// 12. Integer to Roman
//
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV.
// Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//    I can be placed before V (5) and X (10) to make 4 and 9.
//    X can be placed before L (50) and C (100) to make 40 and 90.
//    C can be placed before D (500) and M (1000) to make 400 and 900.
//
//Given an integer, convert it to a roman numeral.
//
//Example 1:
//
//Input: num = 3
//Output: "III"
//Explanation: 3 is represented as 3 ones.
//
//Example 2:
//
//Input: num = 58
//Output: "LVIII"
//Explanation: L = 50, V = 5, III = 3.
//
//Example 3:
//
//Input: num = 1994
//Output: "MCMXCIV"
//Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

// time: O(1)
// space: O(1)
string intToRoman(int num) {
    std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<std::string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    std::string output;
    for (int i = 0; i < values.size() && num > 0; ++i) {
        while (values[i] <= num) {
            num -= values[i];
            output += symbols[i];
        }
    }
    return output;
}

// 80. Remove Duplicates from Sorted Array II
//
// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice.
// The relative order of the elements should be kept the same.
//
// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums.
// More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
//
//Return k after placing the final result in the first k slots of nums.
//
//Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
//
//Custom Judge:
//
//The judge will test your solution with the following code:
//
//int[] nums = [...]; // Input array
//int[] expectedNums = [...]; // The expected answer with correct length
//
//int k = removeDuplicates(nums); // Calls your implementation
//
//assert k == expectedNums.length;
//for (int i = 0; i < k; i++) {
//    assert nums[i] == expectedNums[i];
//}
//
//If all assertions pass, then your solution will be accepted.
//
//
//
//Example 1:
//
//Input: nums = [1,1,1,2,2,3]
//Output: 5, nums = [1,1,2,2,3,_]
//Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
//It does not matter what you leave beyond the returned k (hence they are underscores).
//
//Example 2:
//
//Input: nums = [0,0,1,1,1,1,2,3,3]
//Output: 7, nums = [0,0,1,1,2,3,3,_,_]
//Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
//It does not matter what you leave beyond the returned k (hence they are underscores).

/// ？？？？？？？？
int removeDuplicates(vector<int>& nums) {
    int slow = 0, fast = 1;
    int pos = 0;
    while (slow < nums.size() && fast < nums.size()) {

    }
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
// 76. Minimum Window Substring
//
//Given two strings s and t of lengths m and n respectively, return the minimum window substring
//of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//
//The testcases will be generated such that the answer is unique.
//
//
//
//Example 1:
//
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
//
//Example 2:
//
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
//
//Example 3:
//
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
//
//
//
//Constraints:
//
//    m == s.length
//    n == t.length
//    1 <= m, n <= 105
//    s and t consist of uppercase and lowercase English letters.


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
bool isValidSudoku(vector<vector<char>> &board) {
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
int longestConsecutive(std::vector<int> &nums) {
    if (nums.size() == 1) return 1;
    std::set<int> s;
    for (auto &elem: nums) {
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
    for (auto &elem: s) {
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
// 228. Summary Ranges
//
//You are given a sorted unique integer array nums.
//
//A range [a,b] is the set of all integers from a to b (inclusive).
//
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
// That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//
//Each range [a,b] in the list should be output as:
//
//    "a->b" if a != b
//    "a" if a == b
//
//
//
//Example 1:
//
//Input: nums = [0,1,2,4,5,7]
//Output: ["0->2","4->5","7"]
//Explanation: The ranges are:
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"
//
//Example 2:
//
//Input: nums = [0,2,3,4,6,8,9]
//Output: ["0","2->4","6","8->9"]
//Explanation: The ranges are:
//[0,0] --> "0"
//[2,4] --> "2->4"
//[6,6] --> "6"
//[8,9] --> "8->9"
//
//
//
//Constraints:
//
//    0 <= nums.length <= 20
//    -231 <= nums[i] <= 231 - 1
//    All the values of nums are unique.
//    nums is sorted in ascending order.

// time complexity: O(n)
// space complexity: O(1)
vector<string> summaryRanges(vector<int> &nums) {
    std::vector<string> ans;
    for (int i = 0; i < nums.size(); ++i) {
        int left = nums[i];
        while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) {
            ++i;
        }

        if (left == nums[i]) {
            ans.push_back(to_string(left));
        } else {
            ans.push_back(to_string(left) + "->" + to_string(nums[i]));
        }
    }
    return ans;
}

// 57. Insert Interval
//
//You are given an array of non-overlapping intervals intervals where intervals[i] =
// [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//
//Return intervals after the insertion.
//
//Example 1:
//
//Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
//Output: [[1,5],[6,9]]
//
//Example 2:
//
//Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//Output: [[1,2],[3,10],[12,16]]
//Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

}

/// Stack

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

// Iterate the expression string in reverse order one character at a time.
// Since we are reading the expression character by character, we need to be careful when we are reading digits and non-digits.
//
// The operands could be formed by multiple characters. A string "123" would mean a numeric 123, which could be formed as: 123 >> 120 + 3 >> 100 + 20 + 3.
// Thus, if the character read is a digit we need to form the operand by multiplying a power of 10 to the current digit and adding it to the overall operand.
// We do this since we are processing the string in the reverse order.
//
// The operands could be formed by multiple characters.
// We need to keep track of an on-going operand. This part is a bit tricky since in this case the string is reversed.
// Once we encounter a character which is not a digit, we push the operand onto the stack.
//
// When we encounter an opening parenthesis (, this means an expression just ended. Recall we have reversed the expression.
// So an opening bracket would signify the end of the an expression.
// This calls for evaluation of the expression by popping operands and operators off the stack till we pop corresponding closing parenthesis.
// The final result of the expression is pushed back onto the stack.
//
// Note: We are evaluating all the sub-expressions within the main expression.
// The sub-expressions on the right get evaluated first but the main expression itself is evaluated from left to right when all its components are resolved, which is very important for correct results.
//
// For eg. For expression A−(B+C)+(D+E−F)A - (B+C) + (D+E-F)A−(B+C)+(D+E−F), D+E−FD+E-FD+E−F is evaluated before B+CB+CB+C.
// While evaluating D+E−FD+E-FD+E−F the order is from left to right.
// Similarly for the parent expression, all the child components are evaluated and stored on the stack so that final evaluation is left to right.
//
// Push the other non-digits onto to the stack.
//
// Do this until we get the final result. It's possible that we don't have any more characters left to process but the stack is still non-empty. This would happen when the main expression is not enclosed by parenthesis. So, once we are done evaluating the entire expression, we check if the stack is non-empty. If it is, we treat the elements in it as one final expression and evaluate it the same way we would if we had encountered an opening bracket.
//
// We can also cover the original expression with a set of parenthesis to avoid this extra call.

int calculate(std::string s) {
    int output = 0;
    std::stack<char> stack1;
    std::reverse(s.begin(), s.end());
    for (auto elem: s) {
        if (stack1.top() != '+' && stack1.top() != '-') {

        }
    }

    return output;
}

// class Solution {
//
//    public int evaluateExpr(Stack<Object> stack) {
//
//        // If stack is empty or the expression starts with
//        // a symbol, then append 0 to the stack.
//        // i.e. [1, '-', 2, '-'] becomes [1, '-', 2, '-', 0]
//        if (stack.empty() || !(stack.peek() instanceof Integer)) {
//            stack.push(0);
//        }
//
//        int res = (int) stack.pop();
//
//        // Evaluate the expression till we get corresponding ')'
//        while (!stack.empty() && !((char) stack.peek() == ')')) {
//
//            char sign = (char) stack.pop();
//
//            if (sign == '+') {
//                res += (int) stack.pop();
//            } else {
//                res -= (int) stack.pop();
//            }
//        }
//        return res;
//    }
//
//    public int calculate(String s) {
//
//        int operand = 0;
//        int n = 0;
//        Stack<Object> stack = new Stack<Object>();
//
//        for (int i = s.length() - 1; i >= 0; i--) {
//
//            char ch = s.charAt(i);
//
//            if (Character.isDigit(ch)) {
//
//                // Forming the operand - in reverse order.
//                operand = (int) Math.pow(10, n) * (int) (ch - '0') + operand;
//                n += 1;
//
//            } else if (ch != ' ') {
//                if (n != 0) {
//
//                    // Save the operand on the stack
//                    // As we encounter some non-digit.
//                    stack.push(operand);
//                    n = 0;
//                    operand = 0;
//
//                }
//                if (ch == '(') {
//
//                    int res = evaluateExpr(stack);
//                    stack.pop();
//
//                    // Append the evaluated result to the stack.
//                    // This result could be of a sub-expression within the parenthesis.
//                    stack.push(res);
//
//                } else {
//                    // For other non-digits just push onto the stack.
//                    stack.push(ch);
//                }
//            }
//        }
//
//        //Push the last operand to stack, if any.
//        if (n != 0) {
//            stack.push(operand);
//        }
//
//        // Evaluate any left overs in the stack.
//        return evaluateExpr(stack);
//    }
//}

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
int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> s;
    for (auto &elem: tokens) {
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
    stack<std::string> s;
    std::string res;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == '/') {
            continue;
        }

        std::string tmp;
        while (i != path.size() && path[i] != '/') {
            tmp += path[i];
            i++;
        }

        if (tmp == ".") {
            continue;
        } else if (tmp == "..") {
            if (!s.empty())  s.pop();
        } else {
            s.push(tmp);
        }
    }

    while (!s.empty()) {
        res = "/" + s.top() + res;
        s.pop();
    }

    if (res.empty()) res = "/";
    return res;
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
    for (auto &elem: s) {
        if (!stack.empty()) {
            if ((stack.top() == '(' && elem == ')') || (stack.top() == '[' && elem == ']') ||
                (stack.top() == '{' && elem == '}')) {
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
    ListNode *next;
    double val;
};

ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    auto dummyHead = new ListNode();
    dummyHead->next = head;
    auto cur = dummyHead;
    while (cur->next != nullptr && cur->next->next != nullptr) {
        if (cur->next->val == cur->next->next->val) {
            auto tmp = cur->next->val;
            while (cur->next != nullptr && tmp == cur->next->val) {
                cur->next = cur->next->next;
            }
        } else {
            cur = cur->next;
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
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

std::unordered_map<Node *, Node *> cacheMap;

// recursion
Node *copyRandomList(Node *head) {
    if (head == nullptr) return nullptr;
    if (!cacheMap.count(head)) {
        auto N = new Node(head->val);
        cacheMap[head] = N;
        N->next = copyRandomList(head->next);
        N->random = copyRandomList(head->random);
    }
    return cacheMap[head];
}

// iterative
// time: O(n)
// space: O(n)
Node *copyRandomList2(Node *head) {
    std::unordered_map<Node *, Node *> cacheMap;
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

// iterative
// time: O(n)
// space: O(1)
Node *copyRandomList3(Node *head) {
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

// 146. LRU Cache
//
//Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//
//Implement the LRUCache class:
//
//    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//    int get(int key) Return the value of the key if the key exists, otherwise return -1.
//    void put(int key, int value) Update the value of the key if the key exists. Otherwise,
//    add the key-value pair to the cache.
//    If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//
//The functions get and put must each run in O(1) average time complexity.
//
//
//
//Example 1:
//
//Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//Explanation
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4

class LRUCache {
private:
    class DoublyLinkedList {
    public:
        DoublyLinkedList (int key, int val) {
            this->val = val;
            this->key = key;
        };

        DoublyLinkedList(){};

        int key;
        int val;
        DoublyLinkedList* prev;
        DoublyLinkedList* next;
    };

    DoublyLinkedList* head;
    DoublyLinkedList* tail;
    int capacity;
    int size;
    std::unordered_map<int, DoublyLinkedList*> map;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new DoublyLinkedList();
        tail = new DoublyLinkedList();
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(DoublyLinkedList *pList) {
        pList->next->prev = pList->prev;
        pList->prev->next = pList->next;
        pList->next = nullptr;
        pList->prev = nullptr;
    }

    void addHead(DoublyLinkedList *pList) {
        pList->next = head->next;
        pList->prev = head;
        head->next->prev = pList;
        head->next = pList;
    }

    void moveToHead(DoublyLinkedList *pList) {
        removeNode(pList);
        addHead(pList);
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        DoublyLinkedList* node = map.at(key);
        moveToHead(node);
        return node->val;
    }

    void removeLastNode() {
        DoublyLinkedList* node = tail->prev;
        removeNode(node);
        map.erase(node->key);
        --size;
    }

    void put(int key, int value) {

        // if find the key, update value, move to head
        if (map.find(key) != map.end()) {
            DoublyLinkedList* node = map.at(key);
            node->val = value;
            moveToHead(node);
        } else {
            // if didnt find the key, create new node
            DoublyLinkedList* node = new DoublyLinkedList(key, value);
            addHead(node);
            map.insert({key, node});
            ++size;

            if (size > capacity) {
                removeLastNode();
            }
        }
    }

};

// 460. LFU Cache
//
//Design and implement a data structure for a Least Frequently Used (LFU) cache.
//
//Implement the LFUCache class:
//
//    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
//    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
//    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity,
//    it should invalidate and remove the least frequently used key before inserting a new item.
//    For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
//
// To determine the least frequently used key, a use counter is maintained for each key in the cache.
// The key with the smallest use counter is the least frequently used key.
//
// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation).
// The use counter for a key in the cache is incremented either a get or put operation is called on it.
//
// The functions get and put must each run in O(1) average time complexity.
//
//
//
//Example 1:
//
//Input
//["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//
//Explanation
//// cnt(x) = the use counter for key x
//// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
//LFUCache lfu = new LFUCache(2);
//lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
//lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
//lfu.get(1);      // return 1
//                 // cache=[1,2], cnt(2)=1, cnt(1)=2
//lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                 // cache=[3,1], cnt(3)=1, cnt(1)=2
//lfu.get(2);      // return -1 (not found)
//lfu.get(3);      // return 3
//                 // cache=[3,1], cnt(3)=2, cnt(1)=2
//lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                 // cache=[4,3], cnt(4)=1, cnt(3)=2
//lfu.get(1);      // return -1 (not found)
//lfu.get(3);      // return 3
//                 // cache=[3,4], cnt(4)=1, cnt(3)=3
//lfu.get(4);      // return 4
//                 // cache=[4,3], cnt(4)=2, cnt(3)=3

// HashMap<Integer, Pair<Integer, Integer>> cache, keyed by the original key and valued by the frequency-value pair.
// HashMap<Integer, LinkedListHashSet<Integer>> frequencies, keyed by frequency and valued by the set of keys that have the same frequency.
// int minf, which is the minimum frequency at any given time.
// int capacity, which is the capacity given in the input.

//Here, N is the total number of operations.
//
// Time complexity: O(1), as required by the question.
//
//Since we only have basic HashMap/(Linked)HashSet operations. For details,
//
//Our utility function insert puts the key- value pair into the cache, queries and possibly puts an empty LinedHashSet in the frequencies,
// then queries frequencies again and adds a key into the associated value which is a LinkedHashSet.
// All the operations are based on the hash calculating for simple type (int or Integer) and the time complexity is constant.
//
//For each get operation, in the worst case, we query the frequencies and remove a key from the associated value which is a LinkedHashSet and call insert function once.
// All the operations have the constant time complexity based on the hash calculating for simple type.
//
//For each put operation, in the simple case we just insert the new key-value pair into the cache and call get function once.
// In the worst case, we query the frequencies to get the associated value, namely all the keys with the same frequencies which is a LinkedHashSet.
// And then we get the first key from the LinkedHashSet, remove it from both cache and frequencies.
// All the operations have the constant time complexity based on the hash calculating for simple type.
//
//    Space complexity: O(N).
//
//    We save all the key-value pairs as well as all the keys with frequencies in the 2 HashMaps (plus a LinkedHashSet), so there are at most $min(N, capacity) keys and values at any given time.

class LFUCache {
    // key: frequency, value: list of original key-value pairs that have the same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator corresponding key int the
    // frequencies map's list.
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty()){
            frequencies.erase(f);
            if(minf == f) {
                ++minf;
            }
        }

        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first); // cache erase key
            frequencies[minf].pop_front();

            if(frequencies[minf].empty()) {
                frequencies.erase(minf);
            }
        }

        minf = 1;
        insert(key, 1, value);
    }
};
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

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::queue<TreeNode *> q;
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
        }
        if (c % 2 == 1) std::reverse(a.begin(), a.end());
        output.push_back(a);
        ++c;
    }
    return output;
}

class Solution {
protected void DFS(TreeNode node, int level, List<List<Integer>> results) {
        if (level >= results.size()) {
            LinkedList<Integer> newLevel = new LinkedList<Integer>();
            newLevel.add(node.val);
            results.add(newLevel);
        } else {
            if (level % 2 == 0)
                results.get(level).add(node.val);
            else
                results.get(level).add(0, node.val);
        }

        if (node.left != null) DFS(node.left, level + 1, results);
        if (node.right != null) DFS(node.right, level + 1, results);
    }

public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        DFS(root, 0, results);
        return results;
    }
}

std::vector<std::vector<int>> LevelOrder(TreeNode *root) {
    std::queue<TreeNode *> q;
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

// 399. Evaluate Division
//
// You are given an array of variable pairs equations and an array of real numbers values,
// where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i].
// Each Ai or Bi is a string that represents a single variable.
//
// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
//
// Return the answers to all queries. If a single answer cannot be determined, return -1.0.
//
// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
//
//
//
// Example 1:
//
// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation:
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
//
// Example 2:
//
// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
//
// Example 3:
//
// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]
//

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//    std::map<std::string, std::map<std::string, double>> g;
//    for (int i = 0; i < equations.size(); ++i) {
//        std::vector<std::string> equation = equations[i];
//        std::string dividend = equation[0];
//        std::string divisor = equation[1];
//        double quotient = values[i];
//        g[dividend] = {divisor, quotient};
//        g[divisor] = {dividend, 1 / quotient};
//    }
     std::vector<std::vector<int>> matrix;


}

class Solution {
public double[] calcEquation(List<List<String>> equations, double[] values,
    List<List<String>> queries) {

        HashMap<String, HashMap<String, Double>> graph = new HashMap<>();

        // Step 1). build the graph from the equations
        for (int i = 0; i < equations.size(); i++) {
            List<String> equation = equations.get(i);
            String dividend = equation.get(0), divisor = equation.get(1);
            double quotient = values[i];

            if (!graph.containsKey(dividend))
                graph.put(dividend, new HashMap<String, Double>());
            if (!graph.containsKey(divisor))
                graph.put(divisor, new HashMap<String, Double>());

            graph.get(dividend).put(divisor, quotient);
            graph.get(divisor).put(dividend, 1 / quotient);
        }

        // Step 2). Evaluate each query via bactracking (DFS)
        // by verifying if there exists a path from dividend to divisor
        double[] results = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            List<String> query = queries.get(i);
            String dividend = query.get(0), divisor = query.get(1);

            if (!graph.containsKey(dividend) || !graph.containsKey(divisor))
                results[i] = -1.0;
            else if (dividend == divisor)
                results[i] = 1.0;
            else {
                HashSet<String> visited = new HashSet<>();
                results[i] = backtrackEvaluate(graph, dividend, divisor, 1, visited);
            }
        }

        return results;
    }

private double backtrackEvaluate(HashMap<String, HashMap<String, Double>> graph, String currNode, String targetNode, double accProduct, Set<String> visited) {

        // mark the visit
        visited.add(currNode);
        double ret = -1.0;

        Map<String, Double> neighbors = graph.get(currNode);
        if (neighbors.containsKey(targetNode))
            ret = accProduct * neighbors.get(targetNode);
        else {
            for (Map.Entry<String, Double> pair : neighbors.entrySet()) {
                String nextNode = pair.getKey();
                if (visited.contains(nextNode))
                    continue;
                ret = backtrackEvaluate(graph, nextNode, targetNode,
                                        accProduct * pair.getValue(), visited);
                if (ret != -1.0)
                    break;
            }
        }

        // unmark the visit, for the next backtracking
        visited.remove(currNode);
        return ret;
    }
}
// 207. Course Schedule
//
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//
//    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//
//Return true if you can finish all courses. Otherwise, return false.
//
//
//
//Example 1:
//
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: true
//Explanation: There are a total of 2 courses to take.
//To take course 1 you should have finished course 0. So it is possible.
//
//Example 2:
//
//Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take.
//To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (numCourses == 0) return true;
    vector<int> inDegree(numCourses,0);
    vector<vector<int>> graph(numCourses);
    for (auto elem: prerequisites) {
        int i = elem[0];
        int j = elem[1];
        graph[i].push_back(j);
        inDegree[j]++;
    }

    int sum = 0;
    std::queue<int> q;
    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        ++sum;
        for (auto elem: graph[tmp]) {
            --inDegree[elem];
            if (inDegree[elem] == 0) q.push(elem);
        }
    }
    return sum == numCourses;
}

// 210. Course Schedule II
//
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
//
//
//
//Example 1:
//
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: [0,1]
//Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
//
//Example 2:
//
//Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//Output: [0,2,1,3]
//Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
//So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
//
//Example 3:
//
//Input: numCourses = 1, prerequisites = []
//Output: [0]

// 3, {{0,2},{1,2},{2,0}}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<int> output;
    if (numCourses == 0) return output;
    vector<int> inDegree(numCourses,0);
    vector<vector<int>> graph(numCourses);
    for (auto elem: prerequisites) {
        int i = elem[0];
        int j = elem[1];
        graph[i].push_back(j);
        inDegree[j]++;
    }

    int sum = 0;
    std::queue<int> q;
    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        ++sum;
        output.push_back(tmp);
        for (auto elem: graph[tmp]) {
            --inDegree[elem];
            if (inDegree[elem] == 0) q.push(elem);
        }
    }

    if (sum != numCourses) return std::vector<int> {};
    std::reverse(output.begin(), output.end());
    return output;
}


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
        std::map<char, TrieNode *> _sonMap;
    };

    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        auto tmp = root;
        for (auto &elem: word) {
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
        for (auto &elem: word) {
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
        for (auto &elem: prefix) {
            if (tmp->_sonMap.find(elem) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[elem];
            } else {
                return false;
            }
        }
        return true;
    }

    TrieNode *root;
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
        std::map<char, TrieNode *> _sonMap;
    };

    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(std::string word) {
        auto tmp = root;
        for (auto &elem: word) {
            if (tmp->_sonMap.find(elem) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[elem];
                continue;
            }
            tmp->_sonMap[elem] = new TrieNode();
            tmp = tmp->_sonMap[elem];
        }
        tmp->_isLeaf = true;
    }

    bool searchHelper(std::string word, TrieNode *inNode) {
        for (int i = 0; i < word.size(); ++i) {
            auto elem = word[i];
            if (inNode->_sonMap.find(elem) != inNode->_sonMap.end()) {
                inNode = inNode->_sonMap[elem];
            } else {
                if (elem == '.') {
                    vector<char> keys;
                    for (auto &itr: inNode->_sonMap)
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
private:
    vector<string> ans;
    string cur;

    void backtrack(int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(open, close + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        backtrack(0, 0, n);
        return ans;
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

////Input: head = [4,2,1,3]
ListNode *merge(ListNode *list1, ListNode *list2) {
    ListNode *dummyHead = new ListNode();
    ListNode *ptr = dummyHead;
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
    if (list1) ptr->next = list1;
    else ptr->next = list2;
    return dummyHead->next;
}

ListNode *getMid(ListNode *head) {
    ListNode *midPrev = nullptr;
    while (head && head->next) {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}

ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
        return head;
    ListNode *mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
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

int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = std::max(dp[i - 1], 0) + nums[i];
    }
    return *std::max(dp.begin(), dp.end());
}

int maxSubArrayOptimized(std::vector<int> &nums) {
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
int maxSubarraySumCircular(std::vector<int> &nums) {
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

bool binarySearch(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

int searchInsert(vector<int> &nums, int target) {
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

bool searchMatrix(vector<vector<int>> &matrix, int target) {
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

int findPeakElement(vector<int> &nums) {
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


//Time complexity: O(logn)
//This algorithm only requires one binary search over nums.
//
//Space complexity: O(1)
//We only need to update several parameters left, right and mid, which takes O(1) space.
//
int search(vector<int> &nums, int target) {
    if (nums.size() == 1) {
        if (nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }

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

int LeftSearch(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            if (m != 0 && nums[m - 1] == target) {
                r = m - 1;
            } else {
                return m;
            }
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int RightSearch(std::vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            if (m != nums.size() - 1 && nums[m + 1] == target) {
                l = m + 1;
            } else {
                return m;
            }

        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

std::vector<int> searchRange(std::vector<int> &nums, int target) {
    std::vector<int> output = {-1, -1};
    if (nums.empty()) return output;
    int l = LeftSearch(nums, target);
    int r = RightSearch(nums, target);
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

// Example 4:
// Input: [3,1,2]
// Output: 1

// Complexity Analysis
//    Time Complexity : Same as Binary Search O(logN)
//    Space Complexity : O(1)

int findMin(std::vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if (nums[right] > nums[mid]) {
            right = mid;
        } else {
            break;
        }
    }
    return nums[left];
}

// 4. Median of Two Sorted Arrays
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

class SolutionBinary {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int na = int(A.size()), nb = int(B.size());
        int n = na + nb;
        if (n % 2) {
            return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return 1.0 * (solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1) + solve(A, B, n / 2, 0, na - 1, 0, nb - 1)) / 2;
        }
    }

    int solve(vector<int> &A, vector<int> &B, int k, int aStart, int aEnd, int bStart, int bEnd) {
        // If the segment of on array is empty, it means we have passed all
        // its element, just return the corresponding element in the other array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
            // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
        return -1;
    }
};

// mergeSort
// time: O(n + m)
// space: O(1)
class SolutionMergeSort {
public:
    int p1 = 0, p2 = 0;

    int getMin(vector<int> &nums1, vector<int> &nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double) (getMin(nums1, nums2) + getMin(nums1, nums2)) / 2.0;
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

int findKthLargest(std::vector<int> &nums, int k) {
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

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    int n = capital.size();
    std::priority_queue<int, vector<int>, less<>> pq;
    std::vector<std::pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        arr.push_back({capital[i], profits[i]});
    }
    std::sort(arr.begin(), arr.end());

    int cur_index = 0;
    for (int i = 0; i < k; ++i) {
        while (cur_index < n && w >= arr[cur_index].first) {
            pq.push(arr[cur_index].second);
            ++cur_index;
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

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
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
int maxPoints(vector<vector<int>> &points) {
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

int coinChange(std::vector<int> &coins, int amount) {
    if (amount == 0) return 0;

    std::vector<int> dp(amount + 1, 1e7);
    for (auto &elem: coins) {
        if (elem > amount) continue;
        dp[elem] = 1;
    }

    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        if (dp[i] == 1) continue;
        for (int coin: coins) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] >= 1e7 ? -1 : dp[amount];
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

bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
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
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
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

// 5. Longest Palindromic Substring
//
//Given a string s, return the longest
//palindromic
//substring
//in s.
//
//
//
//Example 1:
//
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//
//Example 2:
//
//Input: s = "cbbd"
//Output: "bb"

string longestPalindrome(string s) {

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

    std::vector<int> h = {3, 2, 1, 5, 6, 4};
    findKthLargest(h, 2);
    isIsomorphic("badc", "baba");

    std::string s = "applepenapple";
    std::vector<std::string> ss = {"apple", "pen"};
    wordBreak(s, ss);

    std::vector<int> z = {1, 2, 3, 4, 5, 8, 10, 11, 12, 13, 14, 15};
    longestConsecutive(z);
    reverseWords("F R  I   E    N     D      S      ");
    math172Optimized(30);

    std::vector<int> ll = {2, 5, 0, 0};
    canJump12(ll);

    std::vector<int> jj = {2, 3, 0, 1, 4};
    jump2(jj);

    std::vector<int> lls = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
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

    std::vector<int> scs = {8, 8, 8, 8, 8, 8};
    auto px = searchRange(scs, 8);
    int jkjj = 0;

    ListNode *h1 = new ListNode();
    h1->val = 4;
    ListNode *h2 = new ListNode();
    h2->val = 1;
    ListNode *h3 = new ListNode();
    h3->val = 3;
    ListNode *h4 = new ListNode();
    h4->val = 2;

    h1->next = h2;
    h2->next = h3;
    h3->next = h4;

    sortList(h1);
    int kkks = 0;

    std::vector<int> nums1 = {1, -2, 3, -2}, nums2 = {3, 4, 3, 2, 1};
    findPeakElement(nums2);
    maxSubarraySumCircular(nums1);

    ListNode *r1 = new ListNode();
    ListNode *r2 = new ListNode();
    ListNode *r3 = new ListNode();
    ListNode *r4 = new ListNode();
    ListNode *r5 = new ListNode();
    ListNode *r6 = new ListNode();
    ListNode *r7 = new ListNode();
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
    std::vector<int> nums3 = {1, 2, 3, 4};
    productExceptSelf(nums3);


    RandomizedSet randomizedSet;
    randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
    randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet.insert(2); // 2 was already in the set, so return false.
    randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.

    // ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
    // [[],[0],[0],[0],[],[0],[0]]
    RandomizedSet randomizedSet2;
    randomizedSet2.remove(0);
    randomizedSet2.remove(0);
    randomizedSet2.insert(0);
    randomizedSet2.getRandom();
    randomizedSet2.remove(0);
    randomizedSet2.insert(0);
}

