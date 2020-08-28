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