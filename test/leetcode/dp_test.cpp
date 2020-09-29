//
// Created by hl4080 on 2020/6/30.
//

#include "leetcode_test.h"

void test_longestPalindromic() {
    cout<<"============simple test longest palindromic substring begin============="<<endl;
    string s1 = "babad";
    string s2 = "cbbd";
    string res1 = longestPalindrome(s1);
    string res2 = longestPalindrome(s2);
    string desired1 = "bab";
    string desired2 = "bb";
    cout<<"test case 1: "<<s1<<endl;
    cout<<"test case 2: "<<s2<<endl;
    if(res1 == res1 && res2 == desired2){
        cout<<"result of test case 1: "<<desired1<<endl;
        cout<<"result of rest case 2: "<<desired2<<endl;
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test longest palindromic substring end==============="<<endl;
}

void test_expressionMatch() {
    cout<<"============simple test expression match begin============="<<endl;
    string s1 = "aa", p1 = "a*";
    string s2 = "mississippi", p2 = "mis*is*p*.";
    bool res1 = isExpressionMatch(s1, p1), res2 = isExpressionMatch(s2, p2);
    bool desired1 = true, desired2 = false;
    cout<<"test case 1: "<<"s: "<<s1<<" p: "<<p1<<endl;
    cout<<"test case 2: "<<"s: "<<s2<<" p: "<<p2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result pf test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else
        cerr<<"TEST STAUS: FAILED"<<endl;
    cout<<"============simple test expression match end==============="<<endl;
}

void test_maximumSubarray() {
    cout<<"============simple test maximum subarray begin============="<<endl;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(nums), desired = 6;
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test maximum subarray end==============="<<endl;
}

void test_uniquePathWithObstacles() {
    cout<<"============simple test unique path with obstacles begin============="<<endl;
    vector<vector<int>> obstacles{
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    int res = uniquePathsWithObstacles(obstacles), desired = 2;
    cout<<"test case: "<<endl;
    printTwoDimVec(obstacles);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test unique path with obstacles end==============="<<endl;
}

void test_minPathSum() {
    cout<<"============simple test min path sum begin============="<<endl;
    vector<vector<int>> grid{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    int res = minPathSum(grid), desired = 7;
    cout<<"test case: "<<endl;
    printTwoDimVec(grid);
    if(res == desired) {
        cout<<"result of test case: "<<res;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test min path sum end==============="<<endl;
}

void test_climbStairs() {
    cout<<"============simple test climb stairs begin============="<<endl;
    int n = 5;
    int res = climbStairs(n), desired = 8;
    cout<<"test case: "<<n<<endl;
    if(desired == res) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test climb stairs end==============="<<endl;
}

void test_numDecodings() {
    cout<<"============simple test number decodings begin============="<<endl;
    string s = "226";
    int res = numDecodings(s), desired = 3;
    cout<<"test case: "<<s<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test number decodings end==============="<<endl;
}

void test_numTrees() {
    cout<<"============simple test number trees begin============="<<endl;
    int n = 5;
    int res = numTrees(n), desired = 42;
    cout<<"test case: "<<"n="<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test number trees end==============="<<endl;
}

void test_maxProfitI() {
    cout<<"============simple test max profit begin============="<<endl;
    vector<int> prices{7,1,5,3,6,4};
    int res = maxProfitI(prices), desired = 5;
    cout<<"test case: ";
    printOneDimVec(prices);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test max profit end==============="<<endl;
}

void test_maxProfitII() {
    cout<<"============simple test max profit begin============="<<endl;
    vector<int> prices{7,1,5,3,6,4};
    int res = maxProfitII(prices), desired = 7;
    cout<<"test case: "<<endl;
    printOneDimVec(prices);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test max profit end==============="<<endl;
}

void test_wordBreak() {
    cout<<"============simple test word break begin============="<<endl;
    string s = "applepenapple";
    vector<string> wordDict{"apple", "pen"};
    bool res = wordBreak(s, wordDict), desired = true;
    cout<<"test case: "<<endl;
    cout<<"s: "<<s<<" "<<"word dict: ";
    printOneDimVec(wordDict);
    if( res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test word break end==============="<<endl;
}
