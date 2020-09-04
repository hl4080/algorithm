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
