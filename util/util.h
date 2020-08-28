//
// Created by hl4080 on 2020/6/25.
//

#ifndef ALOGRITHM_UTIL_H
#define ALOGRITHM_UTIL_H

#include <vector>
#include "../leetcode/data-struct.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<int> list2Vector(ListNode*);
ListNode* vector2List(vector<int>&);
void printListNode(ListNode* l);
void printTree(TreeNode* root);
TreeNode* buildTree(vector<int>& vec, int left, int right);
bool treesEqual(TreeNode* root1, TreeNode* root2);

template <class T> void printOneDimVec(vector<T> vec) {
    for(int i=0; i<vec.size(); ++i)
        cout<<vec[i]<<" ";
    cout<<endl;
}
template <class T> void printTwoDimVec(vector<vector<T>> vec) {
    for(int i=0; i<vec.size(); ++i)
        printOneDimVec(vec[i]);
}

template <class T> bool vecEqual(vector<T>& vec1, vector<T>& vec2) {
    if(vec1.size() != vec2.size()) return false;
    for(int i=0; i<vec1.size(); ++i)
        if(vec1[i] != vec2[i]) return false;
    return true;
}

#endif //ALOGRITHM_UTIL_H
