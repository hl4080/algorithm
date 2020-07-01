//
// Created by hl4080 on 2020/6/21.
//

#include "leetcode_test.h"

void test_twoSum() {
    cout<<"============simple test two-sum begin============="<<endl;
    vector<int> vec{3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(vec, target);
    vector<int> desired{1, 2};
    cout<<"test vector: ";
    printOneDimVec(vec);
    cout<<"taget: "<<target<<endl;
    if(result == desired) {
        cout<<"result of test case: ";
        printOneDimVec(desired);
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test two-sum end==============="<<endl;
}