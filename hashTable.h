//
// Created by zhangjiayuan on 23-5-15.
//

#ifndef BOOSTGEOMETRY_HASHTABLE_H
#define BOOSTGEOMETRY_HASHTABLE_H
#include "Util.h"
bool isAnagram(const std::string& s, const std::string& t);
bool isHappy(int num);
// 映射 	底层实现 	是否有序 	数值是否可以重复 	能否更改数值 	查询效率 	增删效率
// std::map 	红黑树 	key有序 	key不可重复 	key不可修改 	O(logn) 	O(logn)
// std::multimap 	红黑树 	key有序 	key可重复 	key不可修改 	O(log n) 	O(log n)
// std::unordered_map 	哈希表 	key无序 	key不可重复 	key不可修改 	O(1) 	O(1)

// 集合 	底层实现 	是否有序 	数值是否可以重复 	能否更改数值 	查询效率 	增删效率
// std::set 	红黑树 	有序 	否 	否 	O(log n) 	O(log n)
// std::multiset 	红黑树 	有序 	是 	否 	O(logn) 	O(logn)
// std::unordered_set 	哈希表 	无序 	否 	否 	O(1) 	O(1)
#endif //BOOSTGEOMETRY_HASHTABLE_H
