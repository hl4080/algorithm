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
        printOneDimVec(result);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test remove-nth-from-end end================="<<endl;
}