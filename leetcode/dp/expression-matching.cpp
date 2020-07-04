//
// Created by hl4080 on 2020/7/4.
//
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

#include "dp.h"

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

//dp[i][j] represents s[0:i] matches with p[0:j]
//if p[j] != '*'   dp[i][j] = dp[i-1][j-1]  if s[i] == p[j] or p[j] == '.'
//                          = false         else
//if p[j] == '*'   dp[i][j] = dp[i-1][j] or dp[i][j-2]  if s[i] == p[j] or p[j] == '.'  //represent 0 or one more same p[j]
//                          = dp[i][j-2]                else