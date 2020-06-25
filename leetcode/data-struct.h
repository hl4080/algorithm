//
// Created by hl4080 on 2020/6/25.
//

#ifndef ALOGRITHM_DATA_STRUCT_H
#define ALOGRITHM_DATA_STRUCT_H

#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif //ALOGRITHM_DATA_STRUCT_H
