//
// Created by hl4080 on 2021/1/25.
//

#include "string.h"

/*
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

void replaceSpace(char *str,int length) {
    int cnt = 0;
    for(int i=0; i<length; i++) {
        if(str[i] == ' ') cnt++;
    }
    int newLength = length + cnt*2;
    str[newLength] = '\0';
    int p2 = newLength-1, p1 = length-1;
    while(p1 >=0) {
        if(str[p1] != ' ') {
            str[p2] = str[p1];
            p2--;
        }else {
            str[p2-2] = '%';
            str[p2-1] = '2';
            str[p2] = '0';
            p2 -= 3;
        }
        p1--;
    }
}

/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
示例1
输入
"ab"
返回值
["ab","ba"]
 */

void PermutationHelp(vector<string>& res, string piece, map<char, int>& m, int len) {
    if(piece.size() == len) {
        res.push_back(piece);
        return;
    }
    for(auto it=m.begin(); it!=m.end(); it++) {
        if(!it->second) continue;
        piece += it->first;
        it->second--;
        PermutationHelp(res, piece, m, len);
        it->second++;
        piece.pop_back();
    }
}

vector<string> Permutation(string str) {
    map<char, int> m;
    for(int i=0; i<str.size(); i++) m[str[i]]++;
    vector<string> res;
    string piece;
    PermutationHelp(res, piece, m, str.size());
    return res;
}