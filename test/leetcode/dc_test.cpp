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
    if(result == desired){
        cout<<"result of test case 1: "<<desired<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test find-median-sorted-arrays begin============="<<endl;
}

void test_longestCommonPrefix() {
    cout<<"============simple test longest-common-prefix begin============="<<endl;
    vector<string> vec1{"flower","flow","flight"};
    vector<string> vec2{"dog","racecar","car"};
    string res1 = longestCommonPrefix(vec1);
    string res2 = longestCommonPrefix(vec2);
    string desired1 = "fl";
    string desired2 = "";
    cout<<"test case 1: ";
    printOneDimVec(vec1);
    cout<<"test case 2: ";
    printOneDimVec(vec2);
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cout<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test longest-common-prefix end==============="<<endl;
}