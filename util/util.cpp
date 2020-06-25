//
// Created by hl4080 on 2020/6/25.
//

#include "util.h"

vector<int> list2Vector(ListNode* l) {
    vector<int> result;
    while(l) {
        result.push_back(l->val);
        l = l->next;
    }
    return result;
}

ListNode* vector2List(vector<int>& vec) {
    ListNode* l = new ListNode(0);
    ListNode* pre = l;
    l->next = NULL;
    for(int i=0; i<vec.size(); ++i) {
        ListNode* tmp = new ListNode(vec[i]);
        tmp->next = l->next;
        l->next = tmp;
        l = l->next;
    }
    return pre->next;
}