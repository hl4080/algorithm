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

