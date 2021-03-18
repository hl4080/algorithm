//
// Created by hl4080 on 2021/3/6.
//

#include "basis_test.h"

void test_directInsertSort() {
    cout<<"============simple test direct insert sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    directInsertSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test direct insert sort end==============="<<endl;
}

void test_selectSort() {
    cout<<"============simple test direct insert sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    selectSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test direct insert sort end==============="<<endl;
}

void test_bubbleSort() {
    cout<<"============simple test direct bubble sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    bubble_sort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test direct bubble sort end==============="<<endl;
}

void test_hillSort() {
    cout<<"============simple test hill sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    hill_sort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test hill sort end==============="<<endl;
}

void test_quickSort() {
    cout<<"============simple test quick sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    quickSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test hill sort end==============="<<endl;
}

void test_mergeSort() {
    cout<<"============simple test merge sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    mergeSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test merge sort end==============="<<endl;
}

void test_heapSort() {
    cout<<"============simple test heap sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    heapSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test heap sort end==============="<<endl;
}

void test_countSort() {
    cout<<"============simple test count sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    countSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test count sort end==============="<<endl;
}

void test_bucketSort() {
    cout<<"============simple test bucket sort begin============="<<endl;
    vector<int> nums{4,5,1,6,2,9,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    bucketSort(nums);
    vector<int> desired{1,2,2,4,5,6,9};
    if(nums == desired) {
        cout<<"result of test case: ";
        printOneDimVec(nums);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test bucket sort end==============="<<endl;
}