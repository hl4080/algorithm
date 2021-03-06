//
// Created by hl4080 on 2021/1/25.
//

#include <unordered_map>
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

/*
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
返回值描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入

"+2147483647"
返回值

2147483647
示例2
输入

"1a33"
返回值

0
 */

int StrToInt(string str) {
    int res = 0;
    int bit = 1;
    for(int i=str.size()-1; i>=0; i--) {
        if(i == 0) {
            if(str[i] == '+') return res;
            else if(str[i] == '-') return -res;
        }
        if(str[i] < '0' || str[i] > '9') return 0;
        else res += (str[i]-'0')*bit;
        bit *=10;
    }
    return res;
}

/*
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
示例1
输入

"123.45e+6"
返回值

true
 */

bool isNumeric(string str) {

}

/*
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
返回值描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
 */

//Insert one char from stringstream
void SstreamFirstAppear::Insert(char ch) {
    if(!m.count(ch)) q.push(ch);
    m[ch]++;
}
//return the first appearence once char in current stringstream
char SstreamFirstAppear::firstAppearingOnce() {
    while(!q.empty()) {
        char head = q.front();
        if(m[head] == 1) return head;
        else q.pop();
    }
    return '#';
}

/*
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
  矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
示例1
输入

"ABCESFCSADEE",3,4,"ABCCED"
返回值

true
 */
bool hasPathHelp(vector<vector<bool>>& visited, string matrix, int rows, int cols, string str, int index, int i, int j) {
    if(i<0 || i>=rows || j<0 || j>cols || visited[i][j] || str[index] != matrix[i*cols+j]) return false;
    visited[i][j] = true;
    if(index == str.size()-1) return true;
    index++;
    if(hasPathHelp(visited, matrix, rows, cols, str, index, i-1, j) || hasPathHelp(visited, matrix, rows, cols, str, index, i, j-1) ||
       hasPathHelp(visited, matrix, rows, cols, str, index, i+1, j) || hasPathHelp(visited, matrix, rows, cols, str, index, i, j+1)) {
        return true;
    }
    visited[i][j] = false;
    return false;
}

bool hasPath(string matrix, int rows, int cols, string str) {
    if(str.size() > matrix.size()) return false;
    vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(hasPathHelp(visited, matrix, rows, cols, str, 0, i, j)) return true;
        }
    }
    return false;
}