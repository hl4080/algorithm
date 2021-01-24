//
// Created by hl4080 on 2020/6/20.
//

#include "test/test.h"

int main(int argc, char* argv[]) {
    //if(argc != 3)
    //   cerr<<"no valid arguments! "<<endl;
    map<string, FUNC> leetMap;  //associate the test function with its problem index
    map<string, FUNC> offerMap;   //associate the test function with its problem index
    initProblemMap(leetMap);
    initProblemMap(offerMap);
    //for leetcode, index's first char should be l
    //for target offer, index's first char should be o
    string index = "o1";
    map<string, FUNC>::iterator it;
    switch(index[0]) {
        case 'l':
            it = leetMap.find(index);
            break;
        case 'o':
            it = offerMap.find(index);
            break;
        default:
            cerr<<"invalid problem index!"<<endl;
    }
    if(it == leetMap.end()) {
        cerr<<"invaild query index"<<endl;
        exit(1);
    }
    it->second();
}