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

/*
 * Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
 */

int sqrtx(int x) {
    if(!x) return 0;
    double x1=x;
    while(1) {
        double xi = 0.5*(x1+x/x1);
        if(fabs(x1-xi) < 1e-5) break;
        x1 = xi;
    }
    return int(x1);
}

/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
 */

void setZeros(vector<vector<int>>& matrix) {
    if(matrix.empty()) return ;
    int m = matrix.size(), n = matrix[0].size();
    int isCol = 1;
    for(int i=0; i<m; ++i) {
        if(!matrix[i][0]) isCol = 0;
        for(int j=1; j<n; ++j) {
            if(!matrix[i][j]) matrix[0][j] = matrix[i][0] = 0;
        }
    }
    for(int i=1; i<m; ++i) {
        for(int j=1; j<n; ++j)
            if(!matrix[0][j] || !matrix[i][0]) matrix[i][j] = 0;
    }
    if(!matrix[0][0]) {
        for(int j=0; j<n; ++j)
            matrix[0][j] = 0;
    }
    if(!isCol) {
        for(int i=0; i<m; ++i)
            matrix[i][0] = 0;
    }
}

/*
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

 */
vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> res;
    for(int i=0; i<numRows; ++i) {
        vector<int> row(i+1, 1);
        for(int j=1; j<i; ++j) {
            row[j] = res[i-1][j-1]+res[i-1][j];
        }
        res.push_back(row);
    }
    return res;
}

/*
 * Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

 */

vector<int> getRowPacasalTriangle(int rowIndex) {
    vector<int> res(rowIndex+1, 1);
    res[0] = 1;
    for(int i=1; i<=rowIndex; ++i)
        res[i] = res[i-1]*(rowIndex-i+1)/i;
    return res;
}

/*
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

 */

int singleNumberII(vector<int>& nums) {
    int X = 0, Y = 0;
    for(int i=0; i<nums.size(); i++) {
        Y = ~X & (Y^nums[i]);
        X = ~Y & (X^nums[i]);
    }
    return Y;
}

/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

 */

int majorityElement(vector<int>& nums) {
    int count = 1, num = nums[0];
    for(int i=1; i<nums.size(); i++) {
        if(num != nums[i]) count--;
        else count ++;
        if(count == 0) {
            num = nums[i];
            count = 1;
        }
    }
    return num;
}

/*
 * Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

 */

int trailingZeroes(int n) {
    int res = 0;
    while(n) {
        res += n/5;
        n = n/5;
    }
    return res;
}

/*
 * Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

 */

static bool compare(const string& s1, const string& s2)
{
    string ab = s1 + s2;
    string ba = s2 + s1;
    return ab > ba;
}

string largestNumberCombine(vector<int>& nums) {
    vector<string> vec;
    string s;
    for(int i=0; i<nums.size(); i++)
        vec.push_back(to_string(nums[i]));
    sort(vec.begin(), vec.end(), compare);
    if(vec[0] == "0") return "0";
    for(int i=0; i<vec.size(); i++)
        s += vec[i];
    return s;
}



void rotateArray(vector<int>& nums, int k) {
    k = k%nums.size();
    int count = 0;
    for(int i=0; count < nums.size(); i++) {
        int start = i, tmp = nums[i];
        do {
            start = (start + k) % nums.size();
            int tm = nums[start];
            nums[start] = tmp;
            tmp = tm;
            count++;
        } while(start != i);
    }
}

/*
 * Reverse bits of a given 32 bits unsigned integer.
 * Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
 so return 964176192 which its binary representation is 00111001011110000010100101000000.

 */

uint32_t reverseBits(uint32_t n) {
    n = (n>>16) | (n<<16);
    n = ((n&0xff00ff00)>>8) | ((n&0x00ff00ff)<<8);
    n = ((n&0xf0f0f0f0)>>4) | ((n&0x0f0f0f0f)<<4);
    n = ((n&0xcccccccc)>>2) | ((n&0x33333333)<<2);
    n = ((n&0xaaaaaaaa)>>1) | ((n&0x55555555)<<1);
    return n;
}

/*
 * Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

 */

int hammingWeight(uint32_t n) {
    int res = 0;
    while(n>0) {
        res++;
        n &= (n-1);
    }
    return res;
}

/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

 */

int rangeBitwiseAnd(int m, int n) {
    while(m<n) {
        n &= (n-1);
    }
    return n;
}

/*
 * Count the number of prime numbers less than a non-negative number, n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

 */
int countPrimes(int n) {
    if(n<=1) return 0;
    int count= 0;
    vector<bool> noPrime(n+1, 0);
    for(int i=2; i<=n; i++) {
        for(int j=i; (long)i*j<=n; j++) {
            noPrime[i*j] = 1;
        }
    }
    for(int i=2;i<n; i++) {
        count += noPrime[i]? 0:1;
    }
    return count;
}

/*
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

 */

vector<int> majorityElementII(vector<int>& nums) {
    if(nums.size()<=1) return nums;
    int p1=nums[0], c1=0, p2=nums[0], c2=0;
    for(int i=0; i<nums.size(); i++) {
        if(p1 == nums[i]) c1++;
        else {
            if(p2 == nums[i]) c2++;
            else{
                if(c2==0) {
                    p2 = nums[i];
                    c2 = 1;
                } else if(c1 == 0) {
                    p1 = nums[i];
                    c1 = 1;
                }else {
                    c1--;
                    c2--;
                }
            }
        }
    }
    int count1=0, count2=0;
    for(int i=0; i<nums.size(); i++) {
        if(p1 == nums[i]) count1++;
        else if(p2 == nums[i]) count2++;
    }
    vector<int> res;
    if(count1>nums.size()/3) res.push_back(p1);
    if(p1!=p2 && count2>nums.size()/3) res.push_back(p2);
    return res;
}