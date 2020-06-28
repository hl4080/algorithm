//
// Created by hl4080 on 2020/6/20.
//

#include "test/leetcode/leetcode_test.h"

int main(int argc, char* argv[]) {
    if(argc != 2)
        cerr<<"no valid arguments! "<<endl;
    map<string, FUNC> leetMap;  //associate the test function with its problem index
    initLeetMap(leetMap);
    string index = argv[1];
    auto it = leetMap.find(index);
    if(it == leetMap.end())
        cerr<<"invaild query index"<<endl;
    it->second();
}