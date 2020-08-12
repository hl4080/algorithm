//
// Created by hl4080 on 2020/7/10.
//

#include "recursion.h"

/*
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

2 represents "abc", 3 represent "def", 4 represents "ghi", 5 represents "jkl", 6 represents "mno", 7 represents "pqrs"
8 represents "tuv", 9 represents "wxyz"

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

void findCombination(vector<string>& res, vector<string> m, string digits, int index, string str) {
    if(index == digits.size()) {
        res.push_back(str);
        return;
    }
    string s = m[digits[index]-'0'];
    for(int i=0; i<s.size(); ++i)
        findCombination(res, m, digits, index+1, str+s[i]);
    return;
}

vector<string> letterCombinations(string digits) {
    vector<string> m{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    if(digits.empty()) return result;
    findCombination(result, m, digits, 0, "");
    return result;
}

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

void parenthesisHelper(vector<string>& result, int left, int right, int n, string curStr) {
    if(left == n && right == n) {
        result.push_back(curStr);
        return;
    }
    if(left < right) return;
    if(left < n)  parenthesisHelper(result, left+1, right, n, curStr+"(");
    if(right < n)  parenthesisHelper(result, left, right+1, n, curStr+")");
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    parenthesisHelper(result, 0, 0, n, "");
    return result;
}

/*
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

void combinationHelp(vector<int>& candidates, vector<vector<int>>& res, vector<int>& single, int index, int sum, int target) {
    if(sum == target) {
        res.push_back(single);
        return;
    }
    for(int i=index; i<candidates.size(); ++i) {
        if(sum > target) break;
        single.push_back(candidates[i]);
        combinationHelp(candidates, res, single, i, sum+candidates[i], target);
        single.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> single;
    combinationHelp(candidates, res, single, 0, 0, target);
    return res;
}

/*
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
 */

void combination2Help(vector<int>& candidates, vector<vector<int>>& res, vector<int> piece, int index, int sum, int target) {
    if(sum == target) {
        res.push_back(piece);
        return;
    }
    for(int i=index; i<candidates.size(); ++i) {
        if(sum > target) break;
        if(i>index && candidates[i] == candidates[i-1]) continue;
        piece.push_back(candidates[i]);
        combination2Help(candidates, res, piece, i+1, sum + candidates[i], target);
        piece.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> piece;
    sort(candidates.begin(), candidates.end());
    combination2Help(candidates, res, piece, 0, 0, target);
    return res;
}

/*
 * Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

void permuteHelp(vector<int>& nums, vector<vector<int>>& res, int index) {
    if(index == nums.size()) {
        res.push_back(nums);
        return;
    }
    for(int i=index; i<nums.size(); ++i) {
        swap(nums[i], nums[index]);
        permuteHelp(nums, res, index+1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> integerPermute(vector<int>& nums) {
    vector<vector<int>> res;
    permuteHelp(nums, res, 0);
    return res;
}

/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

 */

void permuteHelp2(vector<int>& nums, vector<vector<int>>& res, vector<int>& piece, int index, vector<int>& visited) {
    if(index == nums.size()) {
        res.push_back(piece);
        return;
    }
    for(int i=0; i<nums.size(); ++i) {
        if(visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;
        piece.push_back(nums[i]);
        visited[i] = true;
        permuteHelp2(nums, res, piece, index+1, visited);
        visited[i] = false;
        piece.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> piece;
    vector<vector<int>> res;
    vector<int> visited(nums.size(), 0);
    permuteHelp2(nums, res, piece, 0, visited);
    return res;
}

/*
 * The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
 */

string getSpecialPermutation(int n, int k) {
    vector<int> nums;
    vector<int> fabs(n+1, 1);
    string res;
    for(int i=1; i<=n; ++i){
        nums.push_back(i);
        fabs[i] = i*fabs[i-1];
    }
    k--;
    for(int i=n-1; i>=0; --i) {
        int pos = 0;
        while(k>=fabs[i]) {
            pos++;
            k -= fabs[i];
        }
        res += to_string(nums[pos]);
        nums.erase(nums.begin()+pos);
    }
    return res;
}

/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

void combinationsHelp(vector<vector<int>>& res, vector<int>& single, int index, int n, int k) {
    if(single.size() == k) {
        res.push_back(single);
        return;
    }
    for(int i=index; i<n; ++i) {
        single.push_back(i+1);
        combinationsHelp(res, single, i+1, n, k);
        single.pop_back();
    }
}

vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> res;
    vector<int> single;
    if(!n || !k) return res;
    combinationsHelp(res, single, 0, n, k);
    return res;
}