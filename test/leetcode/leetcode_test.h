//
// Created by hl4080 on 2020/6/21.
//

#ifndef LEETCODE_TEST_H
#define LEETCODE_TEST_H

#include <iostream>
#include "../../util/util.h"
#include "../../leetcode/hash/hash.h"
#include "../../leetcode/math/math.h"
#include "../../leetcode/two_pointer/two-pointer.h"
#include "../../leetcode/list/list.h"
#include "../../leetcode/dc/dc.h"
#include "../../leetcode/dp/dp.h"
#include "../../leetcode/greedy/greedy.h"

typedef void (*FUNC)();

//init function map
void initLeetMap(map<string, FUNC>& m);

//test functiions in hash directory
void test_twoSum();
void test_romanToInt();

//test functions in math directory
void test_singleNumber();
void test_zigzagConversion();
void test_reverseInteger();
void test_palindromeNumber();

//test functions in two-pointers directory
void test_happyNumber();
void test_threeSum();
void test_longestSubsting();
void test_maxWaterArea();

//test functions in list directory
void test_addTwoNumber();

//test functions in dc directory
void test_findMedianSortedArrays();

//test functions in dp diectory
void test_longestPalindromic();
void test_expressionMatch();

//test functions in greedy directory
void test_intToRoman();

#endif //LEETCODE_TEST_H