//
// Created by hl4080 on 2020/6/28.
//

#include "leetcode_test.h"

void initLeetMap(map<string, FUNC>& m) {
    //hash functions
    m["1"]   = &test_twoSum;
    m["13"]  = &test_romanToInt;
    m["36"]  = &test_validSudoku;
    m["49"]  = &test_groupAnagroups;

    //list functions
    m["2"]      = &test_addTwoNumber;
    m["19"]     = &test_removeNthFromEnd;
    m["21"]     = &test_mergeTwoSortedLists;
    m["24"]     = &test_swapPairs;

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
    m["26"]     = &test_removeDuplicate;
    m["31"]     = &test_nextPermutation;
    m["38"]     = &test_countAndSay;
    m["202"]    = &test_happyNumber;

    //dc functions
    m["4"]      = &test_findMedianSortedArrays;
    m["14"]     = &test_longestCommonPrefix;
    m["33"]     = &test_searchInRotatedArray;
    m["34"]     = &test_searchElementPositions;
    m["35"]     = &test_searchInsertPosition;

    //dp functions
    m["5"]      = &test_longestPalindromic;

    //greedy functions
    m["12"]     = &test_intToRoman;

    //recursion functions
    m["17"]     = &test_letterCombination;
    m["22"]     = &test_generateParenthesis;
    m["39"]     = &test_combinationSum;
    m["40"]     = &test_combinationSumII;
    m["46"]     = &test_permutations;
    m["47"]     = &test_uniquePermutations;
    m["48"]     = &test_rotateImage;

    //stack functions
    m["20"]     = &test_validParenthess;
}
