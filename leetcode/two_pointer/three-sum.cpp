//
// Created by hl4080 on 2020/6/24.
//

/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

#include "two-pointer.h"

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() < 3) return result;
    sort(nums.begin(), nums.end());
    for(int p1=0; p1<nums.size(); ++p1) {
        if(p1 > 0 && nums[p1] == nums[p1 - 1]) continue;
        for(int p2=p1+1, p3=nums.size()-1; p2<p3;) {
            while(p2>p1+1 && p2<p3 && nums[p2] == nums[p2-1]) p2++;
            while(p3<nums.size()-1 && p2<p3 && nums[p3] == nums[p3+1]) p3--;
            if(p2 >= p3) break;
            if(nums[p2] + nums[p3] + nums[p1] == 0) {
                result.push_back(vector<int>{nums[p1], nums[p2], nums[p3]});
                p2++;
                p3--;
            }
            else if(nums[p2] + nums[p3] + nums[p1] > 0) p3--;
            else p2++;
        }
    }
    return result;
}