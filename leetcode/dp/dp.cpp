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