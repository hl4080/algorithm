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

