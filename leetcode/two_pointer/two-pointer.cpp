//
// Created by hl4080 on 2020/6/23.
//

#include "two-pointer.h"

/*
 * Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */

int digitSquare(int n) {
    int result = 0;
    while(n != 0) {
        result += (n%10)*(n%10);
        n /= 10;
    }
    return result;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = digitSquare(slow);
        fast = digitSquare(digitSquare(fast));
    } while(slow != fast);
    return slow == 1;
}

/*
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

int lengthOfLongestSubstring(string s) {
    set<char> subset;
    if(s.size() < 2) return s.size();
    int begin = 0, end = 1, len = 1;
    subset.insert(s[begin]);
    while(begin < s.size() && end<s.size()) {
        if(!subset.count(s[end])){
            len = max(len, end-begin+1);
            subset.insert(s[end++]);
        }
        else
            subset.erase(s[begin++]);
    }
    return len;
}

/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3) return result;
    sort(nums.begin(), nums.end());
    for(int p1=0; p1<nums.size(); ++p1) {
        if(p1 > 0 && nums[p1] == nums[p1 - 1]) continue;
        for(int p2=p1+1, p3=nums.size()-1; p2<p3;) {
            while(p2>p1+1 && p2<p3 && nums[p2] == nums[p2-1]) p2++;
            while(p3<nums.size()-1 && p2<p3 && nums[p3] == nums[p3+1]) p3--;
            if(p2 >= p3) break;
            if(nums[p2] + nums[p3] + nums[p1] == 0) {
                result.push_back(vector<int>{nums[p1], nums[p2], nums[p3]});
                p2++;
                p3--;
            }
            else if(nums[p2] + nums[p3] + nums[p1] > 0) p3--;
            else p2++;
        }
    }
    return result;
}