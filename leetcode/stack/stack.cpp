//
// Created by hl4080 on 2020/7/12.
//

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