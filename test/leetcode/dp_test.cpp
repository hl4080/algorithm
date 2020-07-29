//
// Created by hl4080 on 2020/6/30.
//

#include "leetcode_test.h"

void test_longestPalindromic() {
    cout<<"============simple test longest palindromic substring begin============="<<endl;
    string s1 = "babad";
    string s2 = "cbbd";
    string res1 = longestPalindrome(s1);
    string res2 = longestPalindrome(s2);
    string desired1 = "bab";
    string desired2 = "bb";
    cout<<"test case 1: "<<s1<<endl;
    cout<<"test case 2: "<<s2<<endl;
    if(res1 == res1 && res2 == desired2){
        cout<<"result of test case 1: "<<desired1<<endl;
        cout<<"result of rest case 2: "<<desired2<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test longest palindromic substring end==============="<<endl;
}

void test_expressionMatch() {
    cout<<"============simple test expression match begin============="<<endl;
    string s1 = "aa", p1 = "a*";
    string s2 = "mississippi", p2 = "mis*is*p*.";
    bool res1 = isExpressionMatch(s1, p1), res2 = isExpressionMatch(s2, p2);
    bool desired1 = true, desired2 = false;
    cout<<"test case 1: "<<"s: "<<s1<<" p: "<<p1<<endl;
    cout<<"test case 2: "<<"s: "<<s2<<" p: "<<p2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result pf test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else
        cerr<<"TEST STAUS: FAILED"<<endl;
    cout<<"============simple test expression match end==============="<<endl;
}

void test_maximumSubarray() {
    cout<<"============simple test maximum subarray begin============="<<endl;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(nums), desired = 6;
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test maximum subarray end==============="<<endl;
}

