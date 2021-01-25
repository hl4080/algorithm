//
// Created by hl4080 on 2021/1/25.
//

#include "string.h"

/*
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

void replaceSpace(char *str,int length) {
    int cnt = 0;
    for(int i=0; i<length; i++) {
        if(str[i] == ' ') cnt++;
    }
    int newLength = length + cnt*2;
    str[newLength] = '\0';
    int p2 = newLength-1, p1 = length-1;
    while(p1 >=0) {
        if(str[p1] != ' ') {
            str[p2] = str[p1];
            p2--;
        }else {
            str[p2-2] = '%';
            str[p2-1] = '2';
            str[p2] = '0';
            p2 -= 3;
        }
        p1--;
    }
}