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
