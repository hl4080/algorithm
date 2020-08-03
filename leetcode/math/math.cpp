//
// Created by hl4080 on 2020/7/3.
//

#include "./math.h"

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

bool isPalindrome(int x) {
    if(x < 0) return false;
    long result = 0, tmp = x;
    while(x > 0) {
        result = result*10 + x%10;
        x /= 10;
    }
    return tmp == result;
}

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
*/

int reverseInteger(int x) {
    long result = 0;
    while(x != 0) {
        result = result*10 + x%10;
        x /= 10;
    }
    if(result > INT_MAX  || result < INT_MIN) return 0;
    return result;
}

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

int singleNumber(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int result = nums[0];
    for(int i=1; i<nums.size(); ++i)
        result ^= nums[i];
    return result;
}

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

string zigzagConvert(string s, int numRows) {
    if(numRows == 1) return s;
    string result;
    vector<string> rows(min((int)s.size(), numRows));
    for(int i=0, row = 0, down = 1; i<s.size(); ++i) {
        rows[row] += s[i];
        row = down? row+1: row-1;
        if(!row || row == numRows-1) down = !down;
    }
    for(int i=0; i<rows.size(); ++i) {
        result += rows[i];
    }
    return result;
}

/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 */

int uniquePaths(int m, int n) {
    if(n==1 || m == 1) return 1;
    int shrt = m>n? n: m;
    long res = 1, k=m+n-2;
    for(int i=1; i<=shrt-1; ++i) {
        res = res*k/i;
        k--;
    }
    return res;
}
