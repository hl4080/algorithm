//
// Created by hl4080 on 2020/6/22.
//

#ifndef MATH_H
#define MATH_H

#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int singleNumber(vector<int>&);
string zigzagConvert(string s, int numRows);
int reverseInteger(int x);
bool isPalindrome(int x);
int uniquePaths(int m, int n);
int sqrtx(int x);
void setZeros(vector<vector<int>>& matrix);
vector<vector<int>> generatePascalTriangle(int numRows);
vector<int> getRowPacasalTriangle(int rowIndex);
int singleNumberII(vector<int>& nums);
int majorityElement(vector<int>& nums);
int trailingZeroes(int n);
string largestNumberCombine(vector<int>& nums);
void rotateArray(vector<int>& nums, int k);
uint32_t reverseBits(uint32_t n);
int hammingWeight(uint32_t n);
int rangeBitwiseAnd(int m, int n);
int countPrimes(int n);
vector<int> majorityElementII(vector<int>& nums);
vector<int> productExceptSelf(vector<int>& nums);
int addDigits(int num);
vector<int> singleNumberIII(vector<int>& nums);

#endif //MATH_H
