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

/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 */

bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    if(!root->left && !root->right && root->val == sum) return true;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */

void pathSumHelp(TreeNode* root, vector<vector<int>>& res, vector<int> piece, int sum) {
    if(!root) return;
    piece.push_back(root->val);
    if(!root->left && !root->right && sum == root->val) {
        res.push_back(piece);
        piece.pop_back();
        return;
    }
    pathSumHelp(root->left, res, piece, sum-root->val);
    pathSumHelp(root->right, res, piece, sum-root->val);

}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> piece;
    pathSumHelp(root, res, piece, sum);
    return res;
}

/*
 * Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

 */

void flattenTree(TreeNode* root) {
    TreeNode* node = root;
    while(node) {
        if(node->left) {
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            node->right = l;
            while(l->right) l = l->right;
            l->right = r;
            node->left = nullptr;
        }
        node = node->right;
    }
}

/*
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate
each next pointer to point to its next right node, just like in Figure B.
The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

 */

//see more details on leetcode

/*
 * Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

 */

//see more details at leetcode

/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

 */

int sumToLeafNumbersHelp(TreeNode* root, int path) {
    if(!root) return 0;
    if(!root->left && !root->right) return path*10 + root->val;
    path = path*10 + root->val;
    return sumToLeafNumbersHelp(root->left, path) + sumToLeafNumbersHelp(root->right, path);
}

int sumToLeafNumbers(TreeNode* root) {
    int path = 0;
    return sumToLeafNumbersHelp(root, path);
}

/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

 */
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        vector<TreeNode*> tmp;
        while(!q.empty()) {
            tmp.push_back(q.front());
            q.pop();
        }
        res.push_back(tmp[tmp.size()-1]->val);
        for(int i=0; i< tmp.size(); i++) {
            if(tmp[i]->left) q.push(tmp[i]->left);
            if(tmp[i]->right) q.push(tmp[i]->right);
        }
    }
    return res;
}

/*
 * Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
 and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

 */

int leftDepth(TreeNode* root) {
    if(!root) return 0;
    return leftDepth(root->left)+1;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int ldepth = leftDepth(root->left);
    int rdepth = leftDepth(root->right);
    if(ldepth == rdepth)
        return pow(2, ldepth) + countNodes(root->right);
    else
        return pow(2, rdepth) + countNodes(root->left);
}

/*
 * Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 */

TreeNode* invertTree(TreeNode* root) {
    if(!root) return NULL;
    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

 */
int numberNodes(TreeNode* root) {
    if(!root) return 0;
    return numberNodes(root->left)+numberNodes(root->right)+1;
}
int kthSmallestTree(TreeNode* root, int k) {
    int lnum = numberNodes(root->left);
    if(lnum < k-1) return kthSmallestTree(root->right, k-1-lnum);
    else if(lnum == k-1) return root->val;
    return kthSmallestTree(root->left, k);
}

/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int low = p->val>q->val? q->val: p->val;
    int high = p->val>q->val? p->val: q->val;
    if(root->val < low)  return lowestCommonAncestor(root->right, p, q);
    else if(root->val > high) return lowestCommonAncestor(root->left, p, q);
    return root;
}

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

 */
TreeNode* ancestor;
bool isInTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return false;
    bool isL = isInTree(root->left, p, q);
    bool isR = isInTree(root->right, p, q);
    if((isL&&isR) || ((root->val == p->val || root->val == q->val) && (isL || isR))) ancestor = root;
    return isL || isR || root->val == p->val || root->val == q->val;
}
TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q) {
    isInTree(root, p, q);
    return ancestor;
}

/*
 * Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

 */

void binaryTreePathsHelp(TreeNode* root, vector<string>& res, string single) {
    if(!root) return;
    if(!root->left && !root->right) {
        single += to_string(root->val);
        res.push_back(single);
        return;
    }
    single += to_string(root->val);
    single += "->";
    if(root->left) binaryTreePathsHelp(root->left, res, single);
    if(root->right) binaryTreePathsHelp(root->right, res, single);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string single;
    binaryTreePathsHelp(root, res, single);
    return res;
}

/*
 * A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Example 1:

Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

 */

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==1) return vector<int>{0};
    if(n==1) return vector<int>{0};
    vector<int> degrees(n, 0);
    vector<vector<int>> adj(n, vector<int>());
    vector<int> res;
    for(int i=0; i<edges.size(); ++i) {
        degrees[edges[i][0]]++;
        degrees[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> del;
    int count = n;
    while(1) {
        if(count <= 2) {
            for(int i=0; i<n; ++i)
                if(degrees[i] > 0) res.push_back(i);
            return res;
        }
        int big1 = 0;
        for(int i=0; i<n; ++i) {
            big1 += degrees[i]>1? 1:0;
        }
        if(big1 == 1) {
            for(int i=0; i<n; ++i) {
                if(degrees[i]>1) return vector<int>{i};
            }
        }
        vector<int> iter;
        for(int i=0; i<n; i++) {
            if(degrees[i] == 1) {
                count--;
                degrees[i]--;
                iter.push_back(i);
            }
        }
        for(int i=0; i<iter.size(); ++i) {
            for(int j=0; j<adj[iter[i]].size(); ++j) degrees[adj[iter[i]][j]]--;
        }
    }
    return res;
}

/*
 * The thief has found himself a new place for his thievery again.
 * There is only one entrance to this area, called the "root."
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree".
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

 */

vector<int> robTreeHelp(TreeNode* root) {
    if(!root) return vector<int>{0,0};
    vector<int> lcount = robTreeHelp(root->left);
    vector<int> rcount = robTreeHelp(root->right);
    int c0 = max(lcount[0], lcount[1]) + max(rcount[0], rcount[1]);
    int c1 = root->val + lcount[0] + rcount[0];
    return vector<int>{c0, c1};
}

int robTree(TreeNode* root) {
    vector<int> res = robTreeHelp(root);
    return max(res[0], res[1]);
}