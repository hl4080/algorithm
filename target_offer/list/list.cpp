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

/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
示例1
输入

{1,3,5},{2,4,6}
返回值

{1,2,3,4,5,6}
 */

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    ListNode* n = new ListNode(0);
    ListNode* node = n;
    while(pHead1 || pHead2) {
        if(!pHead1 || (pHead2 && pHead1->val > pHead2->val)) {
            node->next = pHead2;
            pHead2 = pHead2->next;
        } else {
            node->next = pHead1;
            pHead1 = pHead1->next;
        }
        node = node->next;
    }
    return n->next;
}