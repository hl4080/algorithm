//
// Created by hl4080 on 2021/1/26.
//

#include "list.h"

/*
 * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
示例1
输入
复制
{67,0,24,58}
返回值
复制
[58,24,0,67]
 */

void printListFromTailToHeadHelp(ListNode* head, vector<int>& res) {
    if(!head) return;
    printListFromTailToHeadHelp(head->next, res);
    res.push_back(head->val);
}

vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> res;
    printListFromTailToHeadHelp(head, res);
    return res;
}


/*
 * 输入一个链表，输出该链表中倒数第k个结点。
示例1
输入

1,{1,2,3,4,5}
返回值

{5}
 */

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode* p1 = pListHead, *p2 = pListHead;
    for(int i=0; i<k; i++) {
        if(!p1) return NULL;
        p1 = p1->next;
    }
    while(p1) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

/*
 * 输入一个链表，反转链表后，输出新链表的表头。
示例1
输入
{1,2,3}
返回值
{3,2,1}
 */

ListNode* ReverseList(ListNode* pHead) {
    if(!pHead) return pHead;
    ListNode* node = ReverseList(pHead->next);
    if(!pHead->next) {
        pHead->next = NULL;
        return pHead;
    }
    pHead->next->next = pHead;
    pHead->next = NULL;
    return node;
}