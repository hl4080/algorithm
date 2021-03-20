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