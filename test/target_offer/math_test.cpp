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