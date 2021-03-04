//
// Created by hl4080 on 2021/1/26.
//

#ifndef ALOGRITHM_TREE_H
#define ALOGRITHM_TREE_H


#include "../../leetcode/data-struct.h"
#include <queue>
#include <string>
#include <cmath>

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
void Mirror(TreeNode *pRoot);
vector<int> PrintFromTopToBottom(TreeNode* root);
bool VerifySquenceOfBST(vector<int>& sequence);
vector<vector<int> > FindPath(TreeNode* root,int expectNumber);
TreeNode* Convert2List(TreeNode* pRootOfTree);
int TreeDepth(TreeNode* pRoot);
bool IsBalancedTree(TreeNode* pRoot);
TreeLinkNode* GetNextLinkNode(TreeLinkNode* pNode);
bool isSymmetrical(TreeNode* pRoot);
vector<vector<int> > PrintZTree(TreeNode* pRoot);
vector<vector<int> > PrintLevelTree(TreeNode* pRoot);
char* SerializeTree(TreeNode *root);
TreeNode* DeserializeTree(char *str);
TreeNode* KthNode(TreeNode* pRoot, int k);

#endif //ALOGRITHM_TREE_H
