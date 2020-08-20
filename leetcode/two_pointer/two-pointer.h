//
// Created by hl4080 on 2020/6/23.
//

#ifndef TWO_POINTER_H
#define TWO_POINTER_H

#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool isHappy(int n);
vector<vector<int>> threeSum(vector<int>& nums);
int lengthOfLongestSubstring(string s);
int maxWaterArea(vector<int>& height);
int threeSumClosest(vector<int>& nums, int target);
int removeDuplicates(vector<int>& nums);
void nextPermutation(vector<int>& nums);
string countAndSay(int n);
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals);
void sortColors(vector<int>& nums);
int removeDeplicatesII(vector<int>& nums);
void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n);

#endif //TWO_POINTER_H
