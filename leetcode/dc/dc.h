//
// Created by hl4080 on 2020/6/27.
//

#ifndef ALOGRITHM_DC_H
#define ALOGRITHM_DC_H

#include <vector>
#include <string>
#include <map>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
string longestCommonPrefix(vector<string>& strs);
int searchInRotatedArray(vector<int>& nums, int target);
vector<int> searchElementPositions(vector<int>& nums, int target);
int searchInsertPosition(vector<int>& nums, int target);
void rotateImage(vector<vector<int>>& matrix);
bool searchMatrix(vector<vector<int>>& matrix, int target);
bool searchRotatedArrayII(vector<int>& nums, int target);
int findMinSortedArray(vector<int>& nums);
int findPeakElement(vector<int>& nums);
int findKthLargest(vector<int>& nums, int k);
vector<int> diffWaysToCompute(string input);
void wiggleSortII(vector<int>& nums);
int kthSmallestMatrix(vector<vector<int>>& matrix, int k);
int longestSubstring(string s, int k);

#endif //ALOGRITHM_DC_H
