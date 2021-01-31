//
// Created by hl4080 on 2021/1/26.
//


#include "../../target_offer/list/list.h"
#include "../../util/util.h"
#include <iostream>


void test_printReverseList() {
    cout<<"============simple test print reverse list begin============="<<endl;
    vector<int> vec{1,2,3,4};
    ListNode* head = vector2List(vec);
    cout<<"test case: ";
    printListNode(head);
    vector<int> res = printListFromTailToHead(head), desired{4,3,2,1};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test print reverse list end==============="<<endl;
}

void test_FindKthToTail() {
    cout<<"============simple test find kth to tail begin============="<<endl;
    vector<int> nums{1,2,3,4,5};
    ListNode* head = vector2List(nums);
    int k = 2;
    cout<<"test case:"<<endl;
    cout<<"head: ";
    printListNode(head);
    cout<<"k="<<k<<endl;
    ListNode* res = FindKthToTail(head, k);
    if(res->val == 4) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find kth to tail begin============="<<endl;
}

void test_reverList() {
    cout<<"============simple test reverse list begin============="<<endl;
    vector<int> nums{1,2,3,4,5};
    ListNode* head = vector2List(nums);
    cout<<"test case: ";
    printListNode(head);
    ListNode* l = ReverseList(head);
    vector<int> res = list2Vector(l),desired{5,4,3,2,1};
    if(vecEqual(res, desired)) {
        cout<<"result of test case: ";
        printListNode(l);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reverse list end==============="<<endl;
}

void test_merge() {
    cout<<"============simple test merge list begin============="<<endl;
    vector<int> l1{1,3,5}, l2{2,4,6};
    ListNode* head1 = vector2List(l1), *head2 = vector2List(l2);
    cout<<"test case:"<<endl;
    cout<<"head1: ";
    printListNode(head1);
    cout<<"head2: ";
    printListNode(head2);
    ListNode* l = Merge(head1, head2);
    vector<int> res = list2Vector(l), desired{1,2,3,4,5,6};
    if(res == desired) {
        cout<<"result of test case: ";
        printListNode(l);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test merge list end==============="<<endl;
}