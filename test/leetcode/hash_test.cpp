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
    if(result != desired)
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    else
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    cout<<"============simple test two-sum end==============="<<endl;
}