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

/*
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

 */

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    for(int i=1; i<nums.size(); ++i)
        ans[i] = nums[i-1]*ans[i-1];
    int rVal = 1;
    for(int i=nums.size()-2; i>=0; i--) {
        ans[i] *= rVal*nums[i+1];
        rVal = rVal*nums[i+1];
    }
    return ans;
}

/*
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
             Since 2 has only one digit, return it.

 */

int addDigits(int num) {
    return (num-1)%9 + 1;
}

/*
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
 * Find the two elements that appear only once. You can return the answer in any order.

Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

 */

vector<int> singleNumberIII(vector<int>& nums) {
    int mask = 0;
    for(int i=0; i<nums.size(); i++) mask ^= nums[i];
    int shift = mask&(-mask);
    int x = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i]&shift) x ^= nums[i];
    }
    return vector<int> {x, mask^x};
}

/*
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

 */
int missingNumber(vector<int>& nums) {
    int res = 0;
    for(int i=0; i<nums.size(); i++) {
        res ^= nums[i];
        res ^= i;
    }
    res ^= nums.size();
    return res;
}

/*
 * Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
             received 3, 0, 6, 1, 5 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.

 */

int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> papers(n+1, 0);
    for(int i=0; i<n; i++) papers[min(n, citations[i])]++;
    int h=n;
    for(int i=papers[n]; i<h; i+=papers[h]) h--;
    return h;
}

/*
 * Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had
             received 0, 1, 3, 5, 6 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.
 */

int hIndexII(vector<int>& citations) {
    int n = citations.size();
    int h = 0;
    for(int i=n-1; i>=0 && citations[i]>h; i--) h++;
    return h;
}

/*
 * You are playing the following Nim Game with your friend:

Initially, there is a heap of stones on the table.
You and your friend will alternate taking turns, and you go first.
On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
The one who removes the last stone is the winner.
Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.

Example 1:

Input: n = 4
Output: false
Explanation: These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.

 */

bool canWinNim(int n) {
    return !(n%4 == 0);
}

/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
        such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
*/

bool increasingTriplet(vector<int>& nums) {
    if(nums.size() < 3) return false;
    int small = INT_MAX, mid = INT_MAX;
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i] <= small) small = nums[i];
        else if(nums[i] <= mid) mid = nums[i];
        else return true;
    }
    return false;
}

/*
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

 */

int integerBreak(int n) {
    int times = n/3;
    int reminder = n%3;
    if(reminder == 0) return times == 1? 2: pow(3, times);
    else if(reminder == 1) return !times? 1: pow(3, times-1)*4;
    return !times? 1: pow(3,times)*reminder;
}

/*
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:

Input: 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100,
             excluding 11,22,33,44,55,66,77,88,99

 */

int countNumbersWithUniqueDigits(int n) {
    if(n==0) return 1;
    int res = 9;
    for(int i=1; i<n; i++) res *= (10-i);
    return res+countNumbersWithUniqueDigits(n-1);
}

/*
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true

 */

bool isPerfectSquare(int num) {
    int x0 = num;
    long y0 = (long)x0*x0 - num;
    while(y0 > 0) {
        y0 = (long)x0*x0 - num;
        x0 = ((long)x0 + num/x0)/2;
    }
    return y0 == 0;
}

/*
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1

 */

int getSum(int a, int b) {
    return b == 0? a: getSum(a^b, (unsigned int)(a&b)<<1);
}

/*
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
Example 1:

Input: a = 2, b = [3]
Output: 8

 */
int powerCertain(int a, int n) {
    return n==0? 1: n==1? a: (a*(long)(powerCertain(a,n-1)%1337))%1337;
}

int superPow(int a, vector<int>& b) {
    if(b.size() == 1) return powerCertain(a, b[0]);
    int c = b[b.size()-1];
    b.pop_back();
    return ((long)powerCertain(a,c)*powerCertain(superPow(a, b), 10))%1337;
}

/*
 * There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6

 */

int lastRemaining(int n) {
    return n==1? 1: 2*(n/2+1-lastRemaining(n/2));
}

/*
 * Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1

 */

int integerReplacement(int n) {
    if(n == INT_MAX) return 32;
    int res = 0;
    while(n != 1) {
        if(n%2 == 0) n = n/2;
        else if((n&3) == 3 && n!=3) n += 1;
        else n -= 1;
        res++;
    }
    return res;
}

/*
 * Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

 */

int pickRandomly(vector<int>& nums, int target) {
    int res;
    int index = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == target) {
            index++;
            if(rand()%index == 0) res = i;
        }
    }
    return res;
}

/*
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
 */

int findNthDigit(int n) {
    n -= 1;
    int res;
    for(int i=1; i<11; i++) {
        long first = pow(10, i-1);
        if(n<first*9*i){
            res = to_string(n/i+first)[n%i]-'0';
            return res;
        }
        n -= first*9*i;
    }
    return res;
}

/*
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

 */

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        int index = abs(nums[i])-1;
        int val = nums[index];
        if(val < 0)
            res.push_back(abs(nums[i]));
        nums[index] = -nums[index];
    }
    return res;
}

/*
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

 */

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        int val = nums[index];
        if(val < 0) nums[index] = abs(nums[index]);
        nums[index] = -nums[index];
    }
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] > 0) res.push_back(i+1);
    }
    return res;
}

/*
 * Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

 */

int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int i=0; i<nums.size(); i++) {
        res += nums[i]-nums[0];
    }
    return res;
}