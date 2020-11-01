//
// Created by hl4080 on 2020/9/22.
//

#ifndef ALOGRITHM_GRAPH_H
#define ALOGRITHM_GRAPH_H


#include <vector>
#include <map>
#include <string>
#include <queue>
#include "../data-struct.h"
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList);
Node* cloneGraph(Node* node);
bool courseSchedule(int numCourses, vector<vector<int>>& prerequisites);
vector<int> courseScheduleII(int numCourses, vector<vector<int>>& prerequisites);


#endif //ALOGRITHM_GRAPH_H
