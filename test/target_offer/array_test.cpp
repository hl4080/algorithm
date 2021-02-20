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