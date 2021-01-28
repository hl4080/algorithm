//
// Created by hl4080 on 2021/1/28.
//

#include "../../target_offer/dc/dc.h"
#include "../../util/util.h"
#include <iostream>

void test_minRotateArray() {
    cout<<"============simple test min rotate array begin============="<<endl;
    vector<int> nums{3,4,5,1,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = minNumberInRotateArray(nums), desired = 1;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test min rotate array end==============="<<endl;
}