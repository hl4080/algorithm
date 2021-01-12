//
// Created by hl4080 on 2020/6/20.
//

#ifndef ALGORITHM_HASH_H
#define ALGORITHM_HASH_H

#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
int romanToInt(string s);
bool isValidSudoku(vector<vector<char>>& board);
vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<string> findRepeatedDnaSequences(string s);
bool isIsomorphic(string s, string t);
bool containsDuplicate(vector<int>& nums);
bool containsNearbyDuplicate(vector<int>& nums, int k);
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
vector<int> topKFrequent(vector<int>& nums, int k);
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);
int minMutation(string start, string end, vector<string>& bank);

#endif //ALGORITHM_HASH_H
