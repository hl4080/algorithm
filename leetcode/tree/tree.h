//
// Created by hl4080 on 2020/8/27.
//

#ifndef ALOGRITHM_TREE_H
#define ALOGRITHM_TREE_H

#include "../data-struct.h"
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> inorderTraversal(TreeNode* root);
vector<TreeNode*> generateTreesII(int n);
bool isValidBST(TreeNode* root);
bool isSameTree(TreeNode* p, TreeNode* q);
bool isSymmetric(TreeNode* root);
vector<vector<int>> levelOrder(TreeNode* root);
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
int maxDepth(TreeNode* root);
TreeNode* buildTreeFromPreAndInorder(vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTreeFromInAndPostOrder(vector<int>& inorder, vector<int>& postorder);
TreeNode* sortedArrayToBST(vector<int>& nums);
TreeNode* sortedListToBST(ListNode* head);
bool isBalancedTree(TreeNode* root);
int minDepth(TreeNode* root);

#endif //ALOGRITHM_TREE_H
