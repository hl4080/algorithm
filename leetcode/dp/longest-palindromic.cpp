//
// Created by hl4080 on 2020/6/30.
//

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

#include "dp.h"

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