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


/*
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
示例1
输入

{8,8,#,9,#,2,#,5},{8,9,#,2}
返回值

true
 */

bool HasSubtreeHelp(TreeNode* pRoot1, TreeNode* pRoot2) {
    if(!pRoot2) return true;
    if(!pRoot1) return false;
    return pRoot1->val == pRoot2->val && HasSubtreeHelp(pRoot1->left, pRoot2->left) && HasSubtreeHelp(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if(!pRoot1 || !pRoot2) return false;
    return HasSubtreeHelp(pRoot1, pRoot2) || HasSubtreeHelp(pRoot1->left, pRoot2) || HasSubtreeHelp(pRoot1->right, pRoot2);
}

/*
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
 */

void Mirror(TreeNode *pRoot) {
    if(!pRoot) return;
    swap(pRoot->left, pRoot->right);
    if(pRoot->left) Mirror(pRoot->left);
    if(pRoot->right) Mirror(pRoot->right);
}

/*
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
示例1
输入

{5,4,#,3,#,2,#,1}
返回值

[5,4,3,2,1]
 */

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int len = q.size();
        for(int i=0; i<len; i++) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return res;
}

/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。
示例1
输入

[4,8,6,12,16,14,10]
返回值

true
 */

bool VerifySquenceOfBSTHelp(vector<int>& sequence, int start, int end) {
    if(start >= end) return true;
    int leftIdx = 0;
    for(int i=start; i<=end; i++) {
        if(sequence[leftIdx] < sequence[end]) leftIdx = i;
        else break;
    }
    for(int i=leftIdx; i<=end; i++) {
        if(sequence[end] > sequence[i]) return false;
    }
    return VerifySquenceOfBSTHelp(sequence, start, leftIdx-1) && VerifySquenceOfBSTHelp(sequence, leftIdx, end-1);
}

bool VerifySquenceOfBST(vector<int>& sequence) {
    if(sequence.empty()) return false;
    return VerifySquenceOfBSTHelp(sequence, 0, sequence.size()-1);
}

/*
输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
示例1


{10,5,12,4,7},22
返回值

[[10,5,7],[10,12]]
示例2

复制
{10,5,12,4,7},15
返回值

[]
 */

void findPathHelp(vector<vector<int>>& res, vector<int> path, TreeNode* root, int exp) {
    if(!root || exp<0) return;
    path.push_back(root->val);;
    if(!root->left && !root->right && exp == root->val) {
        res.push_back(path);
        return;
    }
    findPathHelp(res, path, root->left, exp-root->val);
    findPathHelp(res, path, root->right, exp-root->val);
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    vector<int> path;
    findPathHelp(res, path, root, expectNumber);
    return res;
}

/*
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 */


TreeNode* pre=NULL;
TreeNode* first = NULL;
TreeNode* Convert2List(TreeNode* pRootOfTree) {
    if (pRootOfTree==NULL)
        return NULL;
    Convert2List(pRootOfTree->left);
    if(!first) first = pRootOfTree;
    if (pre!= NULL){
        pRootOfTree->left=pre;
        pre->right=pRootOfTree;
    }
    pre=pRootOfTree;
    Convert2List(pRootOfTree->right);
    return first;
}

/*
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

 */

int TreeDepth(TreeNode* pRoot) {
    if(!pRoot) return 0;
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right))+1;
}