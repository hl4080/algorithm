//
// Created by hl4080 on 2020/6/30.
//

#ifndef ALOGRITHM_DP_H
#define ALOGRITHM_DP_H

#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

string longestPalindrome(string s);
bool isExpressionMatch(string s, string p);
int maxSubArray(vector<int>& nums);
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
int minPathSum(vector<vector<int>>& grid);
int climbStairs(int n);
int numDecodings(string s);
int numTrees(int n);
int maxProfitI(vector<int>& prices);
int maxProfitII(vector<int>& prices);
bool wordBreak(string s, vector<string>& wordDict);
int maxProduct(vector<int>& nums);
int houseRob(vector<int>& nums);
int houseRobII(vector<int>& nums);

#endif //ALOGRITHM_DP_H
