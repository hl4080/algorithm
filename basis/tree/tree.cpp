//
// Created by hl4080 on 2021/3/29.
//

#include "tree.h"

void preorderdfs(TreeNode* root, vector<int>& res) {
    if(!root) return;
    res.push_back(root->val);
    preorderdfs(root->left, res);
    preorderdfs(root->right, res);
}

void preorderIter(TreeNode* root, vector<int>& res) {
    if(!root) return;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        res.push_back(node->val);
        if(node->right) stk.push(node->right);
        if(node->left) stk.push(node->left);
    }
}