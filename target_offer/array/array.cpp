//
// Created by hl4080 on 2021/1/24.
//

#include "array.h"


/*
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例1
输入

7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
返回值

true
 */

bool Find(int target, vector<vector<int> > array) {
    if(array.empty()) return false;
    int m = array.size(), n = array[0].size();
    int p1 = m-1, p2 = 0;
    while(p1>=0 && p2<n) {
        if(array[p1][p2] == target) return true;
        else if(array[p1][p2] < target) p2++;
        else p1--;
    }
    return false;
}

/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变
 */

void reorderArray(vector<int> &array) {
    int odd = 0, even = 0;
    while(odd < array.size()) {
        while(even < array.size() && array[even]%2) even++;
        odd = even+1;
        while(odd < array.size() && array[odd]%2 == 0) odd++;
        if(odd == array.size()) return;
        int tmp = array[odd];
        for(int pos=odd-1; pos>=even; pos--) {
            array[pos+1] = array[pos];
        }
        array[even] = tmp;
    }
}

/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
示例1
输入

[[1,2],[3,4]]
返回值

[1,2,4,3]
 */

void printMatrixHelp(vector<vector<int> >& matrix, vector<int>& res, int lx, int ly, int rx, int ry) {
    for(int i=ly; i<=ry; i++) res.push_back(matrix[lx][i]);
    for(int i=lx+1; i<=rx; i++) res.push_back(matrix[i][ry]);
    int h = rx-lx+1;
    if(h>1) {
        for(int i=ry-1; i>=ly; i--) res.push_back(matrix[rx][i]);
    }
    int w = ry- ly+1;
    if(w > 1) {
        for(int i=rx-1; i>=lx+1; i--) res.push_back(matrix[i][ly]);
    }
}

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> res;
    if(matrix.empty()) return res;
    int m = matrix.size(), n = matrix[0].size();
    int lx = 0, ly = 0;
    int rx = m-1, ry = n-1;
    while(lx<=rx && ly <= ry) printMatrixHelp(matrix, res, lx++, ly++, rx--, ry--);
    return res;
}

/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
示例1
输入

[1,2,3,2,2,2,5,4,2]
返回值

2
 */

int MoreThanHalfNum(vector<int> numbers) {
    if(numbers.empty()) return 0;
    int count = 1;
    int val = numbers[0];
    for(int i=1; i<numbers.size(); i++) {
        if(val != numbers[i]) count--;
        else count++;
        if(!count) {
            count = 1;
            val = numbers[i];
        }
    }
    count = 0;
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i] == val) count++;
    }
    return count>numbers.size()/2? val: 0;
}