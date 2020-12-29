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

/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

int numDecodings(string s) {
    //3 conditions: s[i] = '0', if s[i-1] = '1' or '2', dp[i] = dp[i-2], else return 0
    //              s[i-1] = '1', dp[i] = dp[i-1] + dp[i-2]
    //              s[i-1] = '2', if '0'<=s[i]<='6', dp[i] = dp[i-1] + dp[i-2], else dp[i] = dp[i-1]
    if(s.empty() || s[0] == '0') return 0;
    int pre2=1, pre1=1, cur = 1;
    for(int i=1; i<s.size(); ++i) {
        if(s[i] == '0') {
            if(s[i-1] == '1' || s[i-1] == '2') cur = pre2;
            else return 0;
        }
        else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')) cur = pre1 + pre2;
        else cur = pre1;
        pre2 = pre1;
        pre1 = cur;
    }
    return cur;
}

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

1         3     3      2      1
\       /     /      / \      \
     3     2     1      1   3      2
/     /       \                 \
   2     1         2                 3
*/

int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<=i-1; ++j) {
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

 */

int maxProfitI(vector<int>& prices) {
    if(prices.empty()) return 0;
    int minValue = prices[0], res = INT_MIN;
    for(int i=0; i<prices.size(); i++) {
        if(prices[i] < minValue) minValue = prices[i];
        res = max(res, prices[i]-minValue);
    }
    return res;
}

/*
 * Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

 */

int maxProfitII(vector<int>& prices) {
    if(prices.empty()) return 0;
    int maxProfit = 0, buy = prices[0], sell = prices[0];
    for(int i=0; i<prices.size(); i++) {
        if(prices[i] > buy) maxProfit += prices[i] - buy;
        buy = prices[i];
    }
    return maxProfit;
}

/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

 */

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> st(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size()+1, 0);
    dp[0] = true;
    for(int i=0; i<=s.size(); i++) {
        for(int j=0; j<i; j++) {
            if(dp[j] && st.count(s.substr(j, i-j))){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

/*
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 */

int maxProduct(vector<int>& nums) {
    if(nums.empty()) return 0;
    int Min = nums[0], Max = nums[0], res = nums[0];
    for(int i=1; i<nums.size(); i++) {
        int tmpMin = Min, tmpMax = Max;
        Min = min(tmpMin*nums[i], min(tmpMax*nums[i], nums[i]));
        Max = max(tmpMax*nums[i], max(tmpMin*nums[i], nums[i]));
        res = max(res, Max);
    }
    return res;
}

/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and
 * it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

 */

int houseRob(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size()==1) return nums[0];
    int p0 = nums[0], p1 = nums[1];
    int res = max(p0, p1);
    for(int i=2; i<nums.size(); i++) {
        res = max(p0+nums[i], p1);
        p0 = max(p0,p1);
        p1 = res;
    }
    return res;
}

/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

 */

int houseRobIIHelp(vector<int>& nums, int i, int j) {
    int p0 = nums[i], p1 = nums[i+1], res = max(p0, p1);
    for(int k=i+2; k<=j; k++) {
        res = max(res, p0+nums[k]);
        p0 = max(p0, p1);
        p1 = res;
    }
    return res;
}

int houseRobII(vector<int>& nums) {
    if(nums.size() < 2) return nums.size()? nums[0]: 0;
    if(nums.size() == 2) return max(nums[0], nums[1]);
    return max(houseRobIIHelp(nums, 0, nums.size()-2), houseRobIIHelp(nums, 1, nums.size()-1));
}

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

 */

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(!m) return 0;
    int n = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!i || !j) dp[i][j] = matrix[i][j] == '1'? 1: 0;
            else dp[i][j] = matrix[i][j] == '0'? 0: min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            res = max(res, dp[i][j]);
    }
    return res*res;
}

/*Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

int numSquares(int n) {
    vector<int> squareNum;
    vector<int> dp(n+1, INT_MAX-1);
    dp[0] = 0;
    for(int i=1; i*i<=n; i++) squareNum.push_back(i*i);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<squareNum.size(); j++) {
            if(i < squareNum[j]) break;
            dp[i] = min(dp[i], dp[i-squareNum[j]]+1);
        }
    }
    return dp[n];
}

/*
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

 */

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> tails(n, 0);
    int res = 0;
    for(int i=0; i<n; ++i) {
        int left = 0, right = res;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(tails[mid] < nums[i])  left = mid + 1;
            else right = mid;
        }
        tails[left] = nums[i];
        if(right == res) res++;
    }
    return  res;
}

/*
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]

 */

vector<int> countBits(int num) {
    vector<int> res(num+1, 0);
    for(int i=1; i<=num; ++i) {
        res[i] = res[i/2] + i%2;
    }
    return res;
}

/*
 * Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

 */

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if(nums.empty()) return vector<int>();
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    vector<int> res;
    vector<vector<int>> connect(nums.size(), vector<int>());
    for(int i=0; i<nums.size(); i++) {
        connect[i].push_back(i);
        connect[i].push_back(i);
    }
    for(int i=0; i<nums.size(); i++) {
        int maxSize = 0;
        for(int j=i-1; j>=0; j--) {
            if(maxSize <= dp[j] && nums[i]%nums[j] == 0) {
                dp[i] = dp[j]+1;
                maxSize = dp[i];
                connect[i][1] = j;
            }
        }
    }
    int maxIndex = 0;
    for(int i=0; i<dp.size(); i++) {
        if(dp[maxIndex] < dp[i]) maxIndex = i;
    }
    for(int i=maxIndex; i>=0;) {
        res.push_back(nums[i]);
        int tmp = i;
        i = connect[i][1];
        if(tmp == connect[i][0]) break;
    }
    return res;
}

/*
 * We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

 */

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=n-i+1; j++) {
            int minVal = INT_MAX;
            for (int k = j; k < j + i - 1; k++)
                minVal = min(minVal, k + max(dp[j][k - 1], dp[k + 1][i+j-1]));
            dp[j][i+j-1] = minVal;
        }
    }
    return dp[1][n];
}

/*
 * A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative.
 * The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

 */

int wiggleMaxLength(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> up(nums.size(), 1);
    vector<int> down(nums.size(), 1);
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] < nums[i-1]) {
            up[i] = up[i-1];
            down[i] = max(down[i-1], up[i-1]+1);
        } else if(nums[i] == nums[i-1]) {
            up[i] = up[i-1];
            down[i] = down[i-1];
        } else {
            up[i] = max(up[i-1], down[i-1]+1);
            down[i] = down[i-1];
        }
    }
    int res = INT_MIN;
    for(int i=0; i<nums.size(); ++i) {
        res = max(res, up[i]);
        res = max(res, down[i]);
    }
    return res;
}

/*
 * Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

 */

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1, 0);
    dp[0] = 1;
    for(int i=1; i<=target; i++) {
        for(int j=0; j<nums.size(); j++) {
            if(i-nums[j] >= 0) dp[i] += dp[i-nums[j]];
        }
    }
    return dp[target];
}