//
// Created by hl4080 on 2021/3/29.
//

#include "../../basis/tree/tree.h"
#include "../../util/util.h"

void test_preoderTree() {
    cout<<"============simple test is valid tree begin============="<<endl;
    vector<int> vec{-1,1,-1,5,3,4,6};
    TreeNode* root = buildTree(vec, 0, vec.size()-1);
    vector<int> res1, res2, desired{5,1,4,3,6};
    preorderdfs(root, res1);
    preorderIter(root, res2);
    cout<<"test case: "<<endl;
    printTree(root);
    if(res1 == desired && res2 == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res1);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is valid tree end==============="<<endl;
}