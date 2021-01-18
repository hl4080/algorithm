//
// Created by hl4080 on 2020/8/27.
//

#include "leetcode_test.h"

void test_inorderTreeTravel() {
    cout<<"============simple test inorder tree travel begin============="<<endl;
    vector<int> vec{-1, -1, -1, 1, 3, 2, -1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    vector<int> res = inorderTraversal(root), desired{1, 3, 2};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test inorder tree travel end==============="<<endl;
}

void test_generateTreesII() {
    cout<<"============simple test generate trees II begin============="<<endl;
    int n=2;
    vector<TreeNode*> trees = generateTreesII(n);
    vector<int>vec1{-1,1,2}, vec2{1, 2, -1};
    TreeNode* root1 = buildTree(vec1, 0, vec1.size()-1), *root2 = buildTree(vec2, 0, vec2.size()-1);
    if(treesEqual(root1, trees[0]) && treesEqual(root2, trees[1])) {
        cout<<"result of test case: "<<endl;
        printTree(trees[0]);
        printTree(trees[1]);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test generate trees II end==============="<<endl;
}

void test_isValidTree() {
    cout<<"============simple test is valid tree begin============="<<endl;
    vector<int> vec{-1,1,-1,5,3,4,6};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    bool res = isValidBST(root), desired = false;
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is valid tree end==============="<<endl;
}

void test_isSameTree() {
    cout<<"============simple test is same tree begin============="<<endl;
    vector<int> vec1{1,2,3}, vec2{2,4,6};
    TreeNode* root1 = buildTree(vec1, 0, vec1.size()-1), *root2 = buildTree(vec2, 0, vec2.size()-1);
    bool res = isSameTree(root1, root2), desired = false;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is same tree end==============="<<endl;
}

void test_isSymmetric() {
    cout<<"============simple test is symmetric begin============="<<endl;
    vector<int> vec{3,2,4,1,4,2,3};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    bool res = isSymmetric(root), desired = true;
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is symmetric end==============="<<endl;
}

void test_levelOrder() {
    cout<<"============simple test level order travel begin============="<<endl;
    vector<int> vec{-1,9,-1,3,15,20,7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    vector<vector<int>> res = levelOrder(root);
    vector<vector<int>> desired{
            {3},
            {9,20},
            {15,7}
    };
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test level order travel end==============="<<endl;
}

void test_zigzagOrder() {
    cout<<"============simple test zigzag level order begin============="<<endl;
    vector<int> vec{-1, 9, -1, 3, 15, 20, 7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    vector<vector<int>> res = zigzagLevelOrder(root);
    vector<vector<int>> desired {
            {3},
            {20, 9},
            {15, 7}
    };
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test zigzag level order end==============="<<endl;
}

void test_maxDepth() {
    cout<<"============simple test max depth begin============="<<endl;
    vector<int> vec{-1, 9, -1, 3, 15, 20, 7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    int res = maxDepth(root), desired = 3;
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test max depth end==============="<<endl;
}

void test_buildTreeFromPreAndInorder() {
    cout<<"============simple test Construct Binary Tree from Preorder and Inorder Traversal begin============="<<endl;
    vector<int> preorder{3,9,20,15,7}, inorder{9,3,15,20,7};
    TreeNode* root = buildTreeFromPreAndInorder(preorder, inorder);
    vector<int> vec{-1, 9, -1, 3, 15, 20, 7};
    TreeNode* desired = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    cout<<"preorder: ";
    printOneDimVec(preorder);
    cout<<"inorder: ";
    printOneDimVec(inorder);
    if(treesEqual(root, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(root);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test Construct Binary Tree from Preorder and Inorder Traversal end==============="<<endl;
}

void test_buildTressFromInAndPostOrder() {
    cout<<"============simple test Construct Binary Tree from Inorder and postorder Traversal begin============="<<endl;
    vector<int> inorder{9,3,15,20,7}, postorder{9,15,7,20,3};
    TreeNode* root = buildTreeFromInAndPostOrder(inorder, postorder);
    vector<int> vec{-1, 9, -1, 3, 15, 20, 7};
    TreeNode* desired = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    cout<<"inorder: ";
    printOneDimVec(inorder);
    cout<<"postorder: ";
    printOneDimVec(postorder);
    if(treesEqual(root, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(root);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test Construct Binary Tree from Inorder and postorder Traversal end==============="<<endl;
}

void test_sortedArrayToBST() {
    cout<<"============simple test sorted array to BST begin============="<<endl;
    vector<int> nums{0,3,7,10,15};
    TreeNode* root = sortedArrayToBST(nums);
    vector<int> vec{0,3,-1,7,-1,10,15};
    TreeNode* desired = buildTree(vec, 0, vec.size()-1);
    if(treesEqual(root, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(root);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sorted array to BST end==============="<<endl;
}

void test_sortedListToBST() {
    cout<<"============simple test sorted list to BST begin============="<<endl;
    vector<int> vec{-10, -3, 0, 5, 9};
    ListNode* head = vector2List(vec);
    TreeNode* root = sortedListToBST(head);
    vector<int> vec2{-10, -3, -1, 0, 5, 9, -1};
    TreeNode* desired = buildTree(vec2, 0, vec2.size()-1);
    if(treesEqual(root, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(root);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sorted list to BST end==============="<<endl;
}

void test_isBalancedTree() {
    cout<<"============simple test is balanced tree begin============="<<endl;
    vector<int> vec{-1,9,-1,3,15,20,7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    bool res = isBalancedTree(root), desired = true;
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is balanced tree end==============="<<endl;
}

void test_minDepth() {
    cout<<"============simple test min depth begin============="<<endl;
    vector<int> vec{-1,9,-1,3,15,20,7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    int res = minDepth(root), desired = 2;
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test min depth end==============="<<endl;
}

void test_hasPathSum() {
    cout<<"============simple test has path sum begin============="<<endl;
    vector<int> vec{-1,9,-1,3,15,20,7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    int sum = 12;
    bool res = hasPathSum(root, sum), desired = true;
    cout<<"test case:"<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test has path sum end==============="<<endl;
}

void test_pathSum() {
    cout<<"============simple test path sum begin============="<<endl;
    vector<int> vec{-1,9,-1,3,15,2,7};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    int sum = 12;
    vector<vector<int>> res = pathSum(root, sum);
    vector<vector<int>> desired{
            {3,9},
            {3,2,7}
    };
    cout<<"test case: "<<endl;
    printTree(root);
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test path sum end==============="<<endl;
}

void test_flattenTree() {
    cout<<"============simple test flatten tree begin============="<<endl;
    vector<int> vec{7,3,9};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    vector<int> vec2{-1,-1,-1,3,-1,7,9};
    TreeNode* desired = buildTree(vec2, 0, vec2.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    flattenTree(root);
    if(treesEqual(root, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(root);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test flatten tree end==============="<<endl;
}

void test_sumRootToLeaf() {
    cout<<"============simple test sum root to leaf node begin============="<<endl;
    vector<int> vec{2,1,3};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int res = sumToLeafNumbers(root), desired = 25;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sum root to leaf node end==============="<<endl;
}

void test_rightSideView() {
    cout<<"============simple test right side view begin============="<<endl;
    vector<int> vec{-1,2,5,1,-1,3,4};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case:"<<endl;
    printTree(root);
    vector<int> res = rightSideView(root), desired{1,3,4};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test right side view end==============="<<endl;
}

void test_countNodes() {
    cout<<"============simple test count nodes begin============="<<endl;
    vector<int> vec{4,2,5,1,6,3,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int res = countNodes(root), desired = 6;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test count nodes end==============="<<endl;
}

void test_invertBinaryTree() {
    cout<<"============simple test invert binary tree begin============="<<endl;
    vector<int> vec{1,2,3,4,6,7,9};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    TreeNode* res = invertTree(root);
    vector<int> vec1{9,7,6,4,3,2,1};
    TreeNode* desired = buildTree(vec1, 0, vec1.size()-1);
    if(treesEqual(res, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test invert binary tree end==============="<<endl;
}

void test_kthSmallestElementBST() {
    cout<<"============simple test kth smallest elements in BST begin============="<<endl;
    vector<int> vec{-1,1,2,3,1,4,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int res = kthSmallestTree(root,1), desired = 1;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test kth smallest elements in BST end==============="<<endl;
}

void test_lowestCommonAncestor() {
    cout<<"============simple test lowest common ancestor begin============="<<endl;
    vector<int> vec{-1,0,-1,2,3,4,5,6,-1,7,-1,8,-1,9,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    TreeNode* p = new TreeNode(2), *q = new TreeNode(8);
    TreeNode* res = lowestCommonAncestor(root, p, q), *desired = new TreeNode(6);
    if(res->val == desired->val) {
        cout<<"result of test case: "<<res->val<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test lowest common ancestor end==============="<<endl;
}

void test_lowestCommonAncestorII() {
    cout<<"============simple test lowest common ancestor II begin============="<<endl;
    vector<int> vec{-1,0,-1,2,3,4,5,6,-1,7,-1,8,-1,9,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    TreeNode* p = new TreeNode(2), *q = new TreeNode(8);
    TreeNode* res = lowestCommonAncestor(root, p, q), *desired = new TreeNode(6);
    if(res->val == desired->val) {
        cout<<"result of test case: "<<res->val<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test lowest common ancestor II end==============="<<endl;
}

void test_binaryTreePath() {
    cout<<"============simple test binary tree path begin============="<<endl;
    vector<int> vec{-1,2,5,1,-1,3,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    vector<string> res = binaryTreePaths(root), desired = {"1->2->5", "1->3"};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test binary tree path end==============="<<endl;
}

void test_findMinHeightTrees() {
    cout<<"============simple test find min height trees begin============="<<endl;
    int n = 6;
    vector<vector<int>> edges{
            {3,0},
            {3,1},
            {3,2},
            {3,4},
            {5,4}
    };
    cout<<"test case:"<<endl;
    cout<<"n="<<n<<endl;
    printTwoDimVec(edges);
    vector<int> res = findMinHeightTrees(n, edges), desired{3,4};
    if(res == desired) {
        cout<<"result of test case ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find min height trees end==============="<<endl;
}

void test_houseRobIII() {
    cout<<"============simple test house rob III begin============="<<endl;
    vector<int> nums{-1,2,3,3,-1,3,1};
    TreeNode* root = buildTree(nums, 0, nums.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int res = robTree(root), desired = 7;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test house rob III end==============="<<endl;
}

void test_sumOfLeafNodes() {
    cout<<"============simple test sum of leaf nodes begin============="<<endl;
    vector<int> nums{-1,9,-1,3,15,20,7};
    TreeNode* root = buildTree(nums, 0, nums.size()-1);
    cout<<"test case:"<<endl;
    printTree(root);
    int res = sumOfLeftLeaves(root), desired = 24;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test sum of leaf nodes end==============="<<endl;
}

void test_pathSumIII() {
    cout<<"============simple test path sum III begin============="<<endl;
    vector<int> nums{-1,5,-1,3,1,2,3};
    TreeNode* root = buildTree(nums, 0, nums.size()-1);
    cout<<"test case:"<<endl;
    printTree(root);
    int sum = 8;
    cout<<"sum="<<sum<<endl;
    int res = pathSumIII(root, sum), desired = 2;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUSL FAILED"<<endl;
    cout<<"============simple test path sum III end==============="<<endl;
}

void test_deleteTreeNode() {
    cout<<"============simple test delete node begin============="<<endl;
    vector<int> nums{2,3,4,5,-1,6,7};
    TreeNode* root = buildTree(nums, 0, nums.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int target = 7;
    TreeNode* res = deleteTreeNode(root, target);
    vector<int> des{2,3,4,5,-1,6,-1};
    TreeNode* desired = buildTree(des, 0, des.size()-1);
    if(treesEqual(res, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test delete node end==============="<<endl;
}