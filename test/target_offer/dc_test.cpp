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

void test_streamMedian() {
    cout<<"============simple test stream median begin============="<<endl;
    StreamMedian sm;
    vector<int> stream{5,2,3,4,1,6,7,0,8};
    vector<double> res;
    for(int i=0; i<stream.size(); i++) {
        sm.Insert(stream[i]);
        res.push_back(sm.GetMedian());
    }
    cout<<"test case: ";
    printOneDimVec(stream);
    vector<double> desired{5.00,3.50,3.00,3.50,3.00,3.50,4.00,3.50,4.00};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test stream median end==============="<<endl;
}