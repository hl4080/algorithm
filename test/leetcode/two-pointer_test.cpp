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