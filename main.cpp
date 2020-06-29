//
// Created by hl4080 on 2020/6/20.
//

#include "test/leetcode/leetcode_test.h"

int main() {
    map<string, FUNC> leetMap;  //associate the test function with its problem index
    initLeetMap(leetMap);
    string index = "1";
    auto it = leetMap.find(index);
    if(it == leetMap.end())
        cerr<<"invaild query index"<<endl;
    it->second();
}