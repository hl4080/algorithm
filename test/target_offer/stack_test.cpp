//
// Created by hl4080 on 2021/1/27.
//

#include "../../target_offer/stack/stack.h"
#include <iostream>

void test_myStack() {
    cout<<"============simple test my stack begin============="<<endl;
    MyStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    int t1 = stk.pop();
    int t2 = stk.pop();
    cout<<"test case: push(1) push(2) push(3) pop() pop()"<<endl;
    if(t1 ==3 && t2 == 2) {
        cout<<"result of test case: "<<t1<<" "<<t2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test my stack end==============="<<endl;
}