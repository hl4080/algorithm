//
// Created by hl4080 on 2020/7/4.
//

#include "dp.h"

/*
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
 */

//dp[i][j] represents s[0:i] matches with p[0:j]
//if p[j] != '*'   dp[i][j] = dp[i-1][j-1]  if s[i] == p[j] or p[j] == '.'
//                          = false         else
//if p[j] == '*'   dp[i][j] = dp[i-1][j] or dp[i][j-2]  if s[i] == p[j] or p[j] == '.'  //represent 0 or one more same p[j]
//                          = dp[i][j-2]                else

bool isExpressionMatch(string s, string p) {
    int m = s.size(), n = p.size();
    auto match = [&](int i, int j) {
        if(i == 0) return false;
        return s[i-1] == p[j-1] || p[j-1] == '.';
    };
    vector<vector<bool>> dp(m+1, vector<bool>(n+1));
    dp[0][0] = true;
    for(int i=0; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(p[j-1] == '*') {
                if(match(i, j-1)) dp[i][j] = dp[i-1][j] || dp[i][j-2];
                else dp[i][j] = dp[i][j-2];
            } else dp[i][j] = match(i, j)? dp[i-1][j-1]: dp[i][j];
        }
    }
    return dp[m][n];
}

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
 */

//recursion equation P(i, j) = P(i+1, j-1) && s[i] == s[j]
//boundary condition
//P[i, i] = 1
//P[i, i+1] = s[i] == s[i+1]
string longestPalindrome(string s) {
    int len = s.size();
    string result;
    vector<vector<bool>> dp(len+1, vector<bool>(len+1, 0));
    for(int i=len; i>=0; --i) {
        for(int j=i; j<=len; ++j) {
            if(i == j) dp[i][j] = true;
            else if(j-i == 1) dp[i][j] = s[i] == s[j];
            else dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            if(dp[i][j] && (j-i+1) > result.size())
                result = s.substr(i, j-i+1);
        }
    }
    return result;
}

/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
 */

int maxSubArray(vector<int>& nums) {
    //f(i) represents sum of subarray end with nums[i]
    //recursive expression: f(i) = max(f(i-1)+nums[i], nums[i])
    if(nums.empty()) return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for(int i=1; i<nums.size(); ++i) {
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
    }
    int res = INT_MIN;
    for(int i=0; i<dp.size(); ++i)
        res = max(res, dp[i]);
    return res;
}

/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
 */

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //f(i, j) = 0   if obstacle[i, j] == 1
    //f(i, j) = f(i-1, j) + f(i, j-1) if obstacle[i, j] == 0
    if(obstacleGrid.empty()) return 0;
    vector<int> pre(obstacleGrid[0].size()+1, 0), cur(obstacleGrid[0].size()+1, 0);
    cur[0] = 1;
    for(int i=0; i<obstacleGrid.size(); ++i) {
        for(int j=0; j<obstacleGrid[0].size(); ++j) {
            if(i==0) cur[j+1] = obstacleGrid[i][j]? 0: cur[j];
            else cur[j+1] = obstacleGrid[i][j]? 0: cur[j] + pre[j+1];
            pre = cur;
            cur[0] = 0;
        }
    }
    return cur[obstacleGrid[0].size()];
}

/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
 * which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<int> pre(n+1, 0), cur(n+1, 0);
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j)
            cur[j+1] = i==0? cur[j]+grid[i][j]: j==0? pre[j+1] + grid[i][j]: min(cur[j], pre[j+1])+grid[i][j];
        pre = cur;
    }
    return cur[n];
}

/*
 * You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 */

int climbStairs(int n) {
    int a1 = 1, a2 = 2, res;
    if(n==1) return a1;
    if(n==2) return a2;
    for(int i=3; i<=n; ++i) {
        res = a1+a2;
        a1 = a2;
        a2 = res;
    }
    return res;
}