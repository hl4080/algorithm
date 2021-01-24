//
// Created by hl4080 on 2021/1/24.
//

#include "array.h"


/*
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例1
输入
复制
7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
返回值
复制
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