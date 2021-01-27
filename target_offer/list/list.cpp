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