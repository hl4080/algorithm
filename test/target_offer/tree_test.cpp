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

