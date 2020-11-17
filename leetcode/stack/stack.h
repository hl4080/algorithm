//
// Created by hl4080 on 2020/7/12.
//

#ifndef ALOGRITHM_STACK_H
#define ALOGRITHM_STACK_H

#include <string>
#include <stack>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

bool isValidParentheses(string s);
string simplifyPath(string path);
int evalRPN(vector<string>& tokens);
int calculate(string s);

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int sz;
    MyStack() {
        sz = 0;
    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i=0; i<sz; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        sz += 1;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = q.front();
        q.pop();
        sz -= 1;
        return tmp;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return sz == 0;
    }
};

class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        int sz1 = stk1.size();
        for(int i=0; i<sz1; i++) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.push(x);
        int sz2 = stk2.size();
        for(int i=0; i<sz2; i++) {
            stk1.push(stk2.top());
            stk2.pop();
        }

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = stk1.top();
        stk1.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        return stk1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};
#endif //ALOGRITHM_STACK_H
