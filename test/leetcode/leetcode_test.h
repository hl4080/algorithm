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
#include "../../leetcode/tree/tree.h"
#include "../../leetcode/graph/graph.h"

typedef void (*FUNC)();

//init function map
void initLeetMap(map<string, FUNC>& m);



//test functiions in hash directory
void test_twoSum();
void test_romanToInt();
void test_validSudoku();
void test_groupAnagroups();
void test_findRepeatDnaSequence();
void test_isIsomorphic();
void test_containDuplicate();
void test_containDuplicatesII();
void test_containduplicateIII();
void test_topKfrequent();
void test_kSmallestPairs();

//test functions in math directory
void test_singleNumber();
void test_zigzagConversion();
void test_reverseInteger();
void test_palindromeNumber();
void test_uniquePaths();
void test_sqrtx();
void test_setMatrixZeros();
void test_generatePascalTriange();
void test_getRowPascalTriangle();
void test_singlenumberII();
void test_majorityElement();
void test_trailingZeros();
void test_largestNumber();
void test_rotateArray();
void test_reverseBits();
void test_hammingWeight();
void test_rangeBitwiseAnd();
void test_countPrimes();
void test_majorityElementsII();
void test_productExceptSelf();
void test_addDigits();
void test_singleNumberIII();
void test_missingNumber();
void test_hIndex();
void test_hIndexII();
void test_canWinNim();
void test_increasingTriplet();
void test_integerBreak();
void test_countNumbersWithUnqiueDigits();
void test_isPerfectSquare();
void test_getSum();
void test_superPow();
void test_lastRemain();
void test_integerReplacement();
void test_randomPickIndex();
void test_findNthDigit();

//test functions in two-pointers directory
void test_happyNumber();
void test_threeSum();
void test_longestSubsting();
void test_maxWaterArea();
void test_threeSumClosest();
void test_removeDuplicate();
void test_nextPermutation();
void test_countAndSay();
void test_mergeIntervals();
void test_sortColors();
void test_removeDeplicateII();
void test_mergeSortedArrays();
void test_reverseWords();
void test_compareVersion();
void test_twoSumII();
void test_minSubarrayLen();
void test_searchMatrixII();
void test_nthUglyNumber();
void test_moveZeros();
void test_findDuplicate();
void test_nthSuperUglyNumber();
void test_ongestRepeatingCharacterReplacement();

//test functions in list directory
void test_addTwoNumber();
void test_removeNthFromEnd();
void test_mergeTwoSortedLists();
void test_swapPairs();
void test_rotateList();
void test_deleteDuplicatesListII();
void test_deleteDuplicateList();
void test_partitionList();
void test_reverseListBetween();
void test_listCycle();
void test_listCycleII();
void test_reverseList();
void test_reorderList();
void test_insertSortList();
void test_sortList();
void test_interationList();
void test_removeElements();
void test_ispalindromeList();
void test_deleteNode();
void test_oddEvenList();

//test functions in dc directory
void test_findMedianSortedArrays();
void test_longestCommonPrefix();
void test_searchInRotatedArray();
void test_searchElementPositions();
void test_searchInsertPosition();
void test_rotateImage();
void test_searchMatrix();
void test_searchRotatedSortedArrayII();
void test_findMinSortedArray();
void test_findPeekElement();
void test_findKLargest();
void test_diffWaysToCompute();
void test_wiggleSortII();
void test_kthSmallestMatrix();
void test_longestSubstrWithKRepeatingchar();

//test functions in dp diectory
void test_longestPalindromic();
void test_expressionMatch();
void test_maximumSubarray();
void test_uniquePathWithObstacles();
void test_minPathSum();
void test_climbStairs();
void test_numDecodings();
void test_numTrees();
void test_maxProfitI();
void test_maxProfitII();
void test_wordBreak();
void test_maxProductSubarray();
void test_houseRob();
void test_houseRobII();
void test_maximalSquare();
void test_numSquare();
void test_lengthOfLIS();
void test_countBits();
void test_largestDivisibleSubset();
void test_getMoneyCount();
void test_wiggleMaxLength();
void test_combinationSum4();
void test_rotateFunction();
void test_partitionEqualSum();

//test functions in greedy directory
void test_intToRoman();
void test_jumpGame();
void test_grayCode();
void test_canCompleteCircuit();

//test functions in recursion directory
void test_letterCombination();
void test_generateParenthesis();
void test_combinationSum();
void test_combinationSumII();
void test_permutations();
void test_uniquePermutations();
void test_getPermutation();
void test_combinations();
void test_subsets();
void test_wordExistBoard();
void test_subesetsWithDup();
void test_restoreIpAddr();
void test_minPathTriangle();
void test_surroundRegions();
void test_palinfromePartition();
void test_numIsland();
void test_combinationSum3();
void test_lexicalOrder();

//test functions in stack directory
void test_validParenthess();
void test_simplifyPath();
void test_evalPRN();
void test_mystack();
void test_calculator();
void test_myQueue();
void test_decodeString();
void test_removeKDigits();

//test funtions in tree directory
void test_inorderTreeTravel();
void test_generateTreesII();
void test_isValidTree();
void test_isSameTree();
void test_isSymmetric();
void test_levelOrder();
void test_zigzagOrder();
void test_maxDepth();
void test_buildTreeFromPreAndInorder();
void test_buildTressFromInAndPostOrder();
void test_sortedArrayToBST();
void test_sortedListToBST();
void test_isBalancedTree();
void test_minDepth();
void test_hasPathSum();
void test_pathSum();
void test_flattenTree();
void test_sumRootToLeaf();
void test_rightSideView();
void test_countNodes();
void test_invertBinaryTree();
void test_kthSmallestElementBST();
void test_lowestCommonAncestor();
void test_lowestCommonAncestorII();
void test_binaryTreePath();
void test_findMinHeightTrees();
void test_houseRobIII();
void test_sumOfLeafNodes();

//functions in graph directory
void test_ladderLength();
void test_courseSchedule();
void test_courseScheduleII();
void test_findItinerary();

#endif //LEETCODE_TEST_H