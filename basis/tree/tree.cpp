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
    TreeNode* node = root;
    while(node || !stk.empty()) {
        while(node) {
            res.push_back(node->val);
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
}

void inorderdfs(TreeNode* root, vector<int>& res) {
    if(!root) return ;
    inorderdfs(root->left, res);
    res.push_back(root->val);
    inorderdfs(root->right, res);
}

void inorderIter(TreeNode* root, vector<int>& res) {
    if(!root) return;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while(node || !stk.empty()) {
        while(node) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        res.push_back(node->val);
        stk.pop();
        node = node->right;
    }
}

void postorderdfs(TreeNode* root, vector<int>& res) {
    if(!root) return;
    postorderdfs(root->left, res);
    postorderdfs(root->right, res);
    res.push_back(root->val);
}

void postorderIter(TreeNode* root, vector<int>& res) {
    if(!root) return;
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    stk1.push(root);
    while(!stk1.empty()) {
        TreeNode* node = stk1.top();
        stk1.pop();
        stk2.push(node);
        if(node->left) stk1.push(node->left);
        if(node->right) stk1.push(node->right);
    }
    while(!stk2.empty()) {
        TreeNode* node = stk2.top();
        stk2.pop();
        res.push_back(node->val);
    }
}