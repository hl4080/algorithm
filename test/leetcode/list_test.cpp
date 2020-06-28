//
// Created by hl4080 on 2020/6/25.
//

#include "leetcode_test.h"

void test_addTwoNumber() {
    cout<<"============simple test add-two-number begin============="<<endl;
    vector<int> vec1{2, 4, 3};
    vector<int> vec2{5, 6, 7};
    ListNode* l1 = vector2List(vec1);
    ListNode* l2 = vector2List(vec2);
    ListNode* l = addTwoNumbers(l1, l2);
    vector<int> result = list2Vector(l);
    vector<int> desired{7, 0, 1, 1};
    cout<<"test case : "<<endl;
    cout<<"l1: ";
    printListNode(l1);
    cout<<"l2: ";
    printListNode(l2);
    if(result == desired)
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test add-two-number end==============="<<endl;
}