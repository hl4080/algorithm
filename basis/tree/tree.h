//
// Created by hl4080 on 2021/3/29.
//

#ifndef ALOGRITHM_TREE_H
#define ALOGRITHM_TREE_H

#include <vector>
#include <queue>
#include <stack>
#include "../../leetcode/data-struct.h"

using namespace std;

void preorderdfs(TreeNode* root, vector<int>& res);
void preorderIter(TreeNode* root, vector<int>& res);
void inorderdfs(TreeNode* root, vector<int>& res);
void inorderIter(TreeNode* root, vector<int>& res);
void postorderdfs(TreeNode* root, vector<int>& res);
void postorderIter(TreeNode* root, vector<int>& res);

#endif //ALOGRITHM_TREE_H
