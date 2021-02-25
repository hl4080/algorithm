//
// Created by hl4080 on 2021/1/28.
//

#include "math.h"


/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
示例1
输入

3
返回值

4
 */

int jumpFloorII(int number) {
    return pow(2, number-1);
}

/*
 * 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
示例1
输入

10
返回值

2
 */

int  NumberOf1(int n) {
    int val = n;
    int res = 0;
    while(val) {
        res++;
        val &= (val-1);
    }
    return res;
}

/*
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
示例1
输入

2,3
返回值

8.00000
 */

double Power(double base, int exponent) {
    if(exponent<0) {
        base = 1/base;
        exponent = -exponent;
    }
    double res = 1.0;
    double b = base;
    while(exponent) {
        if(exponent&1) res *= b;
        b *= b;
        exponent = exponent>>1;
    }
    return res;
}

/*
 * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
示例1
输入

13
返回值

6
*/

int NumberOf1Between1AndN(int n) {
    int digit = 1, high = n/10, low = 0, cur = n%10, res = 0;
    while(high>0 || cur>0) {
        if(cur == 0) res += high*digit;
        else if(cur == 1) res += high*digit+low+1;
        else res += (high+1)*digit;
        low = cur*digit+low;
        cur = high%10;
        high = high/10;
        digit *= 10;
    }
    return res;
}

/*
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int ret = 0;
    for(int i=0; i<data.size(); i++) ret ^= data[i];
    int flag = 1;
    while(!(ret&flag)) flag <<= 1;
    *num1 = 0, *num2 = 0;
    for(int i=0; i<data.size(); i++) {
        if(data[i]&flag) *num1 ^= data[i];
        else *num2 ^= data[i];
    }
}

/*
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
示例1
输入

5
返回值

15
 */

int SpecialSum(int n) {
    bool x = n>1 && (n+=SpecialSum(n-1));
    return n;
}