//
// Created by hl4080 on 2021/1/28.
//

#include "dc.h"

/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
示例1
输入
复制
[3,4,5,1,2]
返回值
复制
1
 */

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty()) return 0;
    int begin = 0, end = rotateArray.size()-1;
    while(begin < end) {
        if(rotateArray[begin] < rotateArray[end]) return rotateArray[begin];
        int mid = begin + (end-begin)/2;
        if(rotateArray[mid] > rotateArray[end]) begin = mid+1;
        else if(rotateArray[mid] < rotateArray[end]) end = mid;
        else end--;
    }
    return rotateArray[begin];
}

/*
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 */

void StreamMedian::Insert(int num) {
        if(cnt%2 == 0) {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        cnt++;
    }

double StreamMedian::GetMedian() {
        return cnt%2? min_heap.top(): (double)(min_heap.top()+max_heap.top())/2;
    }