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

#endif //ALOGRITHM_STACK_H
