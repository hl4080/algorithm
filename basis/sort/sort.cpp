//
// Created by hl4080 on 2021/3/6.
//

#include "sort.h"

//direct inserting sort
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
