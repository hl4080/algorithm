//
// Created by hl4080 on 2021/1/25.
//

#include <iostream>
#include "../../target_offer/string/string.h"


void test_replaceSpace() {
    cout<<"============simple test replace space begin============="<<endl;
    char str[] = "We Are Happy";
    int length = 12;
    cout<<"test case: str:\""<<str<<"\" "<<"length:"<<length<<endl;
    replaceSpace(str, length);
    char desired[] = "We%20Are%20Happy";
    string s1 = str, s2 = desired;
    if(s1 == s2) {
        cout<<"result of test case: "<<s1<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test replace space begin============="<<endl;
}