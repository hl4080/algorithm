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