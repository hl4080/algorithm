//
// Created by hl4080 on 2021/1/28.
//

#include "../../target_offer/dp/dp.h"
#include "../../util/util.h"
#include <iostream>

void test_fibonacci() {
    cout<<"============simple test min rotate array begin============="<<endl;
    int n=4;
    cout<<"test case: n="<<n<<endl;
    int res = Fibonacci(n), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test min rotate array end==============="<<endl;
}

void test_jumpFloor() {
    cout<<"============simple test jump floor begin============="<<endl;
    int n=4;
    cout<<"test case: n="<<n<<endl;
    int res = jumpFloor(n), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test jump floor end==============="<<endl;
}

void test_rectCover() {
    cout<<"============simple test rect cover begin============="<<endl;
    int n = 4;
    cout<<"test case: n="<<n<<endl;
    int res = rectCover(n), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test rect cover end==============="<<endl;
}

void test_greatestSubarray() {
    cout<<"============simple test greatest subarray begin============="<<endl;
    vector<int> vec{1,-2,3,10,-4,7,2,-5};
    cout<<"test case: ";
    printOneDimVec(vec);
    int res = FindGreatestSumOfSubArray(vec), desired = 18;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test greatest subarray end==============="<<endl;
}

void test_josephCircle() {
    cout<<"============simple test joseph circle begin============="<<endl;
    int n=5, m=3;
    cout<<"test case: n="<<n<<" m="<<m<<endl;
    int res = LastRemaining(n, m), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test joseph circle end==============="<<endl;
}
