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
void printListNode(ListNode* l);

template <class T> void printOneDimVec(vector<T> vec) {
    for(int i=0; i<vec.size(); ++i)
        cout<<vec[i]<<" ";
    cout<<endl;
}
template <class T> void printTwoDimVec(vector<vector<T>> vec) {
    for(int i=0; i<vec.size(); ++i)
        printOneDimVec(vec[i]);
}

#endif //ALOGRITHM_UTIL_H
