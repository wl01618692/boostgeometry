//
// Created by zhangjiayuan on 23-5-23.
//

#ifndef BOOSTGEOMETRY_MYSTRING_H
#define BOOSTGEOMETRY_MYSTRING_H
#include "Util.h"
/// lc 925
// 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
//
//示例 1：
//
//    输入：name = "alex", typed = "aaleex"
//    输出：true
//    解释：'alex' 中的 'a' 和 'e' 被长按。
//
//示例 2：
//
//    输入：name = "saeed", typed = "ssaaedd"
//    输出：false
//    解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
//
//示例 3：
//
//    输入：name = "leelee", typed = "lleeelee"
//    输出：true
//
//示例 4：
//
//    输入：name = "laiden", typed = "laiden"
//    输出：true
//    解释：长按名字中的字符并不是必要的。
//
//#
//思路
//
//这道题目一看以为是哈希，仔细一看不行，要有顺序。
//
//所以模拟同时遍历两个数组，进行对比就可以了。
//
//对比的时候需要一下几点：
//
//    name[i] 和 typed[j]相同，则i++，j++ （继续向后对比）
//    name[i] 和 typed[j]不相同
//        看是不是第一位就不相同了，也就是j如果等于0，那么直接返回false
//        不是第一位不相同，就让j跨越重复项，移动到重复项之后的位置，再次比较name[i] 和typed[j]
//            如果 name[i] 和 typed[j]相同，则i++，j++ （继续向后对比）
//            不相同，返回false
//    对比完之后有两种情况
//        name没有匹配完，例如name:"pyplrzzzzdsfa" type:"ppyypllr"
//        type没有匹配完，例如name:"alex" type:"alexxrrrrssda"

bool lc925(std::string name, std::string typed) {

}
#endif //BOOSTGEOMETRY_MYSTRING_H
