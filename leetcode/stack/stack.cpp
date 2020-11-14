//
// Created by hl4080 on 2020/7/12.
//

#include <queue>
#include "./stack.h"

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
 */

bool isValidParentheses(string s) {
    if(s.empty()) return true;
    map<char, char> m{{'{', '}'}, {'(', ')'}, {'[', ']'}};
    stack<char> stk;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
            if(stk.empty() || m[stk.top()] != s[i] ) return false;
            stk.pop();
        } else stk.push(s[i]);
    }
    return stk.empty();
}

/*
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

 */

string simplifyPath(string path) {
    stack<string> stk;
    string res;
    stringstream ss(path);
    string split;
    while(getline(ss, split, '/')) {
        if(split == "..") {
            if(!stk.empty()) stk.pop();
            continue;
        }
        if(split != "." && !split.empty()) stk.push(split);
    }
    while(!stk.empty()) {
        string tmp = stk.top();
        res = "/" + tmp + res;
        stk.pop();
    }
    return res.empty()? "/": res;
}

/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

 */

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(int i=0; i<tokens.size(); i++) {
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int t1 = stk.top();
            stk.pop();
            int t2 = stk.top();
            stk.pop();
            if(tokens[i] == "+") stk.push(t2+t1);
            if(tokens[i] == "-") stk.push(t2-t1);
            if(tokens[i] == "*") stk.push(t2*t1);
            if(tokens[i] == "/") stk.push(t2/t1);
        } else {
            stk.push(stoi(tokens[i]));
        }
    }
    return stk.top();
}

/*
 * Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

 */

/*
 * Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7

 */

int calculate(string s) {
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        if(isdigit(c)) num = (long)num*10 + c - '0';
        if((!isdigit(c) && c != ' ') || i == s.size()-1) {
            int pre;
            switch (sign) {
                case('+'): stk.push(num); break;
                case('-'): stk.push(-num);break;
                case('*'):
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre*num);
                    break;
                case('/'):
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                    break;
            }
            sign = c;
            num = 0;
        }
    }
    int res = 0;
    while(!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}