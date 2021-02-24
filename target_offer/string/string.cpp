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

/*
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
示例1
输入

"google"
返回值

4
 */

int FirstNotRepeatingChar(string str) {
    vector<int> vec(256, 0);
    for(auto ch:str) vec[ch]++;
    char t;
    for(int i=0; i<str.size(); i++) {
        if(vec[str[i]] == 1) return i;
    }
    return -1;
}

/*
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */

string LeftRotateString(string str, int n) {
    if(str.empty()) return str;
    int shift = n%str.size();
    str += str.substr(0,shift);
    return str.substr(shift);
}

/*
 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 */

string ReverseSentence(string str) {
    int p1 = str.size()-1;
    int p2 = p1;
    string res;
    while(p2>=0) {
        if(p2 == 0) {
            res += str.substr(0, p1-p2+1);
            return res;
        }else if(str[p2] == ' ') {
            res += str.substr(p2+1, p1-p2);
            res += ' ';
            p1 = p2-1;
            p2 = p1;
        } else p2--;
    }
    return res;
}