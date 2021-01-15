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

void test_majorityElement() {
    cout<<"============simple test majority element begin============="<<endl;
    vector<int> nums{2,2,1,1,1,2,2};
    int res = majorityElement(nums), desired = 2;
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test majority element end==============="<<endl;
}

void test_trailingZeros() {
    cout<<"============simple test trailing zeros begin============="<<endl;
    int n= 30;
    int res = trailingZeroes(n), desired = 7;
    cout<<"test case: n="<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test trailing zeros end==============="<<endl;
}

void test_largestNumber() {
    cout<<"============simple test largets number begin============="<<endl;
    vector<int> nums{3, 30, 34, 5, 9};
    string res = largestNumberCombine(nums), desired = "9534330";
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test largets number end==============="<<endl;
}

void test_rotateArray() {
    cout<<"============simple test rotate array begin============="<<endl;
    vector<int> nums{1,2,3,4,5,6};
    int k= 3;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"K: "<<k<<endl;
    vector<int> desired{4,5,6,1,2,3};
    rotateArray(nums,k);
    if(desired == nums) {
        cout<<"result of test case: ";
        printOneDimVec(desired);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test rotate array end==============="<<endl;
}

void test_reverseBits() {
    cout<<"============simple test reverse bits begin============="<<endl;
    uint32_t n = 43261596;
    uint32_t res = reverseBits(n), desired = 964176192;
    cout<<"test case: "<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reverse bits end==============="<<endl;
}

void test_hammingWeight() {
    cout<<"============simple test hamming weight begin============="<<endl;
    uint32_t n = 11;
    int res = hammingWeight(n), desired = 3;
    cout<<"test case: n: "<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: FAILED"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test hamming weight end==============="<<endl;
}

void test_rangeBitwiseAnd() {
    cout<<"============simple test range bitwise and begin============="<<endl;
    int m=5, n=7;
    int res = rangeBitwiseAnd(m, n), desired = 4;
    cout<<"test case: m="<<m<<" n="<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test range bitwise and end==============="<<endl;
}

void test_countPrimes() {
    cout<<"============simple test count prime begin============="<<endl;
    int n = 10;
    int res = countPrimes(n), desired = 4;
    cout<<"test case: "<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test count prime end==============="<<endl;
}

void test_majorityElementsII() {
    cout<<"============simple test majority elements II begin============="<<endl;
    vector<int> nums{3,2,3};
    vector<int> res = majorityElementII(nums), desired{3};
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test majority elements II end==============="<<endl;
}

void test_productExceptSelf() {
    cout<<"============simple test product except self begin============="<<endl;
    vector<int> nums{1,2,3,4};
    vector<int> res = productExceptSelf(nums), desired{24,12,8,6};
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test product except self end==============="<<endl;
}

void test_addDigits() {
    cout<<"============simple test add digits begin============="<<endl;
    int num = 38;
    int res = addDigits(num), desired = 2;
    cout<<"test case: "<<num<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test add digits end==============="<<endl;
}

void test_singleNumberIII() {
    cout<<"============simple test single number III begin============="<<endl;
    vector<int> nums{1,2,1,3,2,5};
    vector<int> res = singleNumberIII(nums), desired{3,5};
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test single number III end==============="<<endl;
}

void test_missingNumber() {
    cout<<"============simple test missing number begin============="<<endl;
    vector<int> nums{9,6,4,2,3,5,7,0,1};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = missingNumber(nums), desired = 8;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test missing number end==============="<<endl;
}

void test_hIndex() {
    cout<<"============simple test h index begin============="<<endl;
    vector<int> indexes{3,0,6,1,5};
    cout<<"test case: ";
    printOneDimVec(indexes);
    int res = hIndex(indexes), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test h index end==============="<<endl;
}

void test_hIndexII() {
    cout<<"============simple test h index II begin============="<<endl;
    vector<int> citations{0,1,3,5,6};
    cout<<"test case: ";
    printOneDimVec(citations);
    int res = hIndexII(citations), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test h index II end==============="<<endl;
}

void test_canWinNim() {
    cout<<"============simple test can win Nim begin============="<<endl;
    int n = 8;
    bool res = canWinNim(n), desired = false;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test can win Nim end==============="<<endl;
}

void test_increasingTriplet() {
    cout<<"============simple test increasing triplet begin============="<<endl;
    vector<int> nums{4,5,1,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    bool res = increasingTriplet(nums), desired = false;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test increasing triplet end==============="<<endl;
}

void test_integerBreak() {
    cout<<"============simple test integer break begin============="<<endl;
    int n = 11;
    cout<<"test case: n="<<n<<endl;
    int res = integerBreak(n), desired = 54;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test integer break end==============="<<endl;
}

void test_countNumbersWithUnqiueDigits() {
    cout<<"============simple test count numbers with unique digits begin============="<<endl;
    int n=3;
    cout<<"test case: n="<<n<<endl;
    int res = countNumbersWithUniqueDigits(n), desired = 739;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test count numbers with unique digits end==============="<<endl;
}

void test_isPerfectSquare() {
    cout<<"============simple test is perfect square begin============="<<endl;
    int num = 15;
    cout<<"test case: num="<<num<<endl;
    bool res = isPerfectSquare(num), desired = false;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is perfect square end==============="<<endl;
}

void test_getSum() {
    cout<<"============simple test get sum begin============="<<endl;
    int a = -4, b = 2;
    cout<<"test case: a="<<a<<" "<<"b="<<b<<endl;
    int res = getSum(a, b), desired = -2;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test get sum end==============="<<endl;
}

void test_superPow() {
    cout<<"============simple test super pow begin============="<<endl;
    int a = 1;
    vector<int> b{4,3,3,8,5,2};
    cout<<"test case: "<<endl;
    cout<<"a="<<a<<endl;
    cout<<"b=";
    printOneDimVec(b);
    int res = superPow(a, b), desired = 1;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STAUS: PASS"<<endl;
    } else cerr<<"TEST STAUTS: FAILED"<<endl;
    cout<<"============simple test super pow end==============="<<endl;
}

void test_lastRemain() {
    cout<<"============simple test last remain begin============="<<endl;
    int n = 9;
    cout<<"test case: n="<<n<<endl;
    int res = lastRemaining(n), desired = 6;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test last remain end==============="<<endl;
}

void test_integerReplacement() {
    cout<<"============simple test integer replacement begin============="<<endl;
    int n = 15;
    cout<<"test case: n="<<15<<endl;
    int res = integerReplacement(n), desired = 5;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test integer replacement end==============="<<endl;
}

void test_randomPickIndex() {
    cout<<"============simple test randomly pick index begin============="<<endl;
    vector<int> nums{1,2,3,3,3};
    int target = 3;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"target: "<<target<<endl;
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i=0; i<100; i++) {
        int res = pickRandomly(nums, target);
        if(res == 2) c1++;
        else if(res == 3) c2++;
        else if(res == 4) c3++;
    }
    if(c1+c2+c3 == 100 && c1 && c2 && c3) {
        cout<<"result of test case: randomly pick indexes 100 times are: "<<c1<<" "<<c2<<" "<<c3<<endl;
        cout<<"TEST CASE: PASS"<<endl;
    } else cerr<<"TEST CASE: FAILED"<<endl;
    cout<<"============simple test randomly pick index end==============="<<endl;
}

void test_findNthDigit() {
    cout<<"============simple test find nth digit begin============="<<endl;
    int n = 1000;
    cout<<"test case: n="<<n<<endl;
    int res = findNthDigit(n), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find nth digit end==============="<<endl;
}

void test_findAllDuplicates() {
    cout<<"============simple test find all duplicates begin============="<<endl;
    vector<int> nums{4,3,2,7,8,2,3,1};
    cout<<"test case: ";
    printOneDimVec(nums);
    vector<int> res = findDuplicates(nums), desired{2,3};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find all duplicates end==============="<<endl;
}