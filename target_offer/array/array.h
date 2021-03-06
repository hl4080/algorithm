//
// Created by hl4080 on 2021/1/24.
//

#ifndef ALOGRITHM_ARRAY_H
#define ALOGRITHM_ARRAY_H


#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

bool Find(int target, vector<vector<int> > array);
void reorderArray(vector<int> &array);
vector<int> printMatrix(vector<vector<int> > matrix);
int MoreThanHalfNum(vector<int> numbers);
vector<int> LeasKtNumbers(vector<int> input, int k);
string minStringNumber(vector<int> numbers);
int UglyNumber(int index);
int InversePairs(vector<int> data);
int GetNumberOfK(vector<int> data ,int k);
vector<vector<int>> FindContinuousSequence(int sum);
vector<int> FindNumbersWithSum(vector<int> array,int sum);
bool IsContinuous( vector<int> numbers);
int duplicate(vector<int>& numbers);
vector<int> multiplyArray(const vector<int>& A);
vector<int> maxInWindows(const vector<int>& num, unsigned int size);
int movingCount(int threshold, int rows, int cols);

#endif //ALOGRITHM_ARRAY_H
