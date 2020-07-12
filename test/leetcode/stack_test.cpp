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