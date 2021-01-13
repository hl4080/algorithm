//
// Created by hl4080 on 2020/7/6.
//

#include "greedy.h"


/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.
 Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */


string intToRoman(int num) {
    //greedy strategy: substract from larger number to small in map
    vector<int> nums{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result;
    int i = 0;
    while(i < nums.size()) {
        if(num >= nums[i]) {
            result += roman[i];
            num -= nums[i];
        } else ++i;
    }
    return result;
}

/*
 *Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 */

bool jumpGame(vector<int>& nums) {
    int n = nums.size();
    int maxJump = 0;
    for(int i=0; i<n; ++i) {
        if(maxJump < i) return false;
        else if(maxJump >= n-1) return true;
        maxJump = max(maxJump, i+nums[i]);
    }
    return true;
}

 /*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

 */

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<int> net(gas.size(), 0);
    int totalGas = 0, totoalCost = 0;
    for(int i=gas.size()-1; i>=0; i--) {
        net[i] = i == gas.size()-1? gas[i]-cost[i]: net[i+1]+gas[i]-cost[i];
        totalGas += gas[i];
        totoalCost += cost[i];
    }
    if(totalGas < totoalCost) return -1;
    int maxIndex = 0, maxNet = INT_MIN;
    for(int i=net.size()-1; i>=0; i--) {
        if(maxNet < net[i]){
            maxIndex = i;
            maxNet = net[i];
        }
    }
    return maxIndex;
}

/*
 * Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

 */

bool eraseOverlapIntervalsCmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), eraseOverlapIntervalsCmp);
    int interval_num = 1;
    vector<int> first = intervals[0];
    for(int i=0; i<intervals.size(); i++) {
        if(intervals[i][0] >= first[1]) {
            interval_num++;
            first = intervals[i];
        }
    }
    return intervals.size()-interval_num;
}