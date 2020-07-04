//
// Created by hl4080 on 2020/6/20.
//

#include "hash.h"

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

        Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    for(int i=0; i<nums.size(); ++i) {
        if(m.count(nums[i]))
            return vector<int>{m[nums[i]], i};
        m[target - nums[i]] = i;    //首先判断，防止出现只有一个target的一半的数出现
    }
    return vector<int>{};
}