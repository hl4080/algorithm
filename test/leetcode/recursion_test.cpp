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

void test_getPermutation() {
    cout<<"============simple test get permutation begin============="<<endl;
    int n1 = 3, k1 = 3;
    int n2 = 4, k2 = 9;
    string res1 = getSpecialPermutation(n1, k1), res2 = getSpecialPermutation(n2, k2);
    string desired1 = "213", desired2 = "2314";
    cout<<"test case 1: "<<"n:"<<n1<<" k1:"<<k1<<endl;
    cout<<"test case 2: "<<"n:"<<n2<<" k2:"<<k2<<endl;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test get permutation end==============="<<endl;
}

void test_combinations() {
    cout<<"============simple test combinations begin============="<<endl;
    int n=4, k=2;
    vector<vector<int>> res = combinations(n, k);
    vector<vector<int>> desired{
            {1, 2},
            {1, 3},
            {1, 4},
            {2, 3},
            {2, 4},
            {3, 4}
    };
    cout<<"test case: "<<"n: "<<n<<" k: "<<k<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test combinations end==============="<<endl;
}

void test_subsets() {
    cout<<"============simple test subsets begin============="<<endl;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    vector<vector<int>> desired{
            {}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}
    };
    cout<<"test case: ";
    printOneDimVec(nums);
    if(desired == res) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test subsets end==============="<<endl;
}

void test_wordExistBoard() {
    cout<<"============simple test word exist board begin============="<<endl;
    vector<vector<char>> board{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    string word1 = "SEE", word2 = "ABCB";
    bool res1 = wordExistBoard(board, word1), res2 = wordExistBoard(board, word2);
    cout<<"test case: "<<endl;
    cout<<"board: "<<endl;
    printTwoDimVec(board);
    cout<<"word1: "<<word1<<endl;
    cout<<"word2: "<<word2<<endl;
    bool desired1 = true, desired2 = false;
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case1: "<<res1<<endl;
        cout<<"result of test case2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test word exist board end==============="<<endl;
}

void test_grayCode() {
    cout<<"============simple test gray code begin============="<<endl;
    int n = 3;
    vector<int> res = grayCode(n);
    vector<int> desired{0,1,3,2,6,7,5,4};
    cout<<"test case: "<<"n="<<n<<endl;
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test gray code end==============="<<endl;
}

void test_subesetsWithDup() {
    cout<<"============simple test subsets with dup begin============="<<endl;
    vector<int> nums{1, 2, 2};
    vector<vector<int>> res = subsetsWithDup(nums);
    cout<<"test case: ";
    printOneDimVec(nums);
    vector<vector<int>> desired{{}, {1}, {1,2}, {1,2,2}, {2}, {2,2}};
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test subsets with dup end==============="<<endl;
}

void test_restoreIpAddr() {
    cout<<"============simple test restore ip address begin============="<<endl;
    string s = "25525511135";
    vector<string> res = restoreIpAddresses(s), desired{"255.255.11.135","255.255.111.35"};
    cout<<"test case: s: "<<s<<endl;
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test restore ip address end==============="<<endl;
}

void test_minPathTriangle() {
    cout<<"============simple test min path triangle begin============="<<endl;
    vector<vector<int>> triangle{
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
    };
    int res = minPathTriangle(triangle), desired = 11;
    cout<<"test case: "<<endl;
    printTwoDimVec(triangle);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test min path triangle end==============="<<endl;
}

void test_surroundRegions() {
    cout<<"============simple test surround regions begin============="<<endl;
    vector<vector<char>> board{
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
    };
    cout<<"test case: "<<endl;
    printTwoDimVec(board);
    surroundRegions(board);
    vector<vector<char>> desired{
            {'X','X','X','X'},
            {'X','X','X','X'},
            {'X','X','X','X'},
            {'X','O','X','X'}
    };
    if(board == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(desired);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test surround regions end==============="<<endl;
}

void test_palinfromePartition() {
    cout<<"============simple test palindrome partition begin============="<<endl;
    string s = "abbab";
    vector<vector<string>> res = palindromePartition(s);
    vector<vector<string>> desired{
            {"a","b","b","a","b"},
            {"a","b","bab"},
            {"a","bb","a","b"},
            {"abba","b"}
    };
    cout<<"test case: "<<s<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(desired);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test palindrome partition end==============="<<endl;
}