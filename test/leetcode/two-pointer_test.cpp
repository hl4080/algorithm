//
// Created by hl4080 on 2020/6/23.
//

#include "leetcode_test.h"

void test_happyNumber() {
    cout<<"============simple test happy-number begin============="<<endl;
    int n1 = 19, n2 = 1, n3 = 12;
    int res1 = isHappy(n1);
    int res2 = isHappy(n2);
    int res3 = isHappy(n3);
    int desired1 = true, desired2 = true, desired3 = false;
    cout<<"test case 1: "<<n1<<endl;
    cout<<"test case 2: "<<n2<<endl;
    cout<<"test case 3: "<<n3<<endl;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"result of test case 1: "<<desired1<<endl;
        cout<<"result of rest case 2: "<<desired2<<endl;
        cout<<"result of test case 3: "<<desired3<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test happy-number end==============="<<endl;
}

void test_threeSum() {
    cout<<"============simple test three-sum begin============="<<endl;
    vector<int> vec1;
    vector<int> vec2{0, -2, 0, 2, 2};
    vector<vector<int>> res1 = threeSum(vec1);
    vector<vector<int>> res2 = threeSum(vec2);
    vector<vector<int>> desired1;
    vector<vector<int>> desired2{{-2, 0, 2}};
    cout<<"test case 1: ";
    printOneDimVec(vec1);
    cout<<"test case 2: ";
    printOneDimVec(vec2);
    if(desired1 == res1 && desired2 == res2) {
        cout<<"result of test case 1: "<<endl;
        printTwoDimVec(desired1);
        cout<<"result of rest case 2: "<<endl;
        printTwoDimVec(desired2);
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }

    else cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test three-sum end==============="<<endl;
}

void test_longestSubsting() {
    cout<<"============simple test longest-substring begin============="<<endl;
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    int desired = 3;
    cout<<"test case: "<<s<<endl;
    if(result == desired) {
        cout<<"result of test case: "<<desired<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test longest-substring end==============="<<endl;
}

void test_maxWaterArea() {
    cout<<"============simple test max-water-area begin============="<<endl;
    vector<int> vec{1,8,6,2,5,4,8,3,7};
    int res = maxWaterArea(vec);
    int desired = 49;
    cout<<"test case: ";
    printOneDimVec(vec);
    if(res == desired) {
        cout<<"result of test case: "<<desired<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test max-water-area end==============="<<endl;
}

void test_threeSumClosest() {
    cout<<"============simple test three-sum-closest begin============="<<endl;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    int res = threeSumClosest(nums, target);
    int desired = 2;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"target: "<<target<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test three-sum-closest end==============="<<endl;
}

void test_removeDuplicate() {
    cout<<"============simple test remove-duplicate begin============="<<endl;
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int res = removeDuplicates(nums);
    int desired = 5;
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: ";
        cout<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove-duplicate end==============="<<endl;
}

void test_nextPermutation() {
    cout<<"============simple test remove-permutation begin============="<<endl;
    vector<int> nums{1, 3, 2};
    cout<<"test case: ";
    printOneDimVec(nums);
    nextPermutation(nums);
    vector<int> desired{2, 1, 3};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove-permutation end==============="<<endl;
}

void test_countAndSay() {
    cout<<"============simple test count-and-say begin============="<<endl;
    int n = 5;
    string res = countAndSay(n);
    string desired = "111221";
    cout<<"test case 1: "<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test count-and-say end==============="<<endl;
}

void test_mergeIntervals() {
    cout<<"============simple test merge-interval begin============="<<endl;
    vector<vector<int>> intervals{
            {1, 3},
            {2, 6},
            {8, 10},
            {15, 18}
    };
    vector<vector<int>> res = mergeIntervals(intervals);
    vector<vector<int>> desired{
            {1, 6},
            {8, 10},
            {15, 18}
    };
    cout<<"test case: "<<endl;
    printTwoDimVec(intervals);
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test merge-interval end==============="<<endl;
}

void test_sortColors() {
    cout<<"============simple test sort colors begin============="<<endl;
    vector<int> colors{2, 0, 2, 1, 1, 0};
    cout<<"test case: ";
    printOneDimVec(colors);
    vector<int> desired{0, 0, 1, 1, 2, 2};
    sortColors(colors);
    if(colors == desired) {
        cout<<"result of test case: ";
        printOneDimVec(colors);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sort colors end==============="<<endl;
}

void test_removeDeplicateII() {
    cout<<"============simple test remove deplicate II begin============="<<endl;
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int n = removeDeplicatesII(nums);
    cout<<"test case: ";
    printOneDimVec(nums);
    vector<int> desired{1, 1, 2, 2, 3};
    vector<int> res(nums.begin(), nums.begin()+n);
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove deplicate II end==============="<<endl;
}