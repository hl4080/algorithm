//
// Created by hl4080 on 2020/7/2.
//

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
*/

#include "math.h"

int reverseInteger(int x) {
    long result = 0;
    while(x != 0) {
        result = result*10 + x%10;
        x /= 10;
    }
    if(result > INT_MAX  || result < INT_MIN) return 0;
    return result;
}