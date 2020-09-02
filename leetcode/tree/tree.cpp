//
// Created by hl4080 on 2020/8/27.
//

#include "tree.h"

/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
     2
/
3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

void inorderDfs(vector<int>& res, TreeNode* root) {
    if(!root) return;
    inorderDfs(res, root->left);
    res.push_back(root->val);
    inorderDfs(res, root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorderDfs(res, root);
    return res;
}

/*
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

vector<TreeNode*> generateTreesIIHelp(int start, int end) {
    if(start > end) return vector<TreeNode*>{NULL};
    vector<TreeNode*> trees;
    for(int i=start; i<=end; ++i) {
        vector<TreeNode*> left = generateTreesIIHelp(start, i-1);
        vector<TreeNode*> right = generateTreesIIHelp(i+1, end);
        for(int j=0; j<left.size(); ++j) {
            for(int k=0; k<right.size(); ++k) {
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                trees.push_back(root);
            }
        }
    }
    return trees;
}

vector<TreeNode*> generateTreesII(int n) {
    if(!n) return vector<TreeNode*>();
    return generateTreesIIHelp(1, n);
}

/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 */

bool isValidBSTHelp(TreeNode* root, long low, long upper) {
    if(!root) return true;
    if(root->val <= low || root->val >= upper) return false;
    return isValidBSTHelp(root->left, low, root->val) && isValidBSTHelp(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelp(root, LONG_MIN, LONG_MAX);
}

/*
 * Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
 */

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if((p&&!q) || (!p&&q) || (p->val != q->val)) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 */

bool isSymmetricHelp(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2) return true;
    if((!root1 && root2) || (root1 && !root2) || root1->val != root2->val) return false;
    return isSymmetricHelp(root1->left, root2->right) && isSymmetricHelp(root1->right, root2->left);
}

bool isSymmetric(TreeNode* root) {
    return isSymmetricHelp(root, root);
}

/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 */

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        vector<int> tmp;
        int qsz = q.size();
        for(int i=0; i<qsz; ++i) {
            TreeNode* node = q.front();
            tmp.push_back(node->val);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(tmp);
    }
    return res;
}