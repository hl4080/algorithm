//
// Created by hl4080 on 2020/8/27.
//

#ifndef ALOGRITHM_TREE_H
#define ALOGRITHM_TREE_H

#include "../data-struct.h"
#include <vector>

using namespace std;

vector<int> inorderTraversal(TreeNode* root);
vector<TreeNode*> generateTreesII(int n);
bool isValidBST(TreeNode* root);
bool isSameTree(TreeNode* p, TreeNode* q);
bool isSymmetric(TreeNode* root);

#endif //ALOGRITHM_TREE_H
