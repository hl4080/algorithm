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

/*
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

void subsetsHelp(vector<vector<int>>& res, vector<int>& nums, vector<int> single, int index) {
    res.push_back(single);
    for(int i=index; i<nums.size(); ++i) {
        single.push_back(nums[i]);
        subsetsHelp(res, nums, single, i+1);
        single.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> single;
    subsetsHelp(res, nums, single, 0);
    return res;
}

/*
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */

bool wordExistHelp(vector<vector<char>>& board, vector<vector<int>>& directions, vector<vector<bool>>& visited, int i, int j, int index, string word) {
    if(index == word.size()) return true;
    for(int d=0; d<directions.size(); ++d) {
        int i1 = i + directions[d][0];
        int j1 = j + directions[d][1];
        if(i1>=0 && i1<board.size() && j1>=0 && j1<board[0].size() && board[i1][j1] == word[index]) {
            if(visited[i1][j1])
                continue;
            visited[i1][j1] = true;
            if(wordExistHelp(board, directions, visited, i1, j1, index+1, word))
                return true;
            visited[i1][j1] = false;
        }
    }
    return false;
}

bool wordExistBoard(vector<vector<char>>& board, string word) {
    if(board.empty() || word.empty()) return false;
    vector<vector<int>> directions{{0,1}, {0, -1}, {1, 0}, {-1,0}};
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[0].size(); ++j) {
            if(word[0] == board[i][j]) {
                visited[i][j] = true;
                if(wordExistHelp(board, directions, visited, i, j, 1, word))
                    return true;
                visited[i][j] = false;
            }
        }
    }
    return false;
}

/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].
 */
void grayCodeHelp(vector<int>& res, int n, int& val) {
    res.push_back(val);
    for(int i=1; i<=n; ++i) {
        val ^= (1<<(i-1));
        grayCodeHelp(res, i-1, val);
    }
}

vector<int> grayCode(int n) {
    vector<int> res;
    int val = 0;
    grayCodeHelp(res, n, val);
    return res;
}

/*
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */
void subsetsWithDupHelp(vector<vector<int>>& res, vector<int>& nums, vector<int>& piece, int index) {
    res.push_back(piece);
    for(int i=index; i<nums.size(); ++i) {
        if(i>index && nums[i] == nums[i-1]) continue;
        piece.push_back(nums[i]);
        subsetsWithDupHelp(res, nums, piece, i+1);
        piece.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.empty()) return res;
    sort(nums.begin(), nums.end());
    vector<int> piece;
    subsetsWithDupHelp(res, nums, piece, 0);
    return res;
}

/*
 * Given a string s containing only digits. Return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single points and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 */
void restoreIpAddressHelp(vector<string>& res, vector<int>& piece, string s, int segId, int index) {
    if(segId == 4 && index == s.size()) {
        string ip;
        for(int i=0; i<piece.size(); ++i)
            ip += i==piece.size()-1? to_string(piece[i]): to_string(piece[i])+'.';
        res.push_back(ip);
        return;
    }
    if(index == s.size() || segId == 4) return;
    if(s[index] == '0') {
        piece[segId] = 0;
        restoreIpAddressHelp(res, piece, s, segId+1, index+1);
    }
    int addr = 0;
    for(int i=index; i<s.size(); ++i) {
        addr = addr*10 + s[i]-'0';
        if(addr > 0 && addr <= 255) {
            piece[segId] = addr;
            restoreIpAddressHelp(res, piece, s, segId+1, i+1);
        } else break;
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<int> piece(4,0);
    restoreIpAddressHelp(res, piece, s, 0, 0);
    return res;
}

/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

 */

int minPathTriangle(vector<vector<int>>& triangle) {
    if(triangle.empty()) return 0;
    vector<int> dp(triangle.size(),0);
    for(int i=0; i<triangle.size(); i++) {
        vector<int> tmp = dp;
        for(int j=0; j<triangle[i].size(); j++) {
            if(j==0) dp[j] = tmp[j] + triangle[i][j];
            else if(j==triangle[i].size()-1) dp[j] = tmp[j-1]+triangle[i][j];
            else dp[j] = min(tmp[j]+triangle[i][j], tmp[j-1]+triangle[i][j]);
        }
    }
    int minVal = INT_MAX;
    for(int i=0; i<dp.size(); i++)
        minVal = min(minVal, dp[i]);
    return minVal;
}

/*
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

 */
void surroundRegionsHelp(vector<vector<char>>& board, int i, int j) {
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O') return;
    board[i][j] = 'A';
    surroundRegionsHelp(board, i-1, j);
    surroundRegionsHelp(board, i+1, j);
    surroundRegionsHelp(board, i, j-1);
    surroundRegionsHelp(board, i, j+1);
}

void surroundRegions(vector<vector<char>>& board) {
    if(board.empty()) return;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if((i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1) && board[i][j] == 'O')
                surroundRegionsHelp(board, i, j);
        }
    }
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == 'A')
                board[i][j] = 'O';
        }
    }
}

/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

 */
void palindromePartitionHelp(string s, vector<vector<bool>>& dp, vector<vector<string>>& res, vector<string> piece, int i, int len) {
    if(i==len) {
        res.push_back(piece);
        return;
    }
    for(int k=i; k<len; k++) {
        if(!dp[i][k]) continue;
        piece.push_back(s.substr(i, k-i+1));
        palindromePartitionHelp(s, dp, res, piece, k+1, len);
        piece.pop_back();
    }
}
vector<vector<string>> palindromePartition(string s) {
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for(int j=0; j<len; j++) {
        for(int i=0; i<=j; i++) {
            if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])) dp[i][j] = true;
        }
    }
    vector<vector<string>> res;
    vector<string> piece;
    palindromePartitionHelp(s, dp, res, piece, 0, len);
    return res;
}