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

/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */

int searchInRotatedArray(vector<int>& nums, int target) {
    int front = 0, back = nums.size() - 1;
    while(front <= back) {
        int mid = front + (back - front)/2;
        if(nums[mid] == target) return mid;
        if(nums[front] <= nums[mid]) {
            if(nums[front] <= target && nums[mid] >= target) back = mid-1;
            else front = mid+1;
        } else {
            if(nums[mid] <= target && nums[back] >= target) front = mid+1;
            else back = mid-1;
        }
    }
    return -1;
}

/*
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */

int searchFrontElement(vector<int>& nums, int i, int j, int target) {
    int front =i, back = j;
    while(front<=back) {
        int mid = front + (back-front)/2;
        if(nums[mid] == target && (mid == i || nums[mid-1] != target)) return mid;
        if(nums[mid] == target) return searchFrontElement(nums, i, mid-1, target);
        else if(nums[mid] < target) return searchFrontElement(nums, mid+1, j, target);
    }
    return -1;
}

int searchBackElement(vector<int>& nums, int i, int j, int target) {
    int front = i, back = j;
    while(front<=back) {
        int mid = front + (back-front)/2;
        if(nums[mid] == target && (mid == j || nums[mid+1] != target)) return mid;
        if(nums[mid] == target) return searchBackElement(nums, mid+1, j, target);
        else if(nums[mid] > target) return searchBackElement(nums, i, mid-1, target);
    }
    return -1;
}

vector<int> searchElementPositions(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    int front =0, back = nums.size()-1;
    while(front<=back) {
        int mid = front + (back-front)/2;
        if(nums[mid] == target) {
            res[0] = searchFrontElement(nums, front, mid, target);
            res[1] = searchBackElement(nums, mid, back, target);
            break;
        } else if(nums[mid] < target) front = mid+1;
        else back = mid-1;
    }
    return res;
}