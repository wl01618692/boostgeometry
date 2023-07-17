//
// Created by zhangjiayuan on 23-7-14.
//

#ifndef BOOSTGEOMETRY_FIRFILTER_H
#define BOOSTGEOMETRY_FIRFILTER_H
#define N 11
//#include "ap_int.h"

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

// 该代码设计为流函数。它一次只接收一个数据，因此它必须存储以前的数据。
// 由于这是一个11阶滤波器，我们必须存储之前的10个数据。
// 这是shift_reg[]矩阵的作用。因为矩阵数据在函数中被多次调用，所以该矩阵声明为静态类型。

// 编程实现11阶FIR滤波器代码如图2.1。这个函数有两个端口，一个端口是输入数据x和另一个端口是输出结果y。
// 由于每次执行该函数会提供一个函数输入数据并接收一个函数输出数据，
// 多次调用这个函数后，完成整个输出信号的计算。因为我们在获取更多信号时这段代码可以根据需求调用很多次，所以这段代码可以方便地用流模式架构进行建模。

// 每次 for 循环有两个基本运算。首先，它对输入数据执行乘累加操作(当前输入数据x和存储在shift_reg[]中之前输入的数据)。
// 每次循环执行一个常量与一个输入数据的乘法，并将求和结果存储在变量acc中。
// 同时该循环通过shift_array来实现数值移动，它的操作行为像FIFO。它存储输入数据x到shift_reg[0]中，并通过shift_reg将之前的元素“向前”移动:

void fir(data_t *y,data_t x){
    coef_t C[N] = {
            53,0,-91,0,313,500,313,0,-91,0,53
    };
    // 滤波器系数存储在函数内部声明的数组c[]中，定义为静态常数。
    // 注意系数是对称的。即它们以中心值c[5] = 500为镜像对称。
    // 许多FIR滤波器具有这种对称性。我们可以利用这个特点来减少数组c[]所需的存储容量。
    static data_t shift_reg[N];
    acc_t acc;
    int i;
    acc = 0;
    for(i = N - 1;i >= 0;i--){
        if(i == 0){
            acc += x * C[0];
            shift_reg[0] = x;
        }else {
            shift_reg[i] = shift_reg[i - 1];
            acc += shift_reg[i] * C[i];
        }
    }
    * y = acc;
}

//shift_array[10] = shift_array[9]
//shift_array[9] = shift_array[8]
//shift_array[8] = shift_array[7]
//...
//shift_array[2] = shift_array[1]
//shift_array[1] = shift_array[0]
//shift_array[0] = x

#endif //BOOSTGEOMETRY_FIRFILTER_H
