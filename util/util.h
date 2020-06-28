//
// Created by hl4080 on 2020/6/25.
//

#ifndef ALOGRITHM_UTIL_H
#define ALOGRITHM_UTIL_H

#include <vector>
#include "../leetcode/data-struct.h"
#include <iostream>

using namespace std;

vector<int> list2Vector(ListNode*);
ListNode* vector2List(vector<int>&);
void printOneDimVec(vector<int> vec);
void printTwoDimVec(vector<vector<int>> vec);
void printListNode(ListNode* l);

#endif //ALOGRITHM_UTIL_H
