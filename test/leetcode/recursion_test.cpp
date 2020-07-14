//
// Created by hl4080 on 2020/7/10.
//

#include "leetcode_test.h"

void test_letterCombination() {
    cout<<"============simple test letter-combination begin============="<<endl;
    string s = "23";
    vector<string> res = letterCombinations(s);
    vector<string> desired{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    cout<<"test case: "<<s<<endl;
    if(vecEqual(res, desired)) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test letter-combination end==============="<<endl;
}

void test_generateParenthesis() {
    cout<<"============simple test generate-parenthesis begin============="<<endl;
    int n = 3;
    vector<string> res = generateParenthesis(n);
    vector<string> desired{"((()))","(()())","(())()","()(())","()()()"};
    cout<<"test case 1: "<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test generate-parenthesis end==============="<<endl;
}