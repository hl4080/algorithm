//
// Created by hl4080 on 2021/1/26.
//

#ifndef ALOGRITHM_TREE_H
#define ALOGRITHM_TREE_H


#include "../../leetcode/data-struct.h"
#include <queue>

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
void Mirror(TreeNode *pRoot);
vector<int> PrintFromTopToBottom(TreeNode* root);

#endif //ALOGRITHM_TREE_H
