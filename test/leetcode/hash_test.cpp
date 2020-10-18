//
// Created by hl4080 on 2020/6/21.
//

#include "leetcode_test.h"

void test_twoSum() {
    cout<<"============simple test two-sum begin============="<<endl;
    vector<int> vec{3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(vec, target);
    vector<int> desired{1, 2};
    cout<<"test vector: ";
    printOneDimVec(vec);
    cout<<"taget: "<<target<<endl;
    if(result == desired) {
        cout<<"result of test case: ";
        printOneDimVec(desired);
        cout<<"TEST STATUS: "<<"PASS"<<endl;
    }
    else
        cerr<<"TEST STATUS: "<<"FAILED"<<endl;
    cout<<"============simple test two-sum end==============="<<endl;
}

void test_romanToInt() {
    cout<<"============simple test roman-to-int begin============="<<endl;
    string s1 = "IV", s2 = "LVIII", s3 = "MCMXCIV";
    int res1 = romanToInt(s1), res2 = romanToInt(s2), res3 = romanToInt(s3);
    int desired1 = 4, desired2 = 58, desired3 = 1994;
    cout<<"test case 1: "<<s1<<endl;
    cout<<"test case 2: "<<s2<<endl;
    cout<<"test case 3: "<<s3<<endl;
    if(res1 == desired1 && res2 == desired2 && res3 == desired3) {
        cout<<"test result 1: "<<res1<<endl;
        cout<<"test result 2: "<<res2<<endl;
        cout<<"test result 3: "<<res3<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test roman-to-int end==============="<<endl;
}

void test_validSudoku() {
    cout<<"============simple test valid-sudoku begin============="<<endl;
    vector<vector<char>> board1{
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> board2{
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    bool res1 = isValidSudoku(board1), res2 = isValidSudoku(board2);
    bool desired1 = false, desired2 = true;
    cout<<"test case1: "<<endl;
    printTwoDimVec(board1);
    cout<<"test case2: "<<endl;
    printTwoDimVec(board2);
    if(res1 == desired1 && res2 == desired2) {
        cout<<"result of test case 1: "<<res1<<endl;
        cout<<"result of test case 2: "<<res2<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test valid-sudoku end==============="<<endl;
}

void test_groupAnagroups() {
    cout<<"============simple test group-anagroups begin============="<<endl;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    vector<vector<string>> desired{
            {"tan", "nat"},
            {"eat", "tea", "ate"},
            {"bat"}
    };
    cout<<"test case: ";
    printOneDimVec(strs);
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test group-anagroups end==============="<<endl;
}

void test_findRepeatDnaSequence() {
    cout<<"============simple test find repeat dns sequence begin============="<<endl;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s), desired = {"AAAAACCCCC","CCCCCAAAAA"};
    cout<<"test case: "<<s<<endl;
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test find repeat dns sequence end==============="<<endl;
}