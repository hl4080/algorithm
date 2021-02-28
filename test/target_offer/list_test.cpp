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

void test_cloneRandomList() {
    cout<<"============simple test clone random list begin============="<<endl;
    vector<int> vec{1,2,3,-1,1,-1};
    RandomListNode* l1 = vector2RandList(vec);
    RandomListNode* l2 = CloneRandomList(l1);
    cout<<"test case: "<<endl;
    printOneDimVec(vec);
    if(RandomListEqual(l1, l2)) {
        cout<<"result test case: ";
        printOneDimVec(vec);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test clone random list end==============="<<endl;
}

void test_findFirstCommon() {
    cout<<"============simple test find first common begin============="<<endl;
    vector<int> vec1{1,2,3,4}, vec2{5}, vec3{3,4};
    ListNode* head1 = vector2List(vec1), *head2 = vector2List(vec2);
    head2->next = head1->next->next;
    cout<<"test case:"<<endl;
    cout<<"head1: ";
    printListNode(head1);
    cout<<"head2: ";
    printListNode(head2);
    ListNode* res = FindFirstCommonNode(head1, head2), *desired = vector2List(vec3);
    if(list2Vector(res) == list2Vector(desired)) {
        cout<<"result of test case: ";
        printListNode(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find first common end==============="<<endl;
}

void test_listCycleNode() {
    cout<<"============simple test list cycle begin============="<<endl;
    vector<int> vec{1,2,3,4,5};
    ListNode* head = vector2List(vec);
    head->next->next->next->next->next = head->next;
    ListNode* res = EntryNodeOfLoop(head), *desired = head->next;
    if(res == desired) {
        cout<<"result of test case: "<<res->val<<endl;
        cout<<"TEST STAUTS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test list cycle end==============="<<endl;
}

void test_removeDuplicateList() {
    cout<<"============simple test remove duplicate list begin============="<<endl;
    vector<int> vec{1,2,3,3,4,4,5}, vec2{1,2,5};
    ListNode* head = vector2List(vec);
    cout<<"test case: ";
    printListNode(head);
    ListNode* res = deleteDuplication(head), *desired = vector2List(vec2);
    if(list2Vector(res) == list2Vector(desired)) {
        cout<<"result of test case: ";
        printListNode(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove duplicate list end==============="<<endl;
}