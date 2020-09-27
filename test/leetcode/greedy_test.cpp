//
// Created by hl4080 on 2020/7/6.
//

#include "leetcode_test.h"

void test_intToRoman() {
    cout<<"============simple test integer-to-roman begin============="<<endl;
    int n1 = 4, n2 = 58, n3 = 1994;
    string res1 = intToRoman(n1), res2 = intToRoman(n2), res3 = intToRoman(n3);
    string desired1 = "IV", desired2 = "LVIII", desired3 = "MCMXCIV";
    cout<<"test case 1: "<<n1<<endl;
    cout<<"test case 2: "<<n2<<endl;
    cout<<"test case 3: "<<n3<<endl;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"result of test case 3: "<<res3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test integer-to-roman end==============="<<endl;
}

void test_jumpGame() {
    cout<<"============simple test jump game begin============="<<endl;
    vector<int> nums1{2,3,1,1,4}, nums2{3,2,1,0,4};
    bool res1 = jumpGame(nums1), res2 = jumpGame(nums2);
    bool desired1 = true, desired2 = false;
    cout<<"test case1: ";
    printOneDimVec(nums1);
    cout<<"test case2: ";
    printOneDimVec(nums2);
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test jump game end==============="<<endl;
}

void test_canCompleteCircuit() {
    cout<<"============simple test can complete circuit begin============="<<endl;
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    int res = canCompleteCircuit(gas, cost), desired = 3;
    cout<<"test case"<<endl;
    cout<<"gas: ";
    printOneDimVec(gas);
    cout<<"cost: ";
    printOneDimVec(cost);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test can complete circuit end==============="<<endl;
}