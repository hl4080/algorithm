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

/*
 Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

int romanToInt(string s) {
    map<string, int> m{{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
    int result = 0;
    for(int i=0; i<s.size(); ++i) {
        if(i == s.size() - 1) result += m[s.substr(i, 1)];
        else {
            if(m[s.substr(i, 1)] < m[s.substr(i+1, 1)]) {
                result += m[s.substr(i, 2)];
                ++i;
            } else result += m[s.substr(i, 1)];
        }
    }
    return result;
}

/*
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 */

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> row(9, vector<int>(10, 0));
    vector<vector<int>> col(9, vector<int>(10, 0));
    vector<vector<int>> box(9, vector<int>(10, 0));
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            int cur = board[i][j] - '0';
            if(cur >= 1 && cur <= 9) {
                if(row[i][cur] || col[j][cur] || box[(i/3)*3+j/3][cur]) return false;
                else {
                    row[i][cur]++;
                    col[j][cur]++;
                    box[(i/3)*3+j/3][cur]++;
                }
            }
        }
    }
    return true;
}

/*
 * Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
 */

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    map<string, vector<string>> m;
    for(int i=0; i<strs.size(); ++i) {
        string s = "00000000000000000000000000";
        for(int j=0; j<strs[i].size(); ++j) s[strs[i][j]-'a']++;
        if(!m.count(s)) m[s] = vector<string>{};
        m[s].push_back(strs[i]);
    }
    for(auto it=m.begin(); it!=m.end(); ++it) {
        res.push_back(it->second);
    }
    return res;
}

/*
 * All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

 */

vector<string> findRepeatedDnaSequences(string s) {
    set<string> res;
    if(s.size() < 10) return vector<string>{};
    map<char, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    set<int> st;
    long val = 0;
    for(int i=0; i<=s.size()-10; i++) {
        if(i==0) {
            for(int j=0; j<10; j++) {
                val = val<<2;
                val += m[s[j]];
            }
        } else {
            val = val<<2;
            val += m[s[i+9]];
            val &= ~(3<<20);
        }
        if(st.count(val))
            res.insert(s.substr(i, 10));
        st.insert(val);
    }
    vector<string> repeated;
    repeated.assign(res.begin(), res.end());
    return repeated;
}

/*
 * Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true

 */

bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) return false;
    map<char, int> m1;
    map<char, int> m2;
    for(int i=0; i<s.size(); i++){
        if(!m1.count(s[i])) m1[s[i]] = i;
        if(!m2.count(t[i])) m2[t[i]] = i;
    }
    if(m1.size() != m2.size()) return false;
    for(int i=0; i<s.size(); i++)
        if(m1[s[i]] != m2[t[i]]) return false;
    return true;
}

/*
 * Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true

 */

bool containsDuplicate(vector<int>& nums) {
    map<int, bool> m;
    for(int i=0; i<nums.size(); i++) {
        if(m.count(nums[i])) return true;
        m[nums[i]] = true;
    }
    return false;
}