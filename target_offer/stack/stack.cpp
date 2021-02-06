//
// Created by hl4080 on 2021/1/27.
//

#include "stack.h"


bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> stk;
    stk.push(pushV[0]);
    int p1 = 0, p2 = 0;
    while(p1<popV.size() || p2<popV.size()) {
        if(stk.empty()) {
            stk.push(pushV[p1]);
            continue;
        }
        if(stk.top() == popV[p2]) {
            p2++;
            stk.pop();
        } else {
            if(p1 == popV.size()) return false;
            stk.push(pushV[p1++]);
        }
    }
    return true;
}