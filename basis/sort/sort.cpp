//
// Created by hl4080 on 2021/3/6.
//

#include "sort.h"

//direct inserting sort
//time complexity O(n2), space complexity O(1), stable sorting
void insertNum(vector<int>& nums, int pos, int end, int num) {
    for(int i=end; i>=pos; i--) nums[i+1] = nums[i];
    nums[pos] = num;
}
void directInsertSort(vector<int>& nums) {
    int len = nums.size();
    for(int i=0; i<len; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] < nums[j]) {
                insertNum(nums, j, i-1, nums[i]);
                break;
            }
        }
    }
}

//select sort
//time complexity O(n2), space complexity O(1), unstable sort
void selectSort(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        int pos = i;
        for(int j=i; j<nums.size(); j++) pos = nums[pos]<nums[j]? pos: j;
        swap(nums[i], nums[pos]);
    }
}

//bubble sort
//time complexity O(n2), space complexity O(1), stable sort
void bubble_sort(vector<int>& nums) {
    for(int i=0;i<nums.size(); i++) {
        for(int j=nums.size()-1; j>i; j--) {
            if(nums[j] < nums[i]) swap(nums[i], nums[j]);
        }
    }
}

//hill sort
//time complexity worst O(n2) avg O(nlogn2), space compexity O(1), unstable sort
void hill_sort(vector<int>& nums) {
    for(int interval = nums.size()/2; interval>0; interval = interval/2) {
        for(int i=interval; i<nums.size(); i++) {
            int j=i;
            while(j-interval>=0 && nums[j-interval] > nums[j]) {
                swap(nums[j-interval], nums[j]);
                j = j-interval;
            }
        }
    }
}

//quick sort
int partitions(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left+1, r = right;
    while(l<r) {
        while(l<r && nums[l] < pivot) l++;
        while(r>l && nums[r] > pivot) r--;
        swap(nums[l], nums[r]);
    }
    swap(nums[left], nums[l-1]);
    return l-1;
}
void quickSortHelp(vector<int>& nums, int left, int right) {
    if(left < right) {
        int mid = partitions(nums, left, right);
        quickSortHelp(nums, left, mid-1);
        quickSortHelp(nums, mid+1, right);
    }
}
void quickSort(vector<int>& nums) {
    quickSortHelp(nums, 0, nums.size()-1);
}

//merge sort

void merge1(vector<int>& nums, int l1, int r1, int l2, int r2) {
    vector<int> arr;
    int p1 = l1, p2 = l2;
    while(p1<=r1 && p2<=r2) {
        if(nums[p1]>nums[p2]) arr.push_back(nums[p2++]);
        else arr.push_back(nums[p1++]);
    }
    while(p1<=r1) arr.push_back(nums[p1++]);
    while(p2<=r2) arr.push_back(nums[p2++]);
    for(int i=l1; i<=r2; i++) nums[i] = arr[i-l1];
}

void mergeSortHelp(vector<int>& nums, int l, int r) {
    if(l>=r) return;
    int mid = l+(r-l)/2;
    mergeSortHelp(nums, l, mid);
    mergeSortHelp(nums, mid+1, r);
    merge1(nums, l, mid, mid+1, r);
}

void mergeSort(vector<int>& nums) {
    mergeSortHelp(nums, 0, nums.size()-1);
}

//heap sort
void adjustHeap(vector<int>& nums, int i, int len) {
    int tmp = nums[i];
    for(int k=2*i+1; k<len; k=2*k+1) {
        if(k+1<len && nums[k+1] > nums[k]) k++;
        if(nums[k] > nums[i]) {
            swap(nums[i], nums[k]);
            i = k;
        }else break;
    }
}
void heapSort(vector<int>& nums) {
    int len = nums.size();
    for(int i=len/2; i>=0; i--)
        adjustHeap(nums, i, len);
    for(int i=len-1; i>0; i--) {
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i);
    }
}