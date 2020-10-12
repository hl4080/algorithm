//
// Created by hl4080 on 2020/6/23.
//

#include "two-pointer.h"

/*
 * Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process:
 Starting with any positive integer, replace the number by the sum of the squares of its digits,
 and repeat the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

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
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.

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

/*
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
 */

int maxWaterArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, maxArea = 0;
    while(i <= j) {
        maxArea = max(maxArea, (j-i)*min(height[i], height[j]));
        if(height[i] < height[j]) i++;
        else j--;
    }
    return maxArea;
}

/*
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
 */

int threeSumClosest(vector<int>& nums, int target) {
    //idea same as three sum, sort and two pointer, extra result buffer
    sort(nums.begin(), nums.end());
    int minDiff = INT_MAX, len = nums.size(), result;
    for(int p1 = 0; p1<len; ++p1) {
        if(p1>0 && nums[p1] == nums[p1-1]) continue;
        for(int p2 = p1+1; p2<len; ++p2) {
            for(int p3 = len-1; p3>p2; --p3) {
                int diff = abs(nums[p1] + nums[p2] + nums[p3] - target);
                if(diff == 0) return target;
                if(diff < minDiff) {
                    minDiff = diff;
                    result = nums[p1] + nums[p2] + nums[p3];
                }
                if(nums[p1] + nums[p2] + nums[p3] < target) break;
            }
        }
    }
    return result;
}

/*
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
 */

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int p1 = 0, p2 = 1;
    while(p2 < nums.size()) {
        if(nums[p2] == nums[p1]){
            p2++;
            continue;
        }
        nums[++p1] = nums[p2];
    }
    return p1+1;
}

/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */

void nextPermutation(vector<int>& nums) {
    int p1 = nums.size()-1;
    int maxium = INT_MIN;
    while(p1>=0 && nums[p1]>= maxium) maxium = max(maxium, nums[p1--]);
    if(p1 < 0) {
        sort(nums.begin(), nums.end());
        return;
    }
    for(int p2 = p1; p2 < nums.size(); ++p2) {
        if(nums[p2] > nums[p1] && (p2 == nums.size()-1 || nums[p2+1] <= nums[p1])) {
            int tmp = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = tmp;
            sort(nums.begin() + p1 + 1, nums.end());
            break;
        }
    }
}

/*
 * The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1",
 "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11",
 so the answer is the concatenation of "12" and "11" which is "1211".
 */
string countString(string s) {
    string res;
    int i=0;
    while(i<s.size()) {
        int j = i+1;
        while(j<s.size() && s[j] == s[i]) j++;
        res += to_string(j-i)+s[i];
        i = j;
    }
    return res;
}

string countAndSay(int n) {
    if(n==1) return "1";
    return countString(countAndSay(n-1));
}

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if(intervals.empty()) return res;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); ++i) {
        if(intervals[i][0] <= res[res.size()-1][1] && intervals[i][1] > res[res.size()-1][1]) res[res.size()-1][1] = intervals[i][1];
        else if(intervals[i][0] > res[res.size()-1][1]) res.push_back(intervals[i]);
    }
    return res;
}

/*
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

 */

void sortColors(vector<int>& nums) {
    if(!nums.size()) return;
    int p0 = 0, cur = 0, p2 = nums.size()-1;
    while(cur<p2) {
        if(nums[cur] == 0) swap(nums[p0++], nums[cur++]);
        else if(nums[cur] == 2) swap(nums[p2--], nums[cur++]);
        else cur++;
    }
}

/*
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

 */

int removeDeplicatesII(vector<int>& nums) {
    if(nums.size() < 2) return nums.size();
    int p0 = 0, p1 = 0;
    while(p1 < nums.size()) {
        int pre = p1;
        while(p1 < nums.size() && nums[p1] == nums[pre]) p1++;
        if(p1 - pre < 2) nums[p0++] = nums[pre];
        else {
            nums[p0] = nums[pre];
            nums[p0+1] = nums[pre];
            p0 += 2;
        }
    }
    return p0;
}

/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 */

void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m+n;
    int p1 = m-1, p2 = n-1, p3 = len-1;
    while(p3>=0) {
        if(p2<0) return;
        if(p1 < 0 ||nums1[p1] <= nums2[p2]) nums1[p3--] = nums2[p2--];
        else nums1[p3--] = nums1[p1--];
    }
}

/*
 * Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

 */

string reverseWords(string s) {
    string res;
    for(int p2=s.size()-1; p2>=0; ) {
        while(p2>=0 && s[p2] == ' ') p2--;
        if(p2<0) break;
        int p1 = p2;
        while(p1 >= 0 && s[p1] != ' ') p1--;
        res += s.substr(p1+1, p2-p1);
        res += " ";
        p2 = p1;
    }
    return res.substr(0, res.size()-1);
}

/*
 * Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'.
 Each revision consists of digits and may contain leading zeros.
 Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order.
 Revisions are compared using their integer value ignoring any leading zeros.
 This means that revisions 1 and 001 are considered equal.
 If a version number does not specify a revision at an index, then treat the revision as 0.
 For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

 */
int getNextchunk(string s, int n, int& p) {
    if(p>=n) return 0;
    int pre_p = p;
    while(p<n && s[p] != '.') p++;
    int res = atoi(s.substr(pre_p, p-pre_p).c_str());
    p++;
    return res;
}

int compareVersion(string version1, string version2) {
    int p1 = 0, p2 = 0, n1 = version1.size(), n2 = version2.size();
    while(p1<n1 || p2<n2) {
        int num1 = getNextchunk(version1, n1, p1);
        int num2 = getNextchunk(version2, n2, p2);
        if(num1 > num2) return 1;
        else if(num1 < num2) return -1;
    }
    return 0;
}