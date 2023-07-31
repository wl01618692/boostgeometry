#pragma once
#include <iostream>
#include <vector>
#include "testJson.h"
#include "complexNumber.h"
#include "boost_geometry.h"
#include "Trie.h"
#include <queue>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "dynamic_programming.h"
#include "linkedlist.h"
#include "double_ptr.h"
#include "backTrack.h"
#include "greedy.h"
#include "stack_queue.h"
#include "hashTable.h"
#include "unionfind.h"
#include "lc150mustdo.h"
#include<cstring>
using namespace std;

    //seekg()
//Moves the read position in a stream.//移动在流中读的位置
//------------------------------------------------------------------------
//basic_istream<Elem, Tr>& seekg(  //一个参数
//        pos_type pos
//);
//basic_istream<Elem, Tr>& seekg(
//        off_type off,                                     //两个参数
//        ios_base::seekdir way
//);
//------------------------------------------------------------------------
//
//参数
//        pos
//The absolute position in which to move the read pointer.
////移动读取指针的绝对位置
//
//off //偏移量
//An offset to move the read pointer relative to way.
//
//way //  基地址
//One of the ios_base::seekdir enumerations.
//它有三个取值
//        ios：：beg：表示输入流的开始位置
//        ios：：cur：表示输入流的当前位置
//        ios：：end：表示输入流的结束位置
//


class A {
public:
    A() {
        std::cout << "create" << std::endl;
    }

   ~A() {
     std::cout << "destroy" << std::endl;
   }
};

#include <vector>
#include <bitset>

using namespace std;
template <typename T>
class Base {
public:
    void func(T& container) {
        m_it = container.begin();
    }
private:
    decltype(T().begin()) m_it;  //注意这里
};

void* My_memcpy(void* dest,const void* src, size_t num)
{
    assert(dest && src);
    void* ret = dest;
    while (num--)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }
    return ret;
}

void priority_queue() {
    // priority_queue<Type, Container, Functional>
    vector<int> aa = { 1,2,4,3,8,6,1,4};
    std::priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < aa.size(); i++) {
        pq.push(aa[i]);
    }
    sort(aa.begin(), aa.end());
    for (int i = 0; i < aa.size(); i++)
        cout << aa[i] << endl;
    for (int i = 0; i < aa.size(); i++){
        cout << pq.top() << endl;
        pq.pop();
    }
}
// iterator
// random access: vector, deque
// bi-directional: map, set, list

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}

void bidirect_test() {
    std::vector<int> v{1, 2, 3, 4, 5};
    my_reverse(v.begin(), v.end());
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::list<int> l{1, 2, 3, 4, 5};
    my_reverse(l.begin(), l.end());
    for (int n : l) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    int a[] = {1, 2, 3, 4, 5};
    my_reverse(a, a + 5);
    for (int n : a) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void change(int&& right_value) {
    right_value = 8;
}

// https://zhuanlan.zhihu.com/p/335994370
int rvalue_test() {
    int a = 5; // a是个左值
    int &ref_a_left = a; // ref_a_left是个左值引用
    int &&ref_a_right = std::move(a); // ref_a_right是个右值引用

//    change(a); // 编译不过，a是左值，change参数要求右值
//    change(ref_a_left); // 编译不过，左值引用ref_a_left本身也是个左值
//    change(ref_a_right); // 编译不过，右值引用ref_a_right本身也是个左值

// std::move移动不了什么，唯一的功能是把左值强制转化为右值，返还右值引用
// 右值引用既可以是左值也可以是右值，如果有名称则为左值，否则是右值。或者说：作为函数返回值的 && 是右值，直接声明出来的 && 是左值

    change(std::move(a)); // 编译通过
    change(std::move(ref_a_right)); // 编译通过
    change(std::move(ref_a_left)); // 编译通过

    change(5); // 当然可以直接接右值，编译通过

    cout << &a << ' ';
    cout << &ref_a_left << ' ';
    cout << &ref_a_right;
    // 打印这三个左值的地址，都是一样的
}

//int main()
//{
//    int cx = 3, cy = 3; //中心坐标原点(平移)
//    int x1 = 2, y1 = 9; //左上 第二象限
//    int x2 = 2, y2 = 2; //左下 第三象限
//    int x3 = 5, y3 = 1; //右下 第四象限
//    int x4 = 6, y4 = 7; //右上 第一象限
//
//    cout << "y1 / x1: " << atan2(y1 - cy, x1 - cx) * 180 / 3.14159 << endl;
//    cout << "y2 / x2: " << atan2(y2 - cy, x2 - cx) * 180 / 3.14159 << endl;
//    cout << "y3 / x3: " << atan2(y3 - cy, x3 - cx) * 180 / 3.14159 << endl;
//    cout << "y4 / x4: " << atan2(y4 - cy, x4 - cx) * 180 / 3.14159 << endl;
//
//    return 0;
//}
//
//input
//y1 / x1: 99.4624
//y2 / x2: -135
//
//y3 / x3: -45
//y4 / x4: 53.1301
void tst_bitset() {
    std::bitset<10> b("1100110010");
    bool bit = b[3];  // 获取第 3 位
    std::bitset<3> sub = b.to_ulong() < 3 > (2);  // 从第 2 位开始获取 3 位}
    typedef std::size_t length_t, position_t; // the hints

    // constructors:
    constexpr std::bitset<4> b1;
    constexpr std::bitset<4> b2{0xA}; // == 0B1010
    std::bitset<4> b3{"0011"}; // can also be constexpr since C++23
    std::bitset<8> b4{"ABBA", length_t(4), /*0:*/'A', /*1:*/'B'}; // == 0B0000'0110

    // bitsets can be printed out to a stream:
    std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << "; b4:" << b4 << '\n';

    // bitset supports bitwise operations:
    // ^ xor
    b3 |= 0b0100; assert(b3 == 0b0111);
    b3 &= 0b0011; assert(b3 == 0b0011);
    b3 ^= std::bitset<4>{0b1100}; assert(b3 == 0b1111);

    // operations on the whole set:
    b3.reset(); assert(b3 == 0);
    b3.set(); assert(b3 == 0b1111);
    assert(b3.all() && b3.any() && !b3.none());
    b3.flip(); assert(b3 == 0);

    // operations on individual bits:
    b3.set(std::size_t(1), true); assert(b3 == 0b0010);
    b3.set(position_t(1), false); assert(b3 == 0);
    b3.flip(position_t(2)); assert(b3 == 0b0100);
    b3.reset(position_t(2)); assert(b3 == 0);

    // subscript operator[] is supported:
    b3[2] = true; assert(true == b3[2]);

    // other operations:
    assert(b3.count() == 1);
    assert(b3.size() == 4);
    assert(b3.to_ullong() == 0b0100ULL);
    assert(b3.to_string() == "0100");
}

// void *memset(void *s, int ch, size_t n);
void memsetTest() {
    // valid
//    char array[4];
//    memset(array,'1',4);

    int array[4];
    memset(array,1,16); //int所占内存为4字节的情况
    memset(array,1,sizeof(array));
}

//class Solution {
//public int[] helper(TreeNode node) {
//        // return [rob this node, not rob this node]
//        if (node == null) {
//            return new int[] { 0, 0 };
//        }
//        int left[] = helper(node.left);
//        int right[] = helper(node.right);
//        // if we rob this node, we cannot rob its children
//        int rob = node.val + left[1] + right[1];
//        // else, we free to choose rob its children or not
//        int notRob = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
//
//        return new int[] { rob, notRob };
//    }
//
//public int rob(TreeNode root) {
//        int[] answer = helper(root);
//        return Math.max(answer[0], answer[1]);
//    }
//}

std::vector<int> leetcod260(std::vector<int> nums) {
    int xor_two = nums[0];
    int last_bit = 0;
    std::vector<int> result = {0, 0};
    for (int i = 1; i < nums.size(); i++)
        xor_two ^= nums[i];
    last_bit = xor_two & (~(xor_two - 1)); //相异为1，取异或的最后一个1，把两个元素区分，然后分别对两个数组异或
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] & last_bit)
            result[0] ^= nums[i];
        else
            result[1] ^= nums[i];
    }
    return result;
}


int main() {
//    std::vector<std::vector<char>> input200 = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
//    int count = numIslandsBFS(input200);
//
//    std::vector<std::vector<char>> input200_2 = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
//    int count2 = numIslandsBFS(input200_2);
//
//    std::vector<std::vector<char>> input200_3 = {{'1','0','0','0','0'}, {'0','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','0'}, {'0','0','0','0','1'}};
//    int count3 = numIslandsBFS(input200_3);

    std::map<int, int> m1;
    m1.insert({1, 2});
    m1.insert({1, 3});

    // '0' => 48
    int tmp = ('8' - '0');
    int pos = 1 << (tmp - 1);

    std::string sb = "abcde";
    int ssss = rand() % sb.size();
    auto kksd = sb.substr(0, 2);
    std::vector<int> input268 = {1, 2, 1, 3, 2, 5};
    auto kkkk = leetcod260(input268);
    tst_bitset();

    std::cout << (-1 % 5) << std::endl;
    std::cout << cos(2 * 3.14) << std::endl;
    std::vector<int> s123 = {1,2,3};
    std::vector<int> s456 = {4,5,6};
    s123 = std::move(s456);
    std::cout << ((61) << 16) << std::endl;
    double ads = 3 / 2;
    std::cout << ads;
    std::vector<double> dd = {1, 2, 3};
    std::pair<int, int> p1 = {1, 2};
    auto ks = std::get<0> (p1);
    std::cout << std::distance(dd.begin(), dd.end()) << std::endl;
    std::cout << int('a') << std::endl;
    std::vector<double> k;
    std::cout << (k.begin() == k.end()) << std::endl;
    Trie_Test();
    json_test();
    complex_test();
    bg_test();
    gtl_test();
    bidirect_test();
    test_dp();
    linkedlist_test();
    rvalue_test();
    std::cout << integerReplacement(7) << std::endl;
    std::vector<int> g = {1, 2, 3, 4};
    std::vector<int> s = {1, 2};
    std::cout << distriuteCookie(g, s) << std::endl;
    output1047("abbaca");
    std::cout << output20("{[]}") << std::endl;
    std::cout << output20("([)]") << std::endl;
    std::cout << output20("(]") << std::endl;
    std::cout << output20("()[]{}") << std::endl;
    std::cout << output20("()") << std::endl;
//    std::vector<int> kk = {1,1,1,2,2,3};
//    topKFrequent(kk, 2);
    std::vector<int> kkk = {1,3,-1,-3, 5, 3, 6, 7};
    maxSlidingWindow(kkk, 3);
    std::cout << isAnagram("anagram", "nagaram");
    std::cout << isHappy(1);
    std::vector<std::vector<int>> edges =

            {{16,25},{7,9},{3,24},{10,20},{15,24},{2,8},{19,21},{2,15},{13,20},{5,21},{7,11},{6,23} ,{7,16},{1,8},{17,20},{4,19},{11,22},{5,11},{1,16},{14,20},{1,4},{22,23},{12,20} ,{15,18} ,{12,16}
    };

//     [16,25],[7,9],[3,24],[10,20 ,[15,24],[2,8],[19,21],[2,15],[13,20],[5,21],[7,11],[6,23],[7,16],[1,8],[17,20],[4,19],[11,22],[5,11],[1,16],[14,20],[1,4],[22,23],[12,20],[15,18],[12,16]]
    // [1,2], [2,3], [3,4], [1,4], [1,5]
//    std::vector<int> i1 = {1, 4};
//    std::vector<int> i2 = {3, 4};
//    std::vector<int> i3 = {1, 3};
//    std::vector<int> i4 = {1, 2};
//    std::vector<int> i5 = {4, 5};
    // [[1,4],[3,4],[1,3],[1,2],[4,5]]
//    edges.push_back(i1);
//    edges.push_back(i2);
//    edges.push_back(i3);
//    edges.push_back(i4);
//    edges.push_back(i5);
    findRedundantConnection(edges);
    monotoneIncreasingDigits(41114111);
    backspaceCompare("ab#c", "ad#c");
    lc844("a##c", "#a#c");
    std::vector<int> i23 = {1, 2, 1};
    nextGreaterElements(i23);
    lc2390("erase*****");
    std::vector<int> sss = {73, 74, 75, 71, 69, 72, 76, 73};
//    lc739(sss);
    testing123();
    int a = 10;
    int &b = a;  // 定义一个左值引用变量
    b = 20;      // 通过左值引用修改引用内存的值

    // 左值引用的值需要有地址，否则报错
    //int &var = 10; // error
    const int &var = 10; // works
    // same as
//    const int temp = 10;
//    const int &var = temp;

    // 可以取地址的，有名字的，非临时的就是左值；不能取地址的，没有名字的，临时的就是右值；
    // 右值引用用来绑定到右值，绑定到右值以后本来会被销毁的右值的生存期会延长至与绑定到它的右值引用的生存期。
    // 在汇编层面右值引用做的事情和常引用是相同的，即产生临时量来存储常量。但是，唯一 一点的区别是，右值引用可以进行读写操作，而常引用只能进行读操作。
    // 右值引用存放的地方在栈的附近
    // 右值引用只能引用右值，不能引用左值。
    // 右值引用可以引用move以后的左值。
    int &&var1 = 10;

    std::cout << -1e-9 << std::endl;
    std::cout << -1e-9 << std::endl;
    return 0;
}

template <typename T>
void show(T t) {
    std::cout << t << std::endl;
}

void template_test() {
    show<int>(5);
    show<void *>(nullptr);
    show<std::string>("abc");
}

template <typename... Args>
auto sum(Args... args) {
    return (... + args);
}

void Demo() {
    auto a = sum(1, 2, 3, 4); // 10
    auto b = sum(1.5, 2, 3l); // 6.5
    auto c = sum(std::string("abc"), "def", "111"); // std::string("abcdef111")
    auto d = sum(2); // 2
}

int test_union() {
    A a;
    {
        std::vector<A> vec;
        vec.push_back(a);
    }

    struct student {
        char mark;
        long num;
        float score;
    };

    union test {
        char mark;
        int num;
        int score;
    };

    std::cout << sizeof(union test) << std::endl;
    int* p;
    double* k;
    std::cout << sizeof(p) << " " << sizeof(k) << std::endl;
    std::vector<double> w;
    w.push_back(2);
    w.push_back(3);
    std::cout << *w.begin().base();
}

int test_declytype() {

    int x = 0;
    decltype(x) y = 1;           // y -> int
    decltype(x + y) z = 0;       // z -> int
    const int &i = x;
    decltype(i) j = y;           // j -> const int &
    const decltype(z) *p = &z;  // *p  -> const int, p  -> const int *
    decltype(z) *pi = &z;       // *pi -> int      , pi -> int *
    decltype(pi) *pp = &pi;      // *pp -> int *    , pp -> int * *


    // 如果exp是一个不被括号()包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，decltype(exp)的类型和exp一致
    // 如果exp是函数调用，则decltype(exp)的类型就和函数返回值的类型一致
    // 如果exp是一个左值，或被括号()包围，decltype(exp)的类型就是exp的引用，假设exp的类型为T，则decltype(exp)的类型为T&
}

// https://blog.csdn.net/CltCj/article/details/128058643 smart ptr
// https://blog.csdn.net/locahuang/article/details/119026233 smart ptr
// https://blog.csdn.net/weixin_43411585/article/details/99709274 python click
// https://blog.csdn.net/mieleizhi0522/article/details/82142856 python yield


template <typename R, typename T, typename U>
R add(T t, U u)
{
    return t+u;
}
int a = 1; float b = 2.0;
auto c = add<decltype(a + b)>(a, b);

// error
//template <typename T, typename U>
//decltype(t + u) add(T t, U u)  // error: t、u尚未定义
//{
//    return t + u;
//}

template <typename T, typename U>
decltype(T() + U()) add(T t, U u)
{
    return t + u;
}

// 考虑到 T、U 可能是没有无参构造函数的类，正确的写法应该是这样：
template <typename T, typename U>
decltype((*(T*)0) + (*(U*)0)) add(T t, U u)
{
    return t + u;
}

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
    return t + u;
}

template <typename Val>
struct str_map
{
    typedef std::map<std::string, Val> type;
};
str_map<int>::type map1;

template <typename Val>
using str_map_t = std::map<std::string, Val>;
str_map_t<int> map2;

/// lc 72
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
//
//输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
//输出：[[1,0,1],[0,0,0],[1,0,1]]
//
//输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

void setZeroes(vector<vector<int>>& matrix) {

}

