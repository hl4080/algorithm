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
#include "../../leetcode/recursion/recursion.h"
#include "../../leetcode/stack/stack.h"

typedef void (*FUNC)();

//init function map
void initLeetMap(map<string, FUNC>& m);



//test functiions in hash directory
void test_twoSum();
void test_romanToInt();
void test_validSudoku();
void test_groupAnagroups();

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
void test_threeSumClosest();
void test_removeDuplicate();
void test_nextPermutation();
void test_countAndSay();

//test functions in list directory
void test_addTwoNumber();
void test_removeNthFromEnd();
void test_mergeTwoSortedLists();
void test_swapPairs();

//test functions in dc directory
void test_findMedianSortedArrays();
void test_longestCommonPrefix();
void test_searchInRotatedArray();
void test_searchElementPositions();
void test_searchInsertPosition();
void test_rotateImage();

//test functions in dp diectory
void test_longestPalindromic();
void test_expressionMatch();
void test_maximumSubarray();

//test functions in greedy directory
void test_intToRoman();
void test_jumpGame();

//test functions in recursion directory
void test_letterCombination();
void test_generateParenthesis();
void test_combinationSum();
void test_combinationSumII();
void test_permutations();
void test_uniquePermutations();

//test functions in stack directory
void test_validParenthess();

#endif //LEETCODE_TEST_H