//
// Created by hl4080 on 2020/9/22.
//

#include "leetcode_test.h"

void test_ladderLength() {
    cout<<"============simple test ladder length begin============="<<endl;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    int res = ladderLength(beginWord, endWord, wordList), desired = 5;
    cout<<"test case: "<<endl;
    cout<<"begin word: "<<beginWord<<" "<<"end word: "<<endWord<<endl;
    cout<<"word list: ";
    printOneDimVec(wordList);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test ladder length end==============="<<endl;
}

