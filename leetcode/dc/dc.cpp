//
// Created by hl4080 on 2020/6/27.
//

#include "dc.h"

/*
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */

int findKthNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    int pivot1 = 0, pivot2 = 0;
    while(1) {
        if(pivot1 == m) return nums2[pivot2+k-1];
        if(pivot2 == n) return nums1[pivot1+k-1];
        if(k == 1) return min(nums1[pivot1], nums2[pivot2]);
        int mid = k/2;
        int newPivot1 = min(pivot1+mid, m) - 1;
        int newPivot2 = min(pivot2+mid, n) - 1;
        if(nums1[newPivot1] <= nums2[newPivot2]) {
            k -= (newPivot1 - pivot1 + 1);
            pivot1 = newPivot1 + 1;
        } else {
            k -= (newPivot2 - pivot2 + 1);
            pivot2 = newPivot2 + 1;
        }
    }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //equal to find the K(m+n/2) smallest value in two sorted arrays
    int m = nums1.size(), n = nums2.size();
    int k = (m+n)/2;    //nums[k] or (nums[k-1]+nums[k])/2
    if((m+n)%2) return findKthNumber(nums1, nums2, k+1);
    else return (findKthNumber(nums1, nums2, k) + findKthNumber(nums1, nums2, k+1)) / 2.0;
}

/*
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
 */
#include <iostream>
string longestCommonPrefix(vector<string>& strs) {
    //binary search with the shortest str
    //in the comment area, a more clever idea is to sort and compare the beginning and end string, time complexity is determined by sort operation
    if(strs.empty()) return "";
    int m = strs.size(), minLen = INT_MAX;
    for(int i=0; i<m; ++i)
        minLen = min(minLen, (int)strs[i].size());
    int back = minLen, front = 0;
    while(front < back) {
        int mid = front + (back - front + 1) / 2;
        int i = 0;
        for(; i<m; ++i)
            if(strs[0].substr(0, mid) != strs[i].substr(0, mid)) break;
        if(i == m) front = mid;
        else back = mid-1;
    }
    return strs[0].substr(0, front);
}