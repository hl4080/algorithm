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
