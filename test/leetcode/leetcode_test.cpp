//
// Created by hl4080 on 2020/6/28.
//

#include "leetcode_test.h"

void initLeetMap(map<string, FUNC>& m) {
    //hash functions
    m["1"]   = &test_twoSum;
    m["13"]  = &test_romanToInt;

    //list functions
    m["2"]      = &test_addTwoNumber;
    m["19"]     = &test_removeNthFromEnd;
    m["21"]     = &test_mergeTwoSortedLists;

    //math functions
    m["136"]    = &test_singleNumber;
    m["6"]      = &test_zigzagConversion;
    m["7"]      = &test_reverseInteger;
    m["9"]      = &test_palindromeNumber;
    m["10"]     = &test_expressionMatch;

    //two_pointer functions
    m["3"]      = &test_longestSubsting;
    m["11"]     = &test_maxWaterArea;
    m["15"]     = &test_threeSum;
    m["16"]     = &test_threeSumClosest;
    m["202"]    = &test_happyNumber;

    //dc functions
    m["4"]      = &test_findMedianSortedArrays;
    m["14"]     = &test_longestCommonPrefix;

    //dp functions
    m["5"]      = &test_longestPalindromic;

    //greedy functions
    m["12"]     = &test_intToRoman;

    //recursion functions
    m["17"]     = &test_letterCombination;
    m["22"]     = &test_generateParenthesis;

    //stack functions
    m["20"]     = &test_validParenthess;
}
