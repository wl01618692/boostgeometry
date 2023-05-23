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

using namespace std;
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

int main() {
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
    std::vector<int> kk = {1,1,1,2,2,3};
    topKFrequent(kk, 2);
    std::vector<int> kkk = {1,3,-1,-3, 5, 3, 6, 7};
    maxSlidingWindow(kkk, 3);
    std::cout << isAnagram("anagram", "nagaram");
    std::cout << isHappy(1);
    std::vector<std::vector<int>> edges;

    // [16,25],[7,9],[3,24],[10,20],[15,24],[2,8],[19,21],[2,15],[13,20],[5,21],[7,11],[6,23],[7,16],[1,8],[17,20],[4,19],[11,22],[5,11],[1,16],[14,20],[1,4],[22,23],[12,20],[15,18],[12,16]]
    // [1,2], [2,3], [3,4], [1,4], [1,5]
    std::vector<int> i1 = {1, 2};
    std::vector<int> i2 = {1, 3};
    std::vector<int> i3 = {2, 3};
    // [[1,4],[3,4],[1,3],[1,2],[4,5]]
    edges.push_back(i1);
    edges.push_back(i2);
    edges.push_back(i3);
    findRedundantConnection(edges);
    monotoneIncreasingDigits(41114111);
    backspaceCompare("ab#c", "ad#c");
    lc844("a##c", "#a#c");
    lc2390("erase*****");
    std::vector<int> sss = {73, 74, 75, 71, 69, 72, 76, 73};
    lc739(sss);
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

