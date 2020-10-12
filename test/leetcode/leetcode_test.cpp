//
// Created by hl4080 on 2020/6/28.
//

#include "leetcode_test.h"

void initLeetMap(map<string, FUNC>& m) {
    //hash functions
    m["l1"]   = &test_twoSum;
    m["l13"]  = &test_romanToInt;
    m["l36"]  = &test_validSudoku;
    m["l49"]  = &test_groupAnagroups;

    //list functions
    m["l2"]      = &test_addTwoNumber;
    m["l19"]     = &test_removeNthFromEnd;
    m["l21"]     = &test_mergeTwoSortedLists;
    m["l24"]     = &test_swapPairs;
    m["l61"]     = &test_rotateList;
    m["l82"]     = &test_deleteDuplicatesListII;
    m["l83"]     = &test_deleteDuplicateList;
    m["l86"]     = &test_partitionList;
    m["l92"]     = &test_reverseListBetween;
    m["l141"]    = &test_listCycle;
    m["l142"]    = &test_listCycleII;
    m["l143"]    = &test_reorderList;
    m["l147"]    = &test_insertSortList;
    m["l148"]    = &test_sortList;
    m["l160"]    = &test_interationList;
    m["l206"]    = &test_reverseList;

    //math functions
    m["l136"]    = &test_singleNumber;
    m["l6"]      = &test_zigzagConversion;
    m["l7"]      = &test_reverseInteger;
    m["l9"]      = &test_palindromeNumber;
    m["l10"]     = &test_expressionMatch;
    m["l62"]     = &test_uniquePaths;
    m["l69"]     = &test_sqrtx;
    m["l73"]     = &test_setMatrixZeros;
    m["l118"]    = &test_generatePascalTriange;
    m["l119"]    = &test_getRowPascalTriangle;
    m["l137"]    = &test_singlenumberII;

    //two_pointer functions
    m["l3"]      = &test_longestSubsting;
    m["l11"]     = &test_maxWaterArea;
    m["l15"]     = &test_threeSum;
    m["l16"]     = &test_threeSumClosest;
    m["l26"]     = &test_removeDuplicate;
    m["l31"]     = &test_nextPermutation;
    m["l38"]     = &test_countAndSay;
    m["l56"]     = &test_mergeIntervals;
    m["l75"]     = &test_sortColors;
    m["l80"]     = &test_removeDeplicateII;
    m["l88"]     = &test_mergeSortedArrays;
    m["l151"]    = &test_reverseWords;
    m["l165"]    = &test_compareVersion;
    m["l202"]    = &test_happyNumber;

    //dc functions
    m["l4"]      = &test_findMedianSortedArrays;
    m["l14"]     = &test_longestCommonPrefix;
    m["l33"]     = &test_searchInRotatedArray;
    m["l34"]     = &test_searchElementPositions;
    m["l35"]     = &test_searchInsertPosition;
    m["l74"]     = &test_searchMatrix;
    m["l81"]     = &test_searchRotatedSortedArrayII;
    m["l153"]    = &test_findMinSortedArray;
    m["l162"]    = &test_findPeekElement;

    //dp functions
    m["l5"]      = &test_longestPalindromic;
    m["l53"]     = &test_maximumSubarray;
    m["l63"]     = &test_uniquePathWithObstacles;
    m["l64"]     = &test_minPathSum;
    m["l70"]     = &test_climbStairs;
    m["l91"]     = &test_numDecodings;
    m["l96"]     = &test_numTrees;
    m["l121"]    = &test_maxProfitI;
    m["l122"]    = &test_maxProfitII;
    m["l139"]    = &test_wordBreak;
    m["l152"]    = &test_maxProductSubarray;

    //greedy functions
    m["l12"]     = &test_intToRoman;
    m["l55"]     = &test_jumpGame;
    m["l134"]    = &test_canCompleteCircuit;

    //recursion functions
    m["l17"]     = &test_letterCombination;
    m["l22"]     = &test_generateParenthesis;
    m["l39"]     = &test_combinationSum;
    m["l40"]     = &test_combinationSumII;
    m["l46"]     = &test_permutations;
    m["l47"]     = &test_uniquePermutations;
    m["l48"]     = &test_rotateImage;
    m["l60"]     = &test_getPermutation;
    m["l77"]     = &test_combinations;
    m["l78"]     = &test_subsets;
    m["l79"]     = &test_wordExistBoard;
    m["l89"]     = &test_grayCode;
    m["l90"]     = &test_subesetsWithDup;
    m["l93"]     = &test_restoreIpAddr;
    m["l120"]    = &test_minPathTriangle;
    m["l130"]    = &test_surroundRegions;
    m["l131"]    = &test_palinfromePartition;

    //stack functions
    m["l20"]     = &test_validParenthess;
    m["l71"]     = &test_simplifyPath;
    m["l150"]    = &test_evalPRN;

    //tree functions
    m["l94"]     = &test_inorderTreeTravel;
    m["l95"]     = &test_generateTreesII;
    m["l98"]     = &test_isValidTree;
    m["l100"]    = &test_isSameTree;
    m["l101"]    = &test_isSymmetric;
    m["l102"]    = &test_levelOrder;
    m["l103"]    = &test_zigzagOrder;
    m["l104"]    = &test_maxDepth;
    m["l105"]    = &test_buildTreeFromPreAndInorder;
    m["l106"]    = &test_buildTressFromInAndPostOrder;
    m["l108"]    = &test_sortedArrayToBST;
    m["l109"]    = &test_sortedListToBST;
    m["l110"]    = &test_isBalancedTree;
    m["l111"]    = &test_minDepth;
    m["l112"]    = &test_hasPathSum;
    m["l113"]    = &test_pathSum;
    m["l114"]    = &test_flattenTree;
    m["l129"]    = &test_sumRootToLeaf;

    //graph functions
    m["l127"]    = &test_ladderLength;
}
