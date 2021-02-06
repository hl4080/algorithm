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

void test_minStack() {
    cout<<"============simple test min stack begin============="<<endl;
    MinStack stk;
    stk.push(4);
    stk.push(1);
    stk.push(2);
    int v1 = stk.min(), v2 = stk.top();
    stk.pop();
    int v3 = stk.min(), v4 = stk.top();
    cout<<"test case: push(4) push(1) push(2) min() top() push() min() top()"<<endl;
    if(v1 == 1 && v2 == 2 && v3 == 1 && v4 == 1) {
        cout<<"result of test case: "<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test min stack end==============="<<endl;
}