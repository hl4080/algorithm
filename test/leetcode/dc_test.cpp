//
// Created by hl4080 on 2020/6/27.
//

#include "leetcode_test.h"

void test_findMedianSortedArrays() {
    vector<int> vec1{1, 3, 4, 9};
    vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    double result = findMedianSortedArrays(vec1, vec2);
    double desired = 4;
    if(result == desired)
        cout<<"PASS"<<endl;
    else
        cerr<<"FAILED"<<endl;
}
