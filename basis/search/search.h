//
// Created by hl4080 on 2021/3/20.
//

#ifndef ALOGRITHM_SEARCH_H
#define ALOGRITHM_SEARCH_H

#include <vector>
using namespace std;

int seqSearch(vector<int>& nums, int target);
int binarySearchIter(vector<int>& nums, int target);
int binarySearchRecurive(vector<int>& nums, int target);
int differentialSort(vector<int>& nums, int target);
int fabonacciSearch(vector<int>& nums, int target);
int hashSearch(vector<int>& nums, int target);
int binaryTreeSearch(vector<int>& nums, int target);

struct BinarySearchNode {
    int val;
    int index;
    BinarySearchNode* left;
    BinarySearchNode* right;
    BinarySearchNode(int index, int val): index(index), val(val), left(NULL), right(NULL) {}
};

#endif //ALOGRITHM_SEARCH_H
