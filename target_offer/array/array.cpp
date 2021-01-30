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