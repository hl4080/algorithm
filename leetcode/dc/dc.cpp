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

/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
 */

int searchInsertPosition(vector<int>& nums, int target) {
    int front = 0, back = nums.size() - 1;
    while(front < back) {
        int mid = front + (back - front)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) {
            if(mid == back || nums[mid+1] > target) return mid+1;
            front = mid + 1;
        } else {
            if(mid == front || nums[mid-1] < target) return mid;
            back = mid - 1;
        }
    }
    return front;
}

/*
 * You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */

void rotateImage(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<(n+1)/2; ++i) {
        for(int j=0; j<n/2; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-i-1] = tmp;
        }
    }
}

/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int begin = 0, end = m*n-1;
    while(begin <= end) {
        int mid = begin + (end - begin)/2;
        int midRow = mid/n, midCol = mid%n;
        if(matrix[midRow][midCol] == target) return true;
        else if(matrix[midRow][midCol] > target) end = mid-1;
        else begin = mid+1;
    }
    return false;
}

/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 */

bool searchRotatedArrayII(vector<int>& nums, int target) {
    int front = 0, back = nums.size()-1;
    while(front<=back) {
        int mid = front + (back-front)/2;
        if(nums[mid] == target) return true;
        if(nums[front]==nums[mid]) front++;
        else if(nums[front] < nums[mid]) {
            if(target >= nums[front] && target < nums[mid]) back = mid-1;
            else front = mid + 1;
        }
        else {
            if(target  > nums[mid] && target <= nums[back]) front = mid+1;
            else back = mid-1;
        }
    }
    return false;
}

/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1

 */

int findMinSortedArray(vector<int>& nums) {
    int front = 0, back = nums.size()-1;
    while(front<=back) {
        if(nums[front] < nums[back]) return nums[front];
        int mid = front + (back-front)/2;
        if(nums[front] < nums[mid])  front = mid;
        else if(nums[front] == nums[mid]) return front != nums.size()-1? nums[front]>nums[front+1]? nums[front+1]: nums[front]: nums[front];
        else back = mid;
    }
    return nums[front];
}

/*
 * A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

 */

int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while(l<r) {
        int mid = l + (r-l)/2;
        if(nums[mid]>nums[mid+1]) r = mid;
        else l = mid+1;
    }
    return l;
}