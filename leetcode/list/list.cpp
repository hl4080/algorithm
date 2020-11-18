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

/*
 * Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

 */

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* cur = head;
    while(cur && cur->next) {
        ListNode* tmp = cur->next->next;
        cur->next->next = pre->next;
        pre->next = cur->next;
        cur->next = tmp;
    }
    return pre->next;
}

/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

 */

void reorderList(ListNode* head) {
    if(!head || !head->next) return;
    int l = 0;
    ListNode* pre = head;
    while(pre) {
        pre = pre->next;
        l++;
    }
    int k = l%2==0? l/2: l/2+1;
    ListNode* p = head;
    while(k-1) {
        p = p->next;
        k--;
    }
    ListNode* tmp = p->next;
    p->next = NULL;
    p = tmp;
    ListNode* post = reverseList(p);
    pre = head;
    while(pre) {
        ListNode* tmp = pre->next;
        pre->next = post? post: NULL;
        pre = tmp;
        if(!post) return;
        ListNode* tmp2 = post->next;
        post->next = pre;
        post = tmp2;
    }
}

/*
 * Sort a linked list using insertion sort.

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

 */

ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* cur = head, *nxt = head->next;
    cur->next = NULL;
    while(nxt) {
        ListNode* tmpn = nxt->next;
        ListNode* tmpc = cur;
        while(cur != nxt) {
            if((!cur->next && cur->val <= nxt->val) || (cur->val <= nxt->val && nxt->val < cur->next->val)) {
                nxt->next = cur->next;
                cur->next = nxt;
                break;
            } else if((!cur->next && cur->val > nxt->val) || cur->val > nxt->val) {
                nxt->next = cur;
                tmpc = nxt;
                break;
            } else cur = cur->next;
        }
        cur = tmpc;
        nxt = tmpn;
    }
    return cur;
}

/*
 * Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

 */
ListNode* findMiddle(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* slow = head, *fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* tmp = slow->next;
    slow->next = NULL;
    return tmp;
}

ListNode* mergeListsHelp(ListNode* l1, ListNode* l2) {
    ListNode* pre = new ListNode(0);
    ListNode* f = pre;
    while(l1 || l2) {
        if(!l1 || (l2&&l2->val <= l1->val)) {
            pre->next = l2;
            pre = pre->next;
            l2 = l2->next;
        } else{
            pre->next = l1;
            pre = pre->next;
            l1 = l1->next;
        }
    }
    pre->next = NULL;
    return f->next;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* right = findMiddle(head);
    return mergeListsHelp(sortList(head), sortList(right));
}

/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

begin to intersect at node c1.

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5].
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

 */

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA, *p2 = headB;
    if(!p1 || !p2) return NULL;
    int reverse = 0;
    while(p1 != p2) {
        if(!p1) {
            p1 = headB;
            reverse++;
            continue;
        }
        if(!p2) {
            p2 = headA;
            reverse++;
            continue;
        }
        p1 = p1->next;
        p2 = p2->next;
        if(reverse > 2) return NULL;
    }
    return p1;
}

/*
 * Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

 */

ListNode* removeElements(ListNode* head, int val) {
    ListNode* pre = new ListNode(0);
    pre->next = head;
    ListNode* res = pre;
    while(pre) {
        while(pre->next && pre->next->val == val) pre->next = pre->next->next;
        pre = pre->next;
    }
    return res->next;
}

/*
 * Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true

 */

ListNode* front;
bool recursiveCheck(ListNode* head) {
    if(head) {
        if(!recursiveCheck(head->next)) return false;
        if(head->val != front->val) return false;
        front = front->next;
    }
    return true;
}
bool isPalindromeList(ListNode* head) {
    front = head;
    return recursiveCheck(head);
}