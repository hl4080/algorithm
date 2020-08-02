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
    if(result == desired) {
        cout<<"result of test case: ";
        printListNode(l);
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test add-two-number end==============="<<endl;
}

void test_removeNthFromEnd() {
    cout<<"============simple test remove-nth-from-end begin==============="<<endl;
    vector<int> vec{1, 2, 3, 4, 5};
    ListNode* head = vector2List(vec);
    int n = 2;
    ListNode* l = removeNthFromEnd(head, n);
    vector<int> result = list2Vector(l);
    vector<int> desired{1, 2, 3, 5};
    cout<<"test case: "<<endl;
    cout<<"head: ";
    printListNode(head);
    cout<<"n: "<<n<<endl;
    if(result == desired) {
        cout<<"result of test case: ";
        printListNode(l);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove-nth-from-end end================="<<endl;
}

void test_mergeTwoSortedLists() {
    cout<<"============simple test merge-two-sorted-list begin==============="<<endl;
    vector<int> vec11{1, 2, 4}, vec12{1, 3, 4};
    vector<int> vec21{1, 2, 4}, vec22;
    ListNode* head11 = vector2List(vec11), *head12 = vector2List(vec12);
    ListNode* head21 = vector2List(vec21), *head22 = vector2List(vec22);
    ListNode* l1 = mergeTwoLists(head11, head12), *l2 = mergeTwoLists(head21, head22);
    vector<int> res1 = list2Vector(l1), res2 = list2Vector(l2);
    vector<int> desired1{1, 1, 2, 3, 4, 4}, desired2{1, 2, 4};
    cout<<"test case 1: "<<endl;
    cout<<"l1: ";
    printListNode(head11);
    cout<<"l2: ";
    printListNode(head12);
    cout<<"test case 2: "<<endl;
    cout<<"l1: ";
    printListNode(head21);
    cout<<"l2: ";
    printListNode(head22);
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: ";
        printListNode(l1);
        cout<<"result of test case 2: ";
        printListNode(l2);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test merge-two-sorted-list end================="<<endl;
}

void test_swapPairs() {
    cout<<"============simple test swap-pairs begin==============="<<endl;
    vector<int> vec{1, 2, 3, 4};
    ListNode* head = vector2List(vec);
    ListNode* l = swapPairs(head);
    vector<int> res = list2Vector(l);
    vector<int> desired{2, 1, 4, 3};
    cout<<"test case: ";
    printListNode(l);
    if(res == desired) {
        cout<<"result of test case: ";
        printListNode(l);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test swap-pairs end================="<<endl;
}

void test_rotateList() {
    cout<<"============simple test rotate list begin==============="<<endl;
    vector<int> vec1{1,2,3,4,5}, vec2{0, 1, 2};
    ListNode* head1 = vector2List(vec1), *head2 = vector2List(vec2);
    int k1 = 2, k2 =4;
    ListNode* l1 = rotateRight(head1, k1), *l2 = rotateRight(head2, k2);
    vector<int> res1 = list2Vector(l1), res2 = list2Vector(l2);
    vector<int> desired1{4, 5, 1, 2, 3}, desired2{2, 0, 1};
    cout<<"test case 1: "<<endl;
    cout<<"list1 : ";
    printListNode(head1);
    cout<<"k1: "<<k1<<endl;
    cout<<"test case 2: "<<endl;
    cout<<"list 2: ";
    printListNode(head1);
    cout<<"k2: "<<k2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: ";
        printListNode(l1);
        cout<<"result of test case 2: ";
        printListNode(l2);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test rotate list end==============="<<endl;
}