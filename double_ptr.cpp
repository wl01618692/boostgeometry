//
// Created by zhangjiayuan on 23-5-4.
//

#include "double_ptr.h"

// [3,2,2,3], val = 3, return 2
// [0,1,2,2,3,0,4,2], val = 2, return 5
int remove_elem(std::vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (val != nums[fastIndex]) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}


void reverse_string(std::vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
        std::swap(s[i], s[j]);
    }
}

void reverse1(std::string& s, int left, int right) {
    for (int i = left, j = right; i < j; ++i, --j) {
        std::swap(s[i], s[j]);
    }
}

// 1. 每隔 2k 个字符的前 k 个字符进行反转
// 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
// 3. 剩余字符少于 k 个，则将剩余字符全部反转。
std::string reverseStr(std::string& s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        if (i + k <= s.size()) {
            reverse(s.begin() + i, s.begin() + i + k);
        } else {
            reverse(s.begin() + i, s.end());
        }
    }
    return s;
}

// 示例 1： 输入：s = "We are happy."
// 输出："We%20are%20happy."
std::string replaceSpace(std::string s) {
    int count = 0;
    for (auto& c: s) {
        if (c == ' ') {
            count++;
        }
    }
    std::string output(s.size() + 2 * count, ' ');
    int index = 0;
    for (auto& c: s) {
        if (c == ' ') {
            output.at(index++) = '%';
            output.at(index++) = '2';
            output.at(index++) = '0';
        } else {
            output.at(index++) = c;
        }
    }
    return output;
}

