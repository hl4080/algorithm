//
// Created by hl4080 on 2020/7/10.
//

#ifndef ALOGRITHM_RECURSION_H
#define ALOGRITHM_RECURSION_H

#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits);
vector<string> generateParenthesis(int n);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
vector<vector<int>> integerPermute(vector<int>& nums);
vector<vector<int>> permuteUnique(vector<int>& nums);
string getSpecialPermutation(int n, int k);
vector<vector<int>> combinations(int n, int k);
vector<vector<int>> subsets(vector<int>& nums);
bool wordExistBoard(vector<vector<char>>& board, string word);
vector<int> grayCode(int n);
vector<vector<int>> subsetsWithDup(vector<int>& nums);

#endif //ALOGRITHM_RECURSION_H
