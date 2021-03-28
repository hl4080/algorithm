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

//fabonacci search
//time complexity O(logn), space complexity O(1), search condition: order
int fabonacciSearch(vector<int>& nums, int target) {
    vector<int> fab(20, 1);
    int n = nums.size();
    for(int i=2; i<20; i++) fab[i] = fab[i-1] + fab[i-2];
    int k = 0;
    while(target > fab[k]-1) k++;
    for(int i=n; i<fab[k]-1; i++) nums.push_back(nums[n-1]);
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + fab[k-1]-1;
        if(nums[mid] < target) {
            low = mid + 1;
            k--;
        } else if(nums[mid] > target) {
            high = mid - 1;
            k -= 2;
        } else {
            if(mid < high) return mid;
            else return high;
        }
    }
    return -1;
}

//hash search
//time complexity O(1), space complexity O(n), search condition: order or disorder
int hashSearch(vector<int>& nums, int target) {
    vector<vector<pair<int, int>>> hashtable(5, vector<pair<int, int>>());
    int hashsz = hashtable.size();
    for(int i=0; i<nums.size(); i++)
        hashtable[nums[i]%hashsz].push_back(make_pair(i, nums[i]));
    vector<pair<int, int>> table = hashtable[target%hashsz];
    for(int i=0; i<table.size(); i++) {
        if(target == table[i].second) return table[i].first;
    }
    return -1;
}

//binary tree search，树查找包括二叉搜索树、红黑树、2-3树、B树和B+树
//time complexity O(logn), space complexity O(n), search condition: order or disorder
BinarySearchNode* BinaryTreeInsert(BinarySearchNode* root, int index, int val) {
    if(!root) {
        return new BinarySearchNode(index, val);
    }
    if(root->val < val) {
        if(root->right) return BinaryTreeInsert(root->right, index, val);
        else {
            root->right = new BinarySearchNode(index, val);
            return root->right;
        }
    } else {
        if(root->left) return BinaryTreeInsert(root->left, index, val);
        else {
            root->left = new BinarySearchNode(index, val);
            return root->left;
        }
    }
}

int binarySearch(BinarySearchNode* root, int target) {
    if(!root) return -1;
    if(root->val == target) return root->index;
    int l = binarySearch(root->left, target);
    int r = binarySearch(root->right, target);
    if(l!=-1) return l;
    else if(r!=-1) return r;
    return -1;
}

int binaryTreeSearch(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    BinarySearchNode* root = new BinarySearchNode(0, nums[0]);
    for(int i=1; i<nums.size(); i++) {
        BinaryTreeInsert(root, i, nums[i]);
    }
    return binarySearch(root, target);
}

//batch search
//time complexity O(loga)+O(b), space complexity O(n), search condition: order or disorder
#include <iostream>
int batchSearch(vector<int>& nums, int target) {
    int batchNum = 3;
    int numsMax = INT_MIN, numsMin = INT_MAX;
    for(int i=0; i<nums.size(); i++) {
        numsMax = max(numsMax, nums[i]);
        numsMin = min(numsMin, nums[i]);
    }
    int batchRange = (numsMax-numsMin)/batchNum+1;
    vector<vector<pair<int, int>>> batches(3, vector<pair<int, int>>());
    vector<int> batchMax;
    for(int i=1; i<=batchNum; i++) batchMax.push_back(numsMin+i*batchRange);
    for(int i=0; i<nums.size(); i++) {
        batches[(nums[i]-numsMin)/batchRange].push_back(make_pair(i, nums[i]));
    }
    int begin = 0, end = batchMax.size()-1;
    int index;
    while(begin<=end) {
        int mid = begin + (end-begin)/2;
        if(mid == 0 && target < batchMax[mid]) {
            index = mid;
            break;
        }
        if(target>=batchMax[mid-1] && target<batchMax[mid]) {
            index = mid;
            break;
        } else if(target>=batchMax[mid]) begin = mid+1;
        else if(target<batchMax[mid-1]) end = mid-1;
    }
    //cout<<batchMax[1]<<endl;
    for(int i=0; i<batches[index].size(); i++) {
        if(batches[index][i].second == target) return batches[index][i].first;
    }
    return -1;
}
