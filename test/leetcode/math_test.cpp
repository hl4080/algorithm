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

void test_uniquePaths() {
    cout<<"============simple test unique paths begin============="<<endl;
    int m1=7, n1 = 3;
    int m2=10, n2=5;
    int res1 = uniquePaths(m1, n1), res2 = uniquePaths(m2, n2);
    int desired1 = 28, desired2 = 715;
    cout<<"test case 1: "<<"m: "<<m1<<" n: "<<n1<<endl;
    cout<<"test case 2: "<<"m: "<<m2<<" n: "<<n2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test unique paths end==============="<<endl;
}

void test_sqrtx() {
    cout<<"============simple test sqrtx begin============="<<endl;
    int x=8;
    int res = sqrtx(x), desired = 2;
    cout<<"test case: "<<x<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sqrtx end==============="<<endl;
}

void test_setMatrixZeros() {
    cout<<"============simple test set matrix zeros begin============="<<endl;
    vector<vector<int>> matrix{
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
    };
    vector<vector<int>> desired{
            {0, 0, 0, 0},
            {0, 4, 5, 0},
            {0, 3, 1, 0}
    };
    cout<<"test case: "<<endl;
    printTwoDimVec(matrix);
    setZeros(matrix);
    if(matrix == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(matrix);
        cout<<"TEST STATUS: PASS";
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test set matrix zeros end==============="<<endl;
}

void test_generatePascalTriange() {
    cout<<"============simple test generate pascal triangle begin============="<<endl;
    int numRow = 5;
    vector<vector<int>> res = generatePascalTriangle(numRow);
    vector<vector<int>> desired{
            {1},
            {1,1},
            {1,2,1},
            {1,3,3,1},
            {1,4,6,4,1}
    };
    cout<<"test case: numRow = "<<numRow<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test generate pascal triangle end==============="<<endl;
}

void test_getRowPascalTriangle() {
    cout<<"============simple test get row pascal triangle begin============="<<endl;
    int rowIndex = 4;
    vector<int> res = getRowPacasalTriangle(rowIndex);
    vector<int> desired{1,4,6,4,1};
    cout<<"test case: rowIndex = "<<rowIndex<<endl;
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test get row pascal triangle end==============="<<endl;
}

void test_singlenumberII() {
    cout<<"============simple test single number II begin============="<<endl;
    vector<int> nums{0,1,0,1,0,1,99};
    int res = singleNumberII(nums), desired = 99;
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test single number II end==============="<<endl;
}
