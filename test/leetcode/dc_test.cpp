//
// Created by hl4080 on 2020/6/27.
//

#include "leetcode_test.h"

void test_findMedianSortedArrays() {
    cout<<"============simple test find-median-sorted-arrays begin============="<<endl;
    vector<int> vec1{1, 3, 4, 9};
    vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    double result = findMedianSortedArrays(vec1, vec2);
    double desired = 4;
    cout<<"test case: "<<endl;
    cout<<"vec1: ";
    printOneDimVec(vec1);
    cout<<"vec2: ";
    printOneDimVec(vec2);
    if(result == desired){
        cout<<"result of test case 1: "<<desired<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test find-median-sorted-arrays begin============="<<endl;
}

void test_longestCommonPrefix() {
    cout<<"============simple test longest-common-prefix begin============="<<endl;
    vector<string> vec1{"flower","flow","flight"};
    vector<string> vec2{"dog","racecar","car"};
    string res1 = longestCommonPrefix(vec1);
    string res2 = longestCommonPrefix(vec2);
    string desired1 = "fl";
    string desired2 = "";
    cout<<"test case 1: ";
    printOneDimVec(vec1);
    cout<<"test case 2: ";
    printOneDimVec(vec2);
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cout<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test longest-common-prefix end==============="<<endl;
}

void test_searchInRotatedArray() {
    cout<<"============simple test search-in-rotated-array begin============="<<endl;
    vector<int> nums{4,5,6,7,0,1,2};
    int target1 = 0, target2 = 3;
    int res1 = searchInRotatedArray(nums, target1), res2 = searchInRotatedArray(nums, target2);
    int desired1 = 4, desired2 = -1;
    cout<<"test case: ";
    printOneDimVec(nums);
    cout<<"target1: "<<target1<<endl;
    cout<<"target2: "<<target2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test search-in-rotated-array end==============="<<endl;
}

void test_searchElementPositions() {
    cout<<"============simple test search-element-positions begin============="<<endl;
    vector<int> nums{5,7,7,8,8,10};
    int target1 = 8, target2 = 6;
    vector<int> res1 = searchElementPositions(nums, target1), res2 = searchElementPositions(nums, target2);
    vector<int> desired1{3, 4}, desired2{-1, -1};
    cout<<"test case nums: ";
    printOneDimVec(nums);
    cout<<"target1: "<<target1<<endl;
    cout<<"target2: "<<target2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"test of test case 1: ";
        printOneDimVec(res1);
        cout<<"result of test case 2:";
        printOneDimVec(res2);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test search-element-positions end==============="<<endl;
}

void test_searchInsertPosition() {
    cout<<"============simple test search-insert-position begin============="<<endl;
    vector<int> nums{1, 3, 5, 6};
    int target1 = 5, target2 = 2;
    int res1 = searchInsertPosition(nums, target1), res2 = searchInsertPosition(nums, target2);
    int desired1 = 2, desired2 = 1;
    cout<<"test case nums: ";
    printOneDimVec(nums);
    cout<<"target 1: "<<target1<<endl;
    cout<<"target 2: "<<target2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEAT STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test search-insert-position end==============="<<endl;
}

void test_rotateImage() {
    cout<<"============simple test rotate-image begin============="<<endl;
    vector<vector<int>> matrix{
            {5, 1, 9,11},
            {2, 4, 8,10},
            {13, 3, 6, 7},
            {15,14,12,16}
    };
    rotateImage(matrix);
    vector<vector<int>> desired{
            {15,13, 2, 5},
            {14, 3, 4, 1},
            {12, 6, 8, 9},
            {16, 7,10,11}
    };
    cout<<"test case matrix: "<<endl;
    printTwoDimVec(matrix);
    if(matrix == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(matrix);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test rotate-image end==============="<<endl;
}

void test_searchMatrix() {
    cout<<"============simple test search matrix begin============="<<endl;
    vector<vector<int>> matrix{
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    int target = 11;
    cout<<"test case: "<<endl;
    cout<<"matrix: "<<endl;
    printTwoDimVec(matrix);
    cout<<"target: "<<target<<endl;
    bool res = searchMatrix(matrix, target), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test search matrix end==============="<<endl;
}

void test_searchRotatedSortedArrayII() {
    cout<<"============simple test search rotated sorted array II begin============="<<endl;
    vector<int> nums{2,5,6,0,0,1,2};
    int target = 0;
    bool res = searchRotatedArrayII(nums, target), desired = true;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"target: "<<target<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test search rotated sorted array II end==============="<<endl;
}

void test_findMinSortedArray() {
    cout<<"============simple test find minimum in sorted array begin============="<<endl;
    vector<int> nums{4,5,6,7,0,1,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = findMinSortedArray(nums), desired = 0;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find minimum in sorted array end==============="<<endl;
}

void test_findPeekElement() {
    cout<<"============simple test find peek element begin============="<<endl;
    vector<int> nums{1,2,3,1};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = findPeakElement(nums), desired = 2;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find peek element end==============="<<endl;
}

void test_findKLargest() {
    cout<<"============simple test find kth largest element begin============="<<endl;
    vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"k="<<k<<endl;
    int res = findKthLargest(nums, k), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find kth largest element end==============="<<endl;
}

void test_diffWaysToCompute() {
    cout<<"============simple test different ways to compute begin============="<<endl;
    string input = "2*3-4*5";
    cout<<"test case: "<<input<<endl;
    vector<int> res = diffWaysToCompute(input), desired{-34, -10, -14, -10, 10};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test different ways to compute end==============="<<endl;
}

void test_wiggleSortII() {
    cout<<"============simple test wiggle sort II begin============="<<endl;
    vector<int> nums{1, 5, 1, 1, 6, 4};
    cout<<"test case:";
    printOneDimVec(nums);
    wiggleSortII(nums);
    vector<int> desired{1,6,1,5,1,4};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test wiggle sort II end==============="<<endl;
}

void test_kthSmallestMatrix() {
    cout<<"============simple test kth smallest matrix begin============="<<endl;
    vector<vector<int>> matrix{
            {1,5,9},
            {10,11,13},
            {12,13,15}
    };
    int k = 8;
    cout<<"test case"<<endl;
    cout<<"matrix: "<<endl;
    printTwoDimVec(matrix);
    cout<<"k="<<k<<endl;
    int res = kthSmallestMatrix(matrix, k), desired = 13;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test kth smallest matrix end==============="<<endl;
}

void test_longestSubstrWithKRepeatingchar() {
    cout<<"============simple test longest substr with k repeating chars begin============="<<endl;
    string s = "ababbc";
    int k = 2;
    cout<<"test case: s="<<s<<"k="<<k<<endl;
    int res = longestSubstring(s, k), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test longest substr with k repeating chars end==============="<<endl;
}