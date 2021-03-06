//
// Created by hl4080 on 2021/1/24.
//

#include "target_offer_test.h"

void test_find() {
    cout<<"============simple test find begin============="<<endl;
    vector<vector<int>> array{
            {1,2,8,9},
            {2,4,9,12},
            {4,7,10,13},
            {6,8,11,15}
    };
    int target = 7;
    cout<<"test case: "<<endl;
    cout<<"target: "<<target<<endl;
    cout<<"array:"<<endl;
    printTwoDimVec(array);
    bool res = Find(target, array), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find begin============="<<endl;
}

void test_reorderArray() {
    cout<<"============simple test reorder array begin============="<<endl;
    vector<int> nums{1,2,3,4,5};
    cout<<"test case: ";
    printOneDimVec(nums);
    reorderArray(nums);
    vector<int> desired{1,3,5,2,4};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reorder array end==============="<<endl;
}

void test_printMatrix() {
    cout<<"============simple test print matrix begin============="<<endl;
    vector<vector<int>> matrix{
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    cout<<"test case: "<<endl;
    printTwoDimVec(matrix);
    vector<int> res = printMatrix(matrix), desired{1,2,3,6,9,8,7,4,5};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test print matrix end==============="<<endl;
}

void test_morethanHalf() {
    cout<<"============simple test more than half begin============="<<endl;
    vector<int> nums{1,2,3,2,2,2,5,4,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = MoreThanHalfNum(nums), desired = 2;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FIALED"<<endl;
    cout<<"============simple test more than half end==============="<<endl;
}

void test_leastKNumbers() {
    cout<<"============simple test least k numbers begin============="<<endl;
    vector<int> vec{4,5,1,6,2,7,3,8};
    int k = 4;
    cout<<"test case: "<<endl;
    printOneDimVec(vec);
    cout<<"k="<<k<<endl;
    vector<int> res = LeasKtNumbers(vec, k), desired{1,2,3,4};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED";
    cout<<"============simple test least k numbers end==============="<<endl;
}

void test_minStringVal() {
    cout<<"============simple test least k numbers begin============="<<endl;
    vector<int> vec{3,32,24};
    cout<<"test case: ";
    printOneDimVec(vec);
    string res = minStringNumber(vec), desired = "24323";
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test least k numbers end==============="<<endl;
}

void test_uglyNumber() {
    cout<<"============simple test ugly number begin============="<<endl;
    int index = 7;
    cout<<"test case: index="<<index<<endl;
    int res = UglyNumber(index), desired = 8;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test ugly number end==============="<<endl;
}

void test_reversePairs() {
    cout<<"============simple test reverse pairs begin============="<<endl;
    vector<int> vec{1,2,3,4,5,6,7,0};
    cout<<"test case: ";
    printOneDimVec(vec);
    int res = InversePairs(vec), desired = 7;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reverse pairs end==============="<<endl;
}

void test_getNumberOfK() {
    cout<<"============simple test get number of k begin============="<<endl;
    vector<int> vec{1,2,3,3,3,3,4,5};
    int k = 3;
    cout<<"test case: "<<endl;
    cout<<"data: "<<endl;
    printOneDimVec(vec);
    cout<<"k="<<k<<endl;
    int res = GetNumberOfK(vec, k), desired = 4;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test get number of k end==============="<<endl;
}

void test_continuousSequence() {
    cout<<"============simple test get continuous sequence begin============="<<endl;
    int sum = 9;
    cout<<"test case: sum="<<sum<<endl;
    vector<vector<int>> res = FindContinuousSequence(sum), desired{{2,3,4}, {4,5}};
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test get continuous sequence end==============="<<endl;
}

void test_numberWithSum() {
    cout<<"============simple test find numbers with sum begin============="<<endl;
    vector<int> vec{1,2,4,6,8,11,15};
    int sum = 15;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(vec);
    cout<<"sum = "<<sum<<endl;
    vector<int> res = FindNumbersWithSum(vec, sum), desired{4,11};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find numbers with sum end==============="<<endl;
}

void test_isContinous() {
    cout<<"============simple test is continous begin============="<<endl;
    vector<int> nums{0,3,2,6,4};
    cout<<"test case: ";
    printOneDimVec(nums);
    bool res = IsContinuous(nums), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is continous end==============="<<endl;
}

void test_duplicate() {
    cout<<"============simple test duplicate begin============="<<endl;
    vector<int> nums{2,3,1,0,2,5,3};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = duplicate(nums), desired = 2;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test duplicate end==============="<<endl;
}

void test_multiplyArray() {
    cout<<"============simple test multiply array begin============="<<endl;
    vector<int> nums{1,2,3,4,5};
    cout<<"test case: ";
    printOneDimVec(nums);
    vector<int> res = multiplyArray(nums), desired{120,60,40,30,24};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST SATUS: FAILED"<<endl;
    cout<<"============simple test multiply array end==============="<<endl;
}

void test_maxWindow() {
    cout<<"============simple test max window begin============="<<endl;
    vector<int> nums{2,3,4,2,6,2,5,1};
    int k = 3;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"k="<<k<<endl;
    vector<int> res = maxInWindows(nums, k), desired{4,4,6,6,6,5};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST SATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test max window end==============="<<endl;
}

void test_movingCount() {
    cout<<"============simple test moving count begin============="<<endl;
    int threhold = 5, rows = 10, cols = 10;
    cout<<"threhold="<<threhold<<" rows="<<rows<<" cols="<<cols<<endl;
    int res = movingCount(threhold, rows, cols), desired = 21;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test moving count end==============="<<endl;
}