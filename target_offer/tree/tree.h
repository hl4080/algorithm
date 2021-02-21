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
bool VerifySquenceOfBST(vector<int>& sequence);
vector<vector<int> > FindPath(TreeNode* root,int expectNumber);
TreeNode* Convert2List(TreeNode* pRootOfTree);
int TreeDepth(TreeNode* pRoot);
bool IsBalancedTree(TreeNode* pRoot);

#endif //ALOGRITHM_TREE_H
