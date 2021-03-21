//
// Created by hl4080 on 2021/3/20.
//

#include "../../basis/search/search.h"
#include "../../util/util.h"
#include <iostream>

void test_seqSearch() {
    cout<<"============simple test sequential search begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    int target = 9;
    cout<<"test case: ";
    printOneDimVec(nums);
    cout<<"target: "<<target<<endl;
    int res = seqSearch(nums, target), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sequential search end==============="<<endl;
}

void test_binarySearch() {
    cout<<"============simple test binary search begin============="<<endl;
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    int target = 7;
    cout<<"test case: ";
    printOneDimVec(nums);
    cout<<"target: "<<target<<endl;
    int res = binarySearchRecurive(nums, target), desired = 6;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test binary search end==============="<<endl;
}