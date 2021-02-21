//
// Created by hl4080 on 2021/1/26.
//

#include "../../target_offer/tree/tree.h"
#include "../../util/util.h"
#include <iostream>

void test_reconstructTree() {
    cout<<"============simple test reconstruct tree begin============="<<endl;
    vector<int> pre{1,2,3,4,5,6,7}, vin{3,2,4,1,6,5,7};
    cout<<"test case:"<<endl;
    cout<<"pre order: ";
    printOneDimVec(pre);
    cout<<"in order: ";
    printOneDimVec(vin);
    TreeNode* res = reConstructBinaryTree(pre, vin), *desired = buildTree(vin, 0, vin.size()-1);
    if(treesEqual(res, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reconstruct tree end==============="<<endl;
}


void test_subTree() {
    cout<<"============simple test is sub tree begin============="<<endl;
    vector<int> vec1{4,2,5,1,1,3,-1}, vec2{4,2,5};
    TreeNode* root1 = buildTree(vec1, 0, vec1.size()-1), *root2 = buildTree(vec2, 0, vec2.size()-1);
    cout<<"test case: "<<endl;
    cout<<"tree 1:"<<endl;
    printTree(root1);
    cout<<"tree 2:"<<endl;
    printTree(root2);
    bool res = HasSubtree(root1, root2), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is sub tree end==============="<<endl;
}

void test_Mirror() {
    cout<<"============simple test mirror begin============="<<endl;
    vector<int> vec1{4,2,5,1,-1,3,-1}, vec2{-1,3,-1,1,5,2,4};
    TreeNode* root1 = buildTree(vec1, 0, vec1.size()-1), *root2 = buildTree(vec2, 0, vec2.size()-1);
    cout<<"test case:"<<endl;
    printTree(root1);
    Mirror(root1);
    if(treesEqual(root1, root2)) {
        cout<<"result of test case: "<<endl;
        printTree(root1);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test mirror end==============="<<endl;
}

void test_printTreeLevel() {
    cout<<"============simple test print tree level begin============="<<endl;
    vector<int> vec{4,2,5,1,-1,3,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    vector<int> res = PrintFromTopToBottom(root), desired{1,2,3,4,5};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test print tree level end==============="<<endl;
}

void test_verifyBST() {
    cout<<"============simple test verify BST begin============="<<endl;
    vector<int> vec{4,8,6,12,16,14,10};
    cout<<"test case: ";
    printOneDimVec(vec);
    bool res = VerifySquenceOfBST(vec), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test verify BST end==============="<<endl;
}

void test_findPath() {
    cout<<"============simple test find path begin============="<<endl;
    vector<int> vec{1,3,4,2,-1,7,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int exp = 9;
    cout<<"exp number: "<<exp<<endl;
    vector<vector<int>> res = FindPath(root, exp), desired{{2,3,4}, {2,7}};
    printTwoDimVec(res);
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find path end==============="<<endl;
}

void test_convert2List() {
    cout<<"============simple test convert to list begin============="<<endl;
    vector<int> vec{1,2,3}, vec1{-1,1,2,2,2,3,-1};
    TreeNode* root = buildTree(vec,0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    TreeNode* res = Convert2List(root), *desired = buildTree(vec1, 0, vec1.size()-1);
    res = res->right;
    if(treesEqual(res, desired)) {
        cout<<"result of test case: "<<endl;
        printTree(desired);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test convert to list end==============="<<endl;
}

void test_treeDepth() {
    cout<<"============simple test tree depth begin============="<<endl;
    vector<int> vec{4,5,2,1,-1,3,-1};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    cout<<"test case: "<<endl;
    printTree(root);
    int res = TreeDepth(root), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test tree depth end==============="<<endl;
}