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

/*
 * Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

 */

Node* cloneGraphHelp(Node* node, map<Node*, Node*>& m) {
    if(!node) return NULL;
    if(m.count(node)) return m[node];
    Node* cloneNode = new Node(node->val);
    m[node] = cloneNode;
    for(int i=0; i<node->neighbors.size(); i++) {
        cloneNode->neighbors.push_back(cloneGraphHelp(node->neighbors[i], m));
    }
    return cloneNode;
}

Node* cloneGraph(Node* node) {
    map<Node*, Node*> m;
    Node* root = cloneGraphHelp(node, m);
    return root;
}

/*
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.

 */

bool courseSchedule(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDeg(numCourses, 0);
    vector<vector<int>> adj(numCourses, vector<int>());
    int numRes = 0;
    for(int i=0; i<prerequisites.size(); i++){
        inDeg[prerequisites[i][1]]++;
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    queue<int> q;
    for(int i=0; i<numCourses; i++)
        if(!inDeg[i]) q.push(i);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        numRes++;
        for(int i=0; i<adj[node].size(); i++) {
            int pointed = adj[node][i];
            inDeg[pointed]--;
            if(inDeg[pointed] == 0) q.push(pointed);
        }
    }
    return numRes == numCourses;
}