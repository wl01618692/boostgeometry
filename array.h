//
// Created by zhangjiayuan on 23-5-5.
//

#ifndef BOOSTGEOMETRY_ARRAY_H
#define BOOSTGEOMETRY_ARRAY_H

#include "Util.h"
// 示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。
// 示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
int removeElement(std::vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (val != nums[fastIndex]) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}

#endif //BOOSTGEOMETRY_ARRAY_H
