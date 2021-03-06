//
// Created by hl4080 on 2020/7/12.
//

#include "leetcode_test.h"

void test_validParenthess() {
    cout<<"============simple test valid-parenthess begin============="<<endl;
    string s1 = "()[]{}", s2 = "([)]";
    bool res1 = isValidParentheses(s1), res2 = isValidParentheses(s2);
    bool desired1 = true, desired2 = false;
    cout<<"test case 1: "<<s1<<endl;
    cout<<"test case 2: "<<s2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test valid-parenthess end==============="<<endl;
}

void test_simplifyPath() {
    cout<<"============simple test simplify path begin============="<<endl;
    string s = "/a//b////c/d//././/..";
    string res = simplifyPath(s), desired = "/a/b/c";
    cout<<"test case: "<<s<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test simplify path end==============="<<endl;
}

void test_evalPRN() {
    cout<<"============simple test eval PRN begin============="<<endl;
    vector<string> tokens{"2", "1", "+", "3", "*"};
    cout<<"test case: ";
    printOneDimVec(tokens);
    int res = evalRPN(tokens), desired = 9;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test eval PRN end==============="<<endl;
}

void test_mystack() {
    cout<<"============simple test my stack begin============="<<endl;
    MyStack stk = MyStack();
    stk.push(1);
    stk.push(2);
    int p1 = stk.top(), desired1 = 2;
    int p2 = stk.pop(), desired2 = 2;
    int t3 = stk.empty(), desired3 = false;
    if(p1 == desired1 && p2 == desired2 && t3 == desired3) {
        cout<<"result of test case: push(1), push(2), top()->"<<p1<<", pop()->"<<p2<<", empty()->"<<t3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test my stack end==============="<<endl;
}

void test_calculator() {
    cout<<"============simple test calculator begin============="<<endl;
    string s = " 3+5 / 2 ";
    cout<<"test case: "<<s<<endl;
    int res = calculate(s), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test calculator end==============="<<endl;
}

void test_myQueue() {
    cout<<"============simple test my queue begin============="<<endl;
    MyQueue q;
    q.push(1);
    q.push(2);
    int res1 = q.peek(), desired1 = 1;
    int res2 = q.pop(), desired2 = 1;
    bool res3 = q.empty(), desired3 = false;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"result of test case: push("<<1<<"), "<<"push("<<2<<"), "<<"peek()->"<<res1<<", pop()->"<<res2<<", empty()->"<<res3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    }else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test my queue end==============="<<endl;
}

void test_decodeString() {
    cout<<"============simple test decode string begin============="<<endl;
    string s = "2[abc]3[cd]ef";
    cout<<"test case: "<<s<<endl;
    string res = decodeString(s), desired = "abcabccdcdcdef";
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test decode string end==============="<<endl;
}

void test_removeKDigits() {
    cout<<"============simple test remove k digits begin============="<<endl;
    string num = "1432219";
    int k = 3;
    cout<<"test case:"<<endl;
    cout<<"num: "<<num<<endl;
    cout<<"k="<<k<<endl;
    string res = removeKdigits(num, k), desired = "1219";
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove k digits end==============="<<endl;
}