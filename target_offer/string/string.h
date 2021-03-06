//
// Created by hl4080 on 2021/1/25.
//

#ifndef ALOGRITHM_STRING_H
#define ALOGRITHM_STRING_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

void replaceSpace(char *str,int length);
vector<string> Permutation(string str);
int FirstNotRepeatingChar(string str);
string LeftRotateString(string str, int n);
string ReverseSentence(string str);
int StrToInt(string str);
bool hasPath(string matrix, int rows, int cols, string str);

class SstreamFirstAppear
{
public:
    //Insert one char from stringstream
    void Insert(char ch);
    //return the first appearence once char in current stringstream
    char firstAppearingOnce();

private:
    unordered_map<char, int> m;
    queue<char> q;
};


#endif //ALOGRITHM_STRING_H
