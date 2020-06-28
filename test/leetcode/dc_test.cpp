//
// Created by hl4080 on 2020/6/27.
//

#include "leetcode_test.h"

void test_findMedianSortedArrays() {
    cout<<"============simple test find-median-sorted-arrays begin============="<<endl;
    vector<int> vec1{1, 3, 4, 9};
    vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    double result = findMedianSortedArrays(vec1, vec2);
    double desired = 4;
    cout<<"test case: "<<endl;
    cout<<"vec1: ";
    printOneDimVec(vec1);
    cout<<"vec2: ";
    printOneDimVec(vec2);
    if(result == desired)
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test find-median-sorted-arrays begin============="<<endl;
}
