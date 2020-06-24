//
// Created by hl4080 on 2020/6/23.
//

#include "leetcode_test.h"

void test_happyNumber() {
    int n1 = 19, n2 = 1, n3 = 12;
    int res1 = isHappy(n1);
    int res2 = isHappy(n2);
    int res3 = isHappy(n3);
    int desired1 = true, desired2 = true, desired3 = false;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3)
        cout<<"PASS"<<endl;
    else cerr<<"FAILED"<<endl;
}

void test_threeSum() {
    vector<int> vec1;
    vector<int> vec2{0, -2, 0, 2, 2};
    vector<vector<int>> res1 = threeSum(vec1);
    vector<vector<int>> res2 = threeSum(vec2);
    vector<vector<int>> desired1;
    vector<vector<int>> desired2{{-2, 0, 2}};
    if(desired1 == res1 && desired2 == res2)
        cout<<"PASS"<<endl;
    else cerr<<"FAILED"<<endl;
}

