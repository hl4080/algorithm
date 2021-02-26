//
// Created by hl4080 on 2021/1/28.
//

#include "../../target_offer/math/math.h"
#include "../../util/util.h"
#include <iostream>

void test_jumpFloorII() {
    cout<<"============simple test jump floor II begin============="<<endl;
    int n = 3;
    cout<<"test case: n="<<n<<endl;
    int res = jumpFloorII(n), desired = 8;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test jump floor II end==============="<<endl;
}

void test_numberOf1() {
    cout<<"============simple test number of 1 begin============="<<endl;
    int n = 5;
    cout<<"test case: ="<<n<<endl;
    int res = NumberOf1(n), desired = 2;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test number of 1 end==============="<<endl;
}

void test_power() {
    cout<<"============simple test power begin============="<<endl;
    double base = 3.0;
    int exponent = 5;
    cout<<"test case: base="<<base<<" "<<"exponent:"<<exponent<<endl;
    double res = Power(base, exponent), desired = 243.0;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test power begin============="<<endl;
}

void test_numberOf1s() {
    cout<<"============simple test number of 1s begin============="<<endl;
    int n = 13;
    cout<<"test case: n="<<n<<endl;
    int res = NumberOf1Between1AndN(n), desired = 6;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test number of 1s end==============="<<endl;
}

void test_appearOnce() {
    cout<<"============simple test appear once begin============="<<endl;
    vector<int> vec{1,1,2,2,3,5};
    cout<<"test case: ";
    printOneDimVec(vec);
    int n0=0, n1=0;
    int *num1 = &n0, *num2 = &n1;
    FindNumsAppearOnce(vec, num1, num2);
    int desired1 = 3, desired2 = 5;
    if(*num1 == desired1 && *num2 == desired2) {
        cout<<"result of test case: num1="<<num1<<" nums2="<<num2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test appear once end=============="<<endl;
}

void test_specialSum() {
    cout<<"============simple test special sum begin============="<<endl;
    int n = 5;
    cout<<"test case: n="<<n<<endl;
    int res = SpecialSum(n), desired = 15;
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test special sum end==============="<<endl;
}

void test_specialAdd() {
    cout<<"============simple test special add begin============="<<endl;
    int a = 5, b = 3;
    cout<<"test case: a="<<a<<" b="<<b<<endl;
    int res = SpecialAdd(a, b), desired = 8;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test special add end==============="<<endl;
}