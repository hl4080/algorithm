//
// Created by hl4080 on 2021/1/25.
//

#include <iostream>
#include "../../target_offer/string/string.h"
#include "../../util/util.h"


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

void test_permutation() {
    cout<<"============simple test permutation begin============="<<endl;
    string s = "aab";
    cout<<"test case: s="<<s<<endl;
    vector<string> res = Permutation(s), desired{"aab", "aba", "baa"};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test permutation end==============="<<endl;
}

void test_firstNotRepeatChar() {
    cout<<"============simple test first not repeat char begin============="<<endl;
    string s = "google";
    cout<<"test case: s="<<endl;
    int res = FirstNotRepeatingChar(s), desired = 4;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test first not repeat char end==============="<<endl;
}

void test_leftRotatedString() {
    cout<<"============simple test left rotated string begin============="<<endl;
    string s = "XYZdefabc";
    int n = 3;
    cout<<"test case: s="<<s<<" n="<<n<<endl;
    string res = LeftRotateString(s, n), desired = "defabcXYZ";
    if(res == desired) {
        cout<<"resuklt of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test left rotated string end==============="<<endl;
}

void test_reverseSentence() {
    cout<<"============simple test reverse string begin============="<<endl;
    string s = "nowcoder. a am I";
    cout<<"test case: s="<<s<<endl;
    string res = ReverseSentence(s), desired = "I am a nowcoder.";
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test reverse string end==============="<<endl;
}

void test_string2int() {
    cout<<"============simple test string 2 int begin============="<<endl;
    string s = "+2147483647";
    cout<<"test case: s="<<s<<endl;
    int res = StrToInt(s), desired = 2147483647;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test string 2 int end==============="<<endl;
}

void test_stringFirstAppear() {
    cout<<"============simple test string stream first appear char begin============="<<endl;
    SstreamFirstAppear sstring;
    sstring.Insert('a');
    sstring.Insert('b');
    char res = sstring.firstAppearingOnce(), desired = 'a';
    sstring.Insert('a');
    char res2 = sstring.firstAppearingOnce(), desired2 = 'b';
    cout<<"test case: insert(a), insert(b), firstAppear1, insert(a), firstAppear2"<<endl;
    if(res == desired && res2 == desired2) {
        cout<<"result of test case: firstAppear1: "<<res<<" firstAppear2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test string stream first appear char end==============="<<endl;
}

void test_hasPath() {
    cout<<"============simple test has path begin============="<<endl;
    string s = "ABCESFCSADEE";
    int row = 3, col = 4;
    string str = "ABCCED";
    cout<<"test case: s="<<s<<" row="<<row<<" col="<<col<<" str="<<str<<endl;
    bool res = hasPath(s, row, col, str), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test has path end==============="<<endl;
}