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