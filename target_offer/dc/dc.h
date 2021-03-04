//
// Created by hl4080 on 2021/1/28.
//

#ifndef ALOGRITHM_DC_H
#define ALOGRITHM_DC_H

#include <vector>
#include <queue>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray);
class StreamMedian {
public:
    void Insert(int num);
    double GetMedian();
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int cnt = 0;
};


#endif //ALOGRITHM_DC_H
