//
// Created by hl4080 on 2020/6/22.
//

#include "leetcode_test.h"

void test_singleNumber() {
    cout<<"============simple test single-number begin============="<<endl;
    vector<int> vec1{4, 1, 2, 1, 2};
    vector<int> vec2{1};
    int desire1 = 4;
    int desire2 = 1;
    cout<<"test case 1: ";
    printOneDimVec(vec1);
    cout<<"test case 2: ";
    printOneDimVec(vec2);
    if(singleNumber(vec1) == desire1 && singleNumber(vec2) == desire2){
        cout<<"result of test case 1: "<<desire1<<endl;
        cout<<"result of rest case 2: "<<desire2<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test single-number end==============="<<endl;
}

void test_zigzagConversion() {
    cout<<"============simple test zigzag-conversion begin============="<<endl;
    string s = "PAYPALISHIRING";
    int numRow1 = 3, numRow2 = 4;
    string res1 = zigzagConvert(s, numRow1);
    string res2 = zigzagConvert(s, numRow2);
    string desired1 = "PAHNAPLSIIGYIR";
    string desired2 = "PINALSIGYAHRPI";
    cout<<"test case 1: "<<endl;
    cout<<"s: "<<s<<", row number: "<<numRow1<<endl;
    cout<<"test case 2: "<<endl;
    cout<<"s: "<<s<<", row number: "<<numRow2<<endl;
    if(res1 == desired1 && res2 == desired2){
        cout<<"result of test case 1: "<<desired1<<endl;
        cout<<"result of rest case 2: "<<desired2<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test zigzag-conversion end==============="<<endl;
}

void test_reverseInteger() {
    cout<<"============simple test reverse-integer begin============="<<endl;
    int num1 = 123, num2 = -123, num3 = 120;
    int res1 = reverseInteger(num1), res2 = reverseInteger(num2), res3 = reverseInteger(num3);
    int desired1 = 321, desired2 = -321, desired3 = 21;
    cout<<"test case 1: "<<num1<<endl;
    cout<<"test case 2: "<<num2<<endl;
    cout<<"test case 3: "<<num3<<endl;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"result of test case 3: "<<res3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reverse-integer end==============="<<endl;
}

void test_palindromeNumber() {
    cout<<"============simple test palindrome number begin============="<<endl;
    int num1 = 121, num2 = -121, num3 = 10;
    bool res1 = isPalindrome(num1), res2 = isPalindrome(num2), res3 = isPalindrome(num3);
    bool desired1 = true, desired2 = false, desired3 = false;
    cout<<"test case 1: "<<num1<<endl;
    cout<<"test case 2: "<<num2<<endl;
    cout<<"test case 3: "<<num3<<endl;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"result of test case 3: "<<res3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test palindrome number end==============="<<endl;
}
