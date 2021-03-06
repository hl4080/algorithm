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

void test_maxProductSubarray() {
    cout<<"============simple test max product subarray begin============="<<endl;
    vector<int> nums{2,3,-2,4};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = maxProduct(nums), desired = 6;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test max product subarray end==============="<<endl;
}

void test_houseRob() {
    cout<<"============simple test house rob begin============="<<endl;
    vector<int> nums{2,1,1,2};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = houseRob(nums), desired = 4;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test house rob end==============="<<endl;
}

void test_houseRobII() {
    cout<<"============simple test house rob II begin============="<<endl;
    vector<int> nums{1,3,1,3,100};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = houseRobII(nums), desired = 103;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test house rob II end==============="<<endl;
}

void test_maximalSquare() {
    cout<<"============simple test maximal square begin============="<<endl;
    vector<vector<char>> matrix{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    cout<<"test case: "<<endl;
    printTwoDimVec(matrix);
    int res = maximalSquare(matrix), desired = 4;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test maximal square end==============="<<endl;
}

void test_numSquare() {
    cout<<"============simple test num square begin============="<<endl;
    int n = 12;
    cout<<"test case: n="<<n<<endl;
    int res = numSquares(n), desired = 3;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test num square end==============="<<endl;
}

void test_lengthOfLIS() {
    cout<<"============simple test length of LIS begin============="<<endl;
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = lengthOfLIS(nums), desired = 4;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test length of LIS end==============="<<endl;
}

void test_countBits() {
    cout<<"============simple test count bits begin============="<<endl;
    int num = 5;
    cout<<"test case: num="<<num<<endl;
    vector<int> res = countBits(num), desired{0,1,1,2,1,2};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test count bits end==============="<<endl;
}

void test_largestDivisibleSubset() {
    cout<<"============simple test largest divisible subsets begin============="<<endl;
    vector<int> nums{4,8,10,240};
    cout<<"test case: ";
    printOneDimVec(nums);
    vector<int> res= largestDivisibleSubset(nums), desired{240,8,4};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test largest divisible subsets end==============="<<endl;
}

void test_getMoneyCount() {
    cout<<"============simple test get monrey count begin============="<<endl;
    int n = 10;
    cout<<"test case: n="<<n<<endl;
    int res = getMoneyAmount(n), desired = 16;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test get monrey count end==============="<<endl;
}

void test_wiggleMaxLength() {
    cout<<"============simple test wiggle max length begin============="<<endl;
    vector<int> nums{1,17,5,10,13,15,10,5,16,8};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = wiggleMaxLength(nums), desired = 7;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test wiggle max length end==============="<<endl;
}

void test_combinationSum4() {
    cout<<"============simple test combination sun 4 begin============="<<endl;
    vector<int> nums{1,2,3};
    int target = 4;
    cout<<"test case:"<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"target: "<<target<<endl;
    int res = combinationSum4(nums, target), desired = 7;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test combination sun 4 end==============="<<endl;
}

void test_rotateFunction() {
    cout<<"============simple test rotate function begin============="<<endl;
    vector<int> A{4, 3, 2, 6};
    cout<<"test case: ";
    printOneDimVec(A);
    int res = maxRotateFunction(A), desired = 26;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test rotate function end==============="<<endl;
}

void test_partitionEqualSum() {
    cout<<"============simple test partition equal subset sum begin============="<<endl;
    vector<int> nums{1,5,11,5};
    cout<<"test case: ";
    printOneDimVec(nums);
    int res = canPartition(nums), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test partition equal subset sum end==============="<<endl;
}