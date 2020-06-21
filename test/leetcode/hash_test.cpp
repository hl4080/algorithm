//
// Created by hl4080 on 2020/6/21.
//

#include "leetcode_test.h"

void test_twoSum() {
    vector<int> vec{3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(vec, target);
    vector<int> desired{1, 2};
    if(result != desired)
        cerr<<"FAILED"<<endl;
    else
        cout<<"PASS"<<endl;
}