//
// Created by hl4080 on 2020/6/28.
//

#include "leetcode_test.h"

void initLeetMap(map<string, FUNC>& m) {
    //hash functions
    m["1"]   = &test_twoSum;

    //list functions
    m["2"]      = &test_addTwoNumber;

    //math functions
    m["136"]    = &test_singleNumber;
    m["6"]      = &test_zigzagConversion;
    m["7"]      = &test_reverseInteger;
    m["9"]      = &test_palindromeNumber;
    m["10"]     = &test_expressionMatch;

    //two_pointer functions
    m["3"]      = &test_longestSubsting;
    m["15"]     = &test_threeSum;
    m["11"]     = &test_maxWaterArea;
    m["202"]    = &test_happyNumber;

    //dc functions
    m["4"]      = &test_findMedianSortedArrays;

    //dp functions
    m["5"]      = &test_longestPalindromic;
}
