//
// Created by hl4080 on 2020/6/22.
//

#include "leetcode_test.h"

void test_singleNumber() {
    cout<<"============simple test single-number begin============="<<endl;
    vector<int> vec1{4, 1, 2, 1, 2};
    vector<int> vec2{1};
    int desire1 = 4;
    int desire2 = 1;
    cout<<"test case 1: ";
    printOneDimVec(vec1);
    cout<<"test case 2: ";
    printOneDimVec(vec2);
    if(singleNumber(vec1) == desire1 && singleNumber(vec2) == desire2)
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test single-number end==============="<<endl;
}
