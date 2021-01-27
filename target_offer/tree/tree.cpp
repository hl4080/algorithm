//
// Created by hl4080 on 2021/1/26.
//

#include "tree.h"

/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
示例1
输入
复制
[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
返回值
复制
{1,2,5,3,4,6,7}
 */

TreeNode* reconstructBinaryTreeHelp(vector<int>& pre, int pBegin, int pEnd, vector<int>& vin, int vBegin, int vEnd) {
    if(pBegin>pEnd) return NULL;
    TreeNode* root = new TreeNode(pre[pBegin]);
    int index = vBegin;
    for(int i=vBegin; i<=vEnd; i++) {
        if(vin[i] == pre[pBegin]) index = i;
    }
    root->left = reconstructBinaryTreeHelp(pre, pBegin+1, pBegin+index-vBegin, vin, vBegin, index-1);
    root->right = reconstructBinaryTreeHelp(pre, pBegin+index-vBegin+1, pEnd, vin, index+1, vEnd);
    return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    return reconstructBinaryTreeHelp(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
}
