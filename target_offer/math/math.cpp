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
    return pow(2, number);
}
