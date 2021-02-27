//
// Created by hl4080 on 2021/1/28.
//

#include "dp.h"

/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n≤39

示例1
输入
复制
4
返回值
复制
3
 */

int Fibonacci(int n) {
    if(!n) return 0;
    int t0 = 0, t1 = 1;
    for(int i=2; i<=n; i++) {
        int tmp = t1;
        t1 += t0;
        t0 = tmp;
    }
    return t1;
}

/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
示例1
输入

1
返回值

1
示例2
输入

4
返回值

5
 */

int jumpFloor(int number) {
    if(number == 1) return 1;
    int t1 = 1, t2 = 2;
    for(int i=3; i<=number; i++) {
        int tmp = t2;
        t2 += t1;
        t1 = tmp;
    }
    return t2;
}

/*
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

比如n=3时，2*3的矩形块有3种覆盖方法：

 输入

4
返回值

5
 */

int rectCover(int number) {
    if(number == 1) return 1;
    int t1 = 1, t2 = 2;
    for(int i=3; i<=number; i++) {
        int tmp = t2;
        t2 += t1;
        t1 = tmp;
    }
    return t2;
}

/*
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).
示例1
输入

[1,-2,3,10,-4,7,2,-5]
返回值

18
 */

int FindGreatestSumOfSubArray(vector<int> arr) {
    vector<int> dp(arr.size()+1, 0);
    int maxVal = INT_MIN;
    for(int i=0; i<arr.size(); i++) dp[i+1] = dp[i]>0? dp[i]+arr[i]: arr[i];
    for(int i=1; i<dp.size(); i++)
        maxVal = max(maxVal, dp[i]);
    return maxVal;
}


  /*
 * 让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
 * 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
 * 从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,
 * 并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
 * 请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
 *
 * 如果没有小朋友，请返回-1
示例1
输入

5,3
返回值

3
 */

int LastRemaining(int n, int m) {
    if(n<=0) return -1;
    int res = 0;
    for(int i=2; i<=n; i++) {
        res = (res+m)%i;
    }
    return res;
}

/*
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
示例1
输入

"aaa","a*a"
返回值

true
 */
bool isMatch(string s, string p, int i, int j) {
    if(i == 0) return false;
    return s[i-1] == p[j-1] || p[j-1] == '.';
}

bool matchPattern(string str, string pattern) {
    int m = str.size(), n = pattern.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][0] = true;
    for(int i=0; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(pattern[j-1] == '*') dp[i][j] = isMatch(str, pattern, i, j-1)? (dp[i-1][j] || dp[i][j-2]): dp[i][j-2];
            else dp[i][j] = isMatch(str, pattern, i, j)? dp[i-1][j-1]: false;
        }
    }
    return dp[m][n];
}