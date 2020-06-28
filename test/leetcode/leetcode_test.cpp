//
// Created by hl4080 on 2020/6/28.
//

#include "leetcode_test.h"

void initLeetMap(map<string, FUNC>& m) {
    //hash functions
    m["1"]      = &test_twoSum;

    //list functions
    m["2"]      = &test_addTwoNumber;

    //math functions
    m["136"]    = &test_singleNumber;

    //two_pointer functions
    m["3"]      = &test_longestSubsting;
    m["15"]     = &test_threeSum;
    m["202"]    = &test_happyNumber;

    //dc functions
    m["4"]      = &test_findMedianSortedArrays;
}
