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

void test_isIsomorphic() {
    cout<<"============simple test is isomorphic begin============="<<endl;
    string s = "egg", t = "add";
    cout<<"test case: "<<endl;
    cout<<"s: "<<s<<" "<<"t: "<<t<<endl;
    bool res = isIsomorphic(s, t), desired = true;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test is isomorphic end==============="<<endl;
}

void test_containDuplicate() {
    cout<<"============simple test contain duplicate begin============="<<endl;
    vector<int> nums{1,2,3,1};
    bool res = containsDuplicate(nums), desired = true;
    cout<<"test case: ";
    printOneDimVec(nums);
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test contain duplicate end==============="<<endl;
}

void test_containDuplicatesII() {
    cout<<"============simple test contain duplicate II begin============="<<endl;
    vector<int> nums{1,2,3,1};
    int k = 3;
    bool res = containsNearbyDuplicate(nums, k), desired = true;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"k = "<<k<<endl;
    if(res == desired) {
        cout<<"result of test case"<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    }else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test contain duplicate II end==============="<<endl;
}

void test_containduplicateIII() {
    cout<<"============simple test contain duplicate III begin============="<<endl;
    vector<int> nums{1,2,3,1};
    int k = 3, t = 0;
    bool res = containsNearbyAlmostDuplicate(nums, k, t), desired = true;
    cout<<"test case: "<<endl;
    cout<<"nums: ";
    printOneDimVec(nums);
    cout<<"k="<<k<<", t="<<t<<endl;
    if(res == desired) {
        cout<<"result of test case: "<<res<<endl;
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test contain duplicate III end==============="<<endl;
}

void test_topKfrequent() {
    cout<<"============simple test top K frequent begin============="<<endl;
    vector<int> nums{5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2,-4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,-1,4,2,8,-3,5,-9,-3,6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,-4,-1,-1,6,-8,-9,-1,9,-9,3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5};
    int k = 7;
    cout<<"test case: "<<endl;
    printOneDimVec(nums);
    cout<<"k="<<k<<endl;
    vector<int> res = topKFrequent(nums, k), desired{8,-5,-8,-1,2,4,0};
    if(res == desired) {
        cout<<"result of test case: ";
        printOneDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test top K frequent end==============="<<endl;
}

void test_kSmallestPairs() {
    cout<<"============simple test k smallest pairs begin============="<<endl;
    vector<int> nums1{1,1,2}, nums2{1,2,3};
    int k = 10;
    cout<<"test case: "<<endl;
    cout<<"nums1: ";
    printOneDimVec(nums1);
    cout<<"nums2:";
    printOneDimVec(nums2);
    cout<<"k="<<k<<endl;
    vector<vector<int>> res = kSmallestPairs(nums1, nums2, k);
    vector<vector<int>> desired {{1,1}, {1,1}, {2,1}, {1,2},{1,2},{2,2},{1,3},{1,3},{2,3}};
    if(res == desired) {
        cout<<"result of test case: "<<endl;
        printTwoDimVec(res);
        cout<<"TEST STATUS: PASS"<<endl;
    } else cerr<<"TEST STATUS: FAILED"<<endl;
    cout<<"============simple test k smallest pairs end==============="<<endl;
}