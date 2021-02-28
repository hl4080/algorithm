//
// Created by hl4080 on 2021/1/24.
//

#include "leetcode/leetcode_test.h"
#include "target_offer/target_offer_test.h"

void initProblemMap(map<string, FUNC>& m) {
    /********************* leetcode problems **********************/
    //hash functions
    m["l1"]   = &test_twoSum;
    m["l13"]  = &test_romanToInt;
    m["l36"]  = &test_validSudoku;
    m["l49"]  = &test_groupAnagroups;
    m["l187"] = &test_findRepeatDnaSequence;
    m["l205"] = &test_isIsomorphic;
    m["l217"] = &test_containDuplicate;
    m["l219"] = &test_containDuplicatesII;
    m["l220"] = &test_containduplicateIII;
    m["l347"] = &test_topKfrequent;
    m["l373"] = &test_kSmallestPairs;
    m["l433"] = &test_miniumGeneticMutation;
    m["l454"] = &test_fourSumCount;

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
    m["l203"]    = &test_removeElements;
    m["l206"]    = &test_reverseList;
    m["l234"]    = &test_ispalindromeList;
    m["l237"]    = &test_deleteNode;
    m["l328"]    = &test_oddEvenList;
    m["l445"]    = &test_ddTwoNumbersII;

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
    m["l169"]    = &test_majorityElement;
    m["l172"]    = &test_trailingZeros;
    m["l179"]    = &test_largestNumber;
    m["l189"]    = &test_rotateArray;
    m["l190"]    = &test_reverseBits;
    m["l191"]    = &test_hammingWeight;
    m["l201"]    = &test_rangeBitwiseAnd;
    m["l204"]    = &test_countPrimes;
    m["l229"]    = &test_majorityElementsII;
    m["l238"]    = &test_productExceptSelf;
    m["l258"]    = &test_addDigits;
    m["l260"]    = &test_singleNumberIII;
    m["l268"]    = &test_missingNumber;
    m["l274"]    = &test_hIndex;
    m["l275"]    = &test_hIndexII;
    m["l292"]    = &test_canWinNim;
    m["l334"]    = &test_increasingTriplet;
    m["l343"]    = &test_integerBreak;
    m["l357"]    = &test_countNumbersWithUnqiueDigits;
    m["l367"]    = &test_isPerfectSquare;
    m["l371"]    = &test_getSum;
    m["l372"]    = &test_superPow;
    m["l390"]    = &test_lastRemain;
    m["l397"]    = &test_integerReplacement;
    m["l398"]    = &test_randomPickIndex;
    m["l400"]    = &test_findNthDigit;
    m["l442"]    = &test_findAllDuplicates;
    m["l448"]    = &test_findAllDisappear;
    m["l453"]    = &test_minMoves;

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
    m["l167"]    = &test_twoSumII;
    m["l202"]    = &test_happyNumber;
    m["l209"]    = &test_minSubarrayLen;
    m["l240"]    = &test_searchMatrixII;
    m["l264"]    = &test_nthUglyNumber;
    m["l283"]    = &test_moveZeros;
    m["l287"]    = &test_findDuplicate;
    m["l313"]    = &test_nthSuperUglyNumber;
    m["l424"]    = &test_ongestRepeatingCharacterReplacement;

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
    m["l215"]    = &test_findKLargest;
    m["l241"]    = &test_diffWaysToCompute;
    m["l324"]    = &test_wiggleSortII;
    m["l378"]    = &test_kthSmallestMatrix;
    m["l395"]    = &test_longestSubstrWithKRepeatingchar;

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
    m["l198"]    = &test_houseRob;
    m["l213"]    = &test_houseRobII;
    m["l221"]    = &test_maximalSquare;
    m["l279"]    = &test_numSquare;
    m["l300"]    = &test_lengthOfLIS;
    m["l338"]    = &test_countBits;
    m["l368"]    = &test_largestDivisibleSubset;
    m["l375"]    = &test_getMoneyCount;
    m["l376"]    = &test_wiggleMaxLength;
    m["l377"]    = &test_combinationSum4;
    m["l396"]    = &test_rotateFunction;
    m["l416"]    = &test_partitionEqualSum;

    //greedy functions
    m["l12"]     = &test_intToRoman;
    m["l55"]     = &test_jumpGame;
    m["l134"]    = &test_canCompleteCircuit;
    m["l435"]    = &test_nonOverlappingIntervals;

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
    m["l200"]    = &test_numIsland;
    m["l216"]    = &test_combinationSum3;
    m["l386"]    = &test_lexicalOrder;

    //stack functions
    m["l20"]     = &test_validParenthess;
    m["l71"]     = &test_simplifyPath;
    m["l150"]    = &test_evalPRN;
    m["l225"]    = &test_mystack;
    m["l227"]    = &test_calculator;
    m["l232"]    = &test_myQueue;
    m["l394"]    = &test_decodeString;
    m["l402"]    = &test_removeKDigits;

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
    m["l199"]    = &test_rightSideView;
    m["l222"]    = &test_countNodes;
    m["l226"]    = &test_invertBinaryTree;
    m["l230"]    = &test_kthSmallestElementBST;
    m["l235"]    = &test_lowestCommonAncestor;
    m["l236"]    = &test_lowestCommonAncestorII;
    m["l257"]    = &test_binaryTreePath;
    m["l310"]    = &test_findMinHeightTrees;
    m["l337"]    = &test_houseRobIII;
    m["l404"]    = &test_sumOfLeafNodes;
    m["l437"]    = &test_pathSumIII;
    m["l450"]    = &test_deleteTreeNode;

    //graph functions
    m["l127"]    = &test_ladderLength;
    m["l207"]    = &test_courseSchedule;
    m["l210"]    = &test_courseScheduleII;
    m["l332"]    = &test_findItinerary;

    /********************* target offer problems **********************/

    //ararry function
    m["o1"]     = &test_find;
    m["o13"]    = &test_reorderArray;
    m["o19"]    = &test_printMatrix;
    m["o28"]    = &test_morethanHalf;
    m["o29"]    = &test_leastKNumbers;
    m["o32"]    = &test_minStringVal;
    m["o33"]    = &test_uglyNumber;
    m["o35"]    = &test_reversePairs;
    m["o37"]    = &test_getNumberOfK;
    m["o41"]    = &test_continuousSequence;
    m["o42"]    = &test_numberWithSum;
    m["o45"]    = &test_isContinous;
    m["o50"]    = &test_duplicate;
    m["o51"]    = &test_multiplyArray;

    //string functions
    m["o2"]     = &test_replaceSpace;
    m["o27"]    = &test_permutation;
    m["o34"]    = &test_firstNotRepeatChar;
    m["o43"]    = &test_leftRotatedString;
    m["o44"]    = &test_reverseSentence;
    m["o49"]    = &test_string2int;
    m["o54"]    = &test_stringFirstAppear;

    //list functions
    m["o3"]     = &test_printReverseList;
    m["o14"]    = &test_FindKthToTail;
    m["o15"]    = &test_reverList;
    m["o16"]    = &test_merge;
    m["o25"]    = &test_cloneRandomList;
    m["o36"]    = &test_findFirstCommon;
    m["o55"]    = &test_listCycleNode;

    //tree functions
    m["o4"]     = &test_reconstructTree;
    m["o17"]    = &test_subTree;
    m["o18"]    = &test_Mirror;
    m["o22"]    = &test_printTreeLevel;
    m["o23"]    = &test_verifyBST;
    m["o24"]    = &test_findPath;
    m["o26"]    = &test_convert2List;
    m["o38"]    = &test_treeDepth;
    m["o39"]    = &test_IsBalancedTree;

    //stack function
    m["o5"]     = &test_myStack;
    m["o20"]    = &test_minStack;
    m["o21"]    = &test_isPopOrder;

    //dc function
    m["o6"]     = &test_minRotateArray;

    //dp function
    m["o7"]     = &test_fibonacci;
    m["o8"]     = &test_jumpFloor;
    m["o10"]    = &test_rectCover;
    m["o30"]    = &test_greatestSubarray;
    m["o46"]    = &test_josephCircle;
    m["o52"]    = &test_matchPattern;

    //math function
    m["o9"]     = &test_jumpFloorII;
    m["o11"]    = &test_numberOf1;
    m["o12"]    = &test_power;
    m["o31"]    = &test_numberOf1s;
    m["o40"]    = &test_appearOnce;
    m["o47"]    = &test_specialSum;
    m["o48"]    = &test_specialAdd;
}
