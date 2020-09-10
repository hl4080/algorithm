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

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 */

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    bool reverse = 0;
    while(!q.empty()) {
        vector<int> tmp(q.size(), 0);
        int qlen = q.size();
        for(int i = reverse? qlen-1: 0; reverse? i>=0: i<qlen; reverse?--i: ++i) {
            TreeNode* node = q.front();
            q.pop();
            tmp[i] = node->val;
            if(node->left) q.push(node->left);
            if(node->right)  q.push(node->right);
        }
        res.push_back(tmp);
        reverse = !reverse;
    }
    return res;
}

/*
 * Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

 */

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
}

/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

 */
TreeNode* buildTreeFromPreAndInorderHelp(vector<int>& preorder, vector<int>& inorder,
        map<int, int>& m, int preStart,int preEnd, int inStart, int inEnd) {
    if(preStart > preEnd || inStart > inEnd) return NULL;
    int val = preorder[preStart];
    TreeNode* root = new TreeNode(val);
    int inIdx = m[val];
    int preIdx = inIdx-inStart+1+preStart;
    root->left = buildTreeFromPreAndInorderHelp(preorder, inorder, m, preStart+1, preIdx-1, inStart, inIdx-1);
    root->right = buildTreeFromPreAndInorderHelp(preorder, inorder, m, preIdx, preEnd, inIdx + 1, inEnd);
    return root;
}

TreeNode* buildTreeFromPreAndInorder(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> m;
    for(int i=0; i<inorder.size(); ++i)
        m[inorder[i]] = i;
    return buildTreeFromPreAndInorderHelp(preorder, inorder, m, 0, preorder.size()-1, 0, inorder.size()-1);
}

/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

 */
TreeNode* buildTreeFromInAndPostOrderHelp(vector<int>& inorder, vector<int>& postorder, map<int, int>& m,
        int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart > inEnd || postStart > postEnd) return NULL;
    int val = postorder[postEnd];
    TreeNode* root = new TreeNode(val);
    int inIdx = m[val];
    int postIdx = inIdx - inStart + postStart;
    root->left = buildTreeFromInAndPostOrderHelp(inorder, postorder, m, inStart, inIdx-1, postStart, postIdx-1);
    root->right = buildTreeFromInAndPostOrderHelp(inorder, postorder, m, inIdx+1, inEnd, postIdx, postEnd-1);
    return root;
}

TreeNode* buildTreeFromInAndPostOrder(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> m;
    for(int i=0; i<inorder.size(); ++i) {
        m[inorder[i]] = i;
    }
    return buildTreeFromInAndPostOrderHelp(inorder, postorder, m, 0, inorder.size()-1, 0, postorder.size()-1);
}

/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

 */

TreeNode* sortedArrayToBSTHelp(vector<int>& nums, int begin, int end) {
    if(begin > end) return NULL;
    int mid = begin + (end-begin+1)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelp(nums, begin, mid - 1);
    root->right = sortedArrayToBSTHelp(nums, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelp(nums, 0, nums.size()-1);
}

/*
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
 */

int getListLength(ListNode* head) {
    int res = 0;

    for(; head; head = head->next)
        res++;
    return res;
}

TreeNode* sortedListToBSTHelp(ListNode* &head, int left, int right) {
    if(left > right) return NULL;
    int mid = left+(right-left+1)/2;
    TreeNode* root = new TreeNode();
    root->left = sortedListToBSTHelp(head, left, mid-1);
    root->val = head->val;
    head = head->next;
    root->right = sortedListToBSTHelp(head, mid+1, right);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int len = getListLength(head);
    return sortedListToBSTHelp(head, 0, len-1);
}

/*
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

 */

int height(TreeNode* root) {
    if(!root) return 0;
    int hleft = height(root->left), hright = height(root->right);
    if(hleft == -1 || hright == -1 || abs(hleft-hright) > 1) return -1;
    return hleft > hright? hleft+1: hright+1;
}

bool isBalancedTree(TreeNode* root) {
    return height(root) > -1;
}

/*
 * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its minimum depth = 2.
 */

int minDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left) return minDepth(root->right)+1;
    if(!root->right) return minDepth(root->left)+1;
    return min(minDepth(root->left), minDepth(root->right))+1;
}