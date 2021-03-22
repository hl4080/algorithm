//
// Created by hl4080 on 2021/3/20.
//

#include "search.h"

//sequential search
//time complexity O(n), space complexity O(1), search condition: order or disorder
int seqSearch(vector<int>& nums, int target) {
    for(int i=0; i<nums.size(); i++)
        if(nums[i] == target) return i;
    return -1;
}

//binary search
//time complexity O(logn), space complexity O(1), search condition: order
int binarySearchIter(vector<int>& nums, int target) {
    int begin = 0, end = nums.size()-1;
    while(begin <= end) {
        int mid = begin + (end-begin)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) begin = mid + 1;
        else end = mid-1;
    }
    return -1;
}

int binarySearchRecuriveHelp(vector<int>& nums, int target, int left, int right) {
    if(left > right || target < nums[left] || target > nums[right]) return -1;
    int mid = left + (right-left)/2;
    if(nums[mid] == target) return mid;
    else if(target < nums[mid]) return binarySearchRecuriveHelp(nums, target, left, mid-1);
    else return binarySearchRecuriveHelp(nums, target, mid+1, right);
}

int binarySearchRecurive(vector<int>& nums, int target) {
    return binarySearchRecuriveHelp(nums, target, 0, nums.size()-1);
}

//differiential sort
//time complexity: worst O(n), avg O(logn), worst O(loglogn), space complexity O(1), search condition: order
int differentialSort(vector<int>& nums, int target) {
    int begin = 0, end = nums.size()-1;
    while(begin <= end) {
        int mid = begin + (target-nums[begin])*(end-begin)/(nums[end]-nums[begin]);
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) end = mid - 1;
        else begin = mid + 1;
    }
    return -1;
}