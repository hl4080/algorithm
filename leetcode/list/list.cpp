//
// Created by hl4080 on 2020/6/25.
//

#include "list.h"

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

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

/*
 * Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //keep two pointer with interval of length n
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode *p1 = pre, *p2 = pre;
    for(int i=0; i<n; ++i)
        p2 = p2->next;
    while(p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p1->next->next;
    return pre->next;
}

/*
 * Merge two sorted linked lists and return it as a new sorted list.
 * The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    while(l1 || l2) {
        if((l1 && !l2) || (l1 && l2 && l1->val < l2->val) ) {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        } else {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
    }
    return pre->next;
}
/*
 * Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
 */

ListNode* swapPairs(ListNode* head) {
    ListNode* pre = new ListNode(0);
    pre -> next = head;
    ListNode* flag = pre;
    while(flag->next && flag->next->next) {
        ListNode* first = flag->next, *second = flag->next->next;
        flag->next = second;
        first->next = second->next;
        second->next = first;
        flag = flag->next->next;
    }
    return pre->next;
}