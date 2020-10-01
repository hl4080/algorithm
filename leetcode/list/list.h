//
// Created by hl4080 on 2020/6/25.
//

#ifndef LIST_H
#define LIST_H

#include "../data-struct.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* removeNthFromEnd(ListNode* head, int n);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
ListNode* swapPairs(ListNode* head);
ListNode* rotateRight(ListNode* head, int k);
ListNode* deleteDuplicatesListII(ListNode* head);
ListNode* deleteDuplicatesSortedList(ListNode* head);
ListNode* partitionLists(ListNode* head, int x);
ListNode* reverseListBetween(ListNode* head, int m, int n);
bool listCycle(ListNode *head);
ListNode* listCycleII(ListNode *head);

#endif //LIST_H
