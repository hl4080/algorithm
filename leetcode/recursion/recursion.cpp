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