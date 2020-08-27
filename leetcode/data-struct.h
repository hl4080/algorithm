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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
#endif //ALOGRITHM_DATA_STRUCT_H
