//
// Created by hl4080 on 2020/6/20.
//

#include "test/test.h"

int main(int argc, char* argv[]) {
    //if(argc != 3)
     //  cerr<<"no valid arguments! "<<endl;
    map<string, FUNC> leetMap;  //associate the test function with its problem index
    map<string, FUNC> offerMap;
    map<string, FUNC> basisMap;
    initProblemMap(leetMap);
    initProblemMap(offerMap);
    initProblemMap(basisMap);
    //for leetcode, index's first char should be 'l'
    //for target offer, index's first char should be 'o'
    //for basis algorithms, index's first char should be 'b'
    string index = "b5";
    map<string, FUNC>::iterator it;
    switch(index[0]) {
        case 'l':
            it = leetMap.find(index);
            if(it == leetMap.end()) {
                cerr<<"invalid query index"<<endl;
                exit(1);
            }
            break;
        case 'o':
            it = offerMap.find(index);
            if(it == offerMap.end()) {
                cerr<<"invalid query index"<<endl;
                exit(1);
            }
            break;
        case 'b':
            it = basisMap.find(index);
            if(it == basisMap.end()) {
                cerr<<"invalid query index"<<endl;
                exit(1);
            }
            break;
        default:
            cerr<<"invalid problem index!"<<endl;
    }
    it->second();
}