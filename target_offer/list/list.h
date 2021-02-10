//
// Created by hl4080 on 2021/1/26.
//

#ifndef ALOGRITHM_LIST_H
#define ALOGRITHM_LIST_H

#include "../../leetcode/data-struct.h"
#include <vector>

using namespace std;

vector<int> printListFromTailToHead(ListNode* head);
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
ListNode* ReverseList(ListNode* pHead);
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
RandomListNode* CloneRandomList(RandomListNode* pHead);


#endif //ALOGRITHM_LIST_H
