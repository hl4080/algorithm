//
// Created by hl4080 on 2021/1/24.
//

#include "target_offer_test.h"

void test_find() {
    cout<<"============simple test find begin============="<<endl;
    vector<vector<int>> array{
            {1,2,8,9},
            {2,4,9,12},
            {4,7,10,13},
            {6,8,11,15}
    };
    int target = 7;
    cout<<"test case: "<<endl;
    cout<<"target: "<<target<<endl;
    cout<<"array:"<<endl;
    printTwoDimVec(array);
    bool res = Find(target, array), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find begin============="<<endl;
}
