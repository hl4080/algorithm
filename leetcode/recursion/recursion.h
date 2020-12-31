//
// Created by hl4080 on 2020/7/10.
//

#ifndef ALOGRITHM_RECURSION_H
#define ALOGRITHM_RECURSION_H

#include <string>
#include <vector>
#include <numeric>

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
vector<string> restoreIpAddresses(string s);
int minPathTriangle(vector<vector<int>>& triangle);
void surroundRegions(vector<vector<char>>& board);
vector<vector<string>> palindromePartition(string s);
int numIslands(vector<vector<char>>& grid);
vector<vector<int>> combinationSum3(int k, int n);
vector<int> lexicalOrder(int n);

#endif //ALOGRITHM_RECURSION_H
