//
// Created by hl4080 on 2020/6/21.
//

#include "leetcode_test.h"

void test_twoSum() {
    cout<<"============simple test two-sum begin============="<<endl;
    vector<int> vec{3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(vec, target);
    vector<int> desired{1, 2};
    cout<<"test vector: ";
    printOneDimVec(vec);
    cout<<"taget: "<<target<<endl;
    if(result == desired) {
        cout<<"result of test case: ";
        printOneDimVec(desired);
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test two-sum end==============="<<endl;
}

void test_romanToInt() {
    cout<<"============simple test roman-to-int begin============="<<endl;
    string s1 = "IV", s2 = "LVIII", s3 = "MCMXCIV";
    int res1 = romanToInt(s1), res2 = romanToInt(s2), res3 = romanToInt(s3);
    int desired1 = 4, desired2 = 58, desired3 = 1994;
    cout<<"test case 1: "<<s1<<endl;
    cout<<"test case 2: "<<s2<<endl;
    cout<<"test case 3: "<<s3<<endl;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"test result 1: "<<res1<<endl;
        cout<<"test result 2: "<<res2<<endl;
        cout<<"test result 3: "<<res3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test roman-to-int end==============="<<endl;
}