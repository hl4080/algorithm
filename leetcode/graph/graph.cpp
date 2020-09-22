//
// Created by hl4080 on 2020/9/22.
//

#include "graph.h"

/*
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

 */

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int len = beginWord.size();
    map<string, vector<string>> m;
    queue<pair<int, string>> q;
    map<string, bool> visited;
    for(int i=0; i<wordList.size(); i++) {
        for(int j=0; j<len; j++) {
            string key = wordList[i].substr(0, j) + "*" +wordList[i].substr(j+1);
            if(m.count(key) > 0) m[key].push_back(wordList[i]);
            else {
                vector<string> tmp;
                tmp.push_back(wordList[i]);
                m.insert(make_pair(key, tmp));
            }
        }
    }
    q.push(make_pair(1, beginWord));
    visited[beginWord] = true;
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        for(int i=0; i<len; i++) {
            string key = node.second.substr(0, i) + "*" + node.second.substr(i+1);
            for(int j=0; j<m[key].size(); j++) {
                if(m[key][j] == endWord) return node.first+1;
                if(!visited[m[key][j]]) {
                    q.push(make_pair(node.first+1, m[key][j]));
                    visited[m[key][j]] = true;
                }
            }
        }
    }
    return 0;
}
