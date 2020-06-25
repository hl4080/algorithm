//
// Created by hl4080 on 2020/6/25.
//

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include "list.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int forward = 0;
    ListNode* pre = new ListNode(0);
    ListNode* result = pre;
    result->next = NULL;
    while(l1 || l2 || forward) {
        int current = forward;
        current += l1? l1->val: 0;
        current += l2? l2->val: 0;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        forward = current/10;
        ListNode* tmp = new ListNode(current%10);
        tmp->next = result->next;
        result->next = tmp;
        result = result->next;
    }
    return pre->next;
}