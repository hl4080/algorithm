//
// Created by hl4080 on 2020/7/10.
//

#include "leetcode_test.h"

void test_letterCombination() {
    cout<<"============simple test letter-combination begin============="<<endl;
    string s = "23";
    vector<string> res = letterCombinations(s);
    vector<string> desired{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    cout<<"test case: "<<s<<endl;
    if(vecEqual(res, desired)) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test letter-combination end==============="<<endl;
}

void test_generateParenthesis() {
    cout<<"============simple test generate-parenthesis begin============="<<endl;
    int n = 3;
    vector<string> res = generateParenthesis(n);
    vector<string> desired{"((()))","(()())","(())()","()(())","()()()"};
    cout<<"test case 1: "<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test generate-parenthesis end==============="<<endl;
}

void test_combinationSum() {
    cout<<"============simple test combination sum begin============="<<endl;
    vector<int> candidates{2, 3, 5};
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target);
    vector<vector<int>> desired{
            {2, 2, 2, 2},
            {2, 3, 3},
            {3, 5}
    };
    cout<<"test case: ";
    printOneDimVec(candidates);
    cout<<"target: "<<target<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test combination sum end==============="<<endl;
}

void test_combinationSumII() {
    cout<<"============simple test combination sum II begin============="<<endl;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    vector<vector<int>> desired{
            {1, 1, 6},
            {1, 2, 5},
            {1, 7},
            {2, 6}
    };
    cout<<"test case: ";
    printOneDimVec(candidates);
    cout<<"target: "<<target<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test combination sum II end==============="<<endl;
}

void test_permutations() {
    cout<<"============simple test permutations begin============="<<endl;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = integerPermute(nums);
    vector<vector<int>> desired{
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 2, 1},
            {3, 1, 2}
    };
    cout<<"test case: ";
    printOneDimVec(nums);
    if(desired == res) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test permutations end==============="<<endl;
}

void test_uniquePermutations() {
    cout<<"============simple test unique-permutations begin============="<<endl;
    vector<int> nums{1, 1, 2};
    vector<vector<int>> res = permuteUnique(nums);
    vector<vector<int>> desired{
            {1, 1, 2},
            {1, 2, 1},
            {2, 1, 1}
    };
    cout<<"test case: ";
    printOneDimVec(nums);
    if(desired == res) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test unique-permutations end==============="<<endl;
}