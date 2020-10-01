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

/*
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
 */

ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return NULL;
    if(!head->next) return head;
    ListNode* tail = head;
    int n;
    for(n=1; tail->next; ++n)
        tail = tail->next;
    tail->next = head;
    tail = head;
    for(int i=0; i<n-k%n-1; ++i)
        tail = tail->next;
    ListNode* node = tail->next;
    tail->next = NULL;
    return node;
}

/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
 */

ListNode* deleteDuplicatesListII(ListNode* head) {
    if(!head) return head;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* p1 = head, *p2 = p1->next, *f = pre;
    while(p1 && p2) {
        if(p1->val != p2->val) {
            f->next = p1;
            f = p1;
            p1 = p1->next;
            p2 = p2->next;
            continue;
        }
        while(p2 && p1->val == p2->val) p2 = p2->next;
        f->next = p2;
        p1 = p2;
        p2 = p2==NULL? NULL: p2->next;
    }
    return pre->next;
}

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
 */

ListNode* deleteDuplicatesSortedList(ListNode* head) {
    if(!head) return head;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* p0 = head, *p1 = head->next;
    while(p1) {
        while(p1 && p0->val == p1->val) p1 = p1->next;
        p0->next = p1;
        p0 = p0->next;
        p1 = p1? p1->next: NULL;
    }
    return pre->next;
}

/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
 */

ListNode* partitionLists(ListNode* head, int x) {
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* p0 = pre, *p1 = head;
    while(p1 && p1->val < x) {
        p1 = p1->next;
        p0 = p0->next;
    }
    while(p1) {
        ListNode* tmp;
        if(p1->val >= x) {
            tmp = p1;
            p1 = p1->next;
        } else {
            tmp->next = p1->next;
            p1->next = p0->next;
            p0->next = p1;
            p1 = tmp->next;
            p0 = p0->next;
        }
    }
    return pre->next;
}

/*
 * Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

ListNode* reverseListBetween(ListNode* head, int m, int n) {
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* lm = head, *ln, *flag = pre;
    for(int i=1; i<m; ++i) lm = lm->next, pre = pre->next;
    ln = lm;
    for(int i=0; i<n-m; ++i) ln = ln->next;
    ListNode* tail = ln->next;
    for(int i=0; i<=n-m; ++i) {
        ListNode* tmp = lm->next;
        lm->next = tail;
        pre->next = lm;
        tail = lm;
        lm = tmp;
    }
    return flag->next;
}

/*
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

 */

bool listCycle(ListNode *head) {
    if(!head || !head->next) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast && (fast && fast->next));
    return fast == slow;
}

/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

 */

ListNode* listCycleII(ListNode *head) {
    if(!head || !head->next) return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast && (fast && fast->next));
    if(slow != fast) return NULL;
    //we get the interation node, then get the neeting point
    ListNode* pre = head;
    while(pre != slow) {
        pre = pre->next;
        slow = slow->next;
    }
    return pre;
}