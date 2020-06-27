//
// Created by hl4080 on 2020/6/27.
//

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

#include "dc.h"
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