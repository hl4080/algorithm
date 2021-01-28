//
// Created by hl4080 on 2021/1/28.
//

#include "dp.h"

/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n≤39

示例1
输入
复制
4
返回值
复制
3
 */

int Fibonacci(int n) {
    if(!n) return 0;
    int t0 = 0, t1 = 1;
    for(int i=2; i<=n; i++) {
        int tmp = t1;
        t1 += t0;
        t0 = tmp;
    }
    return t1;
}