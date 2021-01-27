//
// Created by hl4080 on 2021/1/27.
//

#ifndef ALOGRITHM_STACK_H
#define ALOGRITHM_STACK_H


#include <stack>
using namespace std;

class MyStack {
public:
    void push(int node) {
        int sz = stack2.size();
        for(int i=0; i<sz; i++) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
        for(int i=0; i<sz+1; i++) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    int pop() {
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


#endif //ALOGRITHM_STACK_H
