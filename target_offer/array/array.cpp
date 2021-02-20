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

/*
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
示例1
输入

[4,5,1,6,2,7,3,8],4
返回值

[1,2,3,4]
 */

vector<int> LeasKtNumbers(vector<int> input, int k) {
    vector<int> res;
    if(k<=0 || k>input.size()) return res;
    priority_queue<int> q;
    for(int i=0; i<input.size(); i++) {
        if(i<k) q.push(input[i]);
        else{
            if(input[i] >= q.top()) continue;
            else{
                q.pop();
                q.push(input[i]);
            }
        }
    }
    while(!q.empty()) {
        res.push_back(q.top());
        q.pop();
    }
    sort(res.begin(), res.end());
    return res;
}

/*
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
示例1
输入

[3,32,321]
返回值

"321323"
 */

bool minStringNumberCmp(string a, string b) {
    return a+b < b+a;
}

string minStringNumber(vector<int> numbers) {
    vector<string> vec;
    string res;
    for(int i=0; i<numbers.size(); i++) vec.push_back(to_string(numbers[i]));
    sort(vec.begin(), vec.end(), minStringNumberCmp);
    for(string s: vec) res += s;
    return res;
}

/*
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
示例1
输入

7
返回值

8
 */

int UglyNumber(int index) {
    if(index <= 0) return 0;
    vector<int> res(index,1);
    int p2 = 0, p3 = 0, p5 = 0;
    for(int i=1; i<index; i++) {
        res[i] = min(2*res[p2], min(3*res[p3], 5*res[p5]));
        if(res[i] == 2*res[p2]) p2++;
        if(res[i] == 3*res[p3]) p3++;
        if(res[i] == 5*res[p5]) p5++;
    }
    return res[index-1];
}

/*
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

对于50%的数据,size≤10000
4

对于75%的数据,size≤100000
5

对于100\%100%的数据,size≤2∗100000
5

输入描述:
题目保证输入的数组中没有的相同的数字
示例1
输入

[1,2,3,4,5,6,7,0]
返回值

7
 */

void merge(vector<int>& data, int lo, int mid, int hi, int& res) {
    int i = lo, j = mid+1;
    vector<int> tmp;
    while(i<=mid && j<=hi) {
        if(data[i]<data[j]) tmp.push_back(data[i++]);
        else {
            res += (mid-i+1);
            tmp.push_back(data[j++]);
        }
    }
    while(i<=mid) tmp.push_back(data[i++]);
    while(j<=hi) tmp.push_back(data[j++]);
    for(int i=lo; i<=hi; i++) data[i] = tmp[i-lo];
}

void mergeSort(vector<int>& data, int lo, int hi, int& res) {
    if(lo >= hi) return;
    int mid = lo + (hi-lo)/2;
    mergeSort(data, lo, mid, res);
    mergeSort(data, mid+1, hi, res);
    merge(data, lo, mid, hi, res);
}

int InversePairs(vector<int> data) {
    int lo = 0, hi = data.size()-1, res = 0;
    mergeSort(data, lo, hi, res);
    return res;
}