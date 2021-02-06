//
// Created by hl4080 on 2021/1/27.
//

#ifndef ALOGRITHM_STACK_H
#define ALOGRITHM_STACK_H


#include <stack>
#include <vector>
#include <map>
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

class MinStack {
public:
    void push(int value) {
        stk1.push(value);
        if(stk2.empty()) {
            stk2.push(value);
            return;
        }
        int minValue = stk2.top();
        stk2.push(std::min(minValue, value));
    }
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    int top() {
        return stk1.top();
    }
    int min() {
        return stk2.top();
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};

bool IsPopOrder(vector<int> pushV,vector<int> popV);

#endif //ALOGRITHM_STACK_H
