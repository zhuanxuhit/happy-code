#include <cstring>
#include <algorithm>
#include <iostream>
#include "prettyprint.h"

using namespace std;
//
// Created by zhuanxu on 2018/1/29.
//
void manacher(const char* s, int *P){
    auto size = strlen(s);
    P[0] = 1;
    int mx = 1;
    int id = 0;
    for (int i=1;i<size;i++){
        if (mx>i){
            P[i] = min(mx-i,P[2*id-i]);
        }else {
            P[i] = 1;
        }
        while (s[i+P[i]] == s[i-P[i]]){
            P[i]++;
        }
        if (i + P[i] > mx) {
            mx = i + P[i];
            id = i;
        }
    }
}

int main() {
    // 最大回文子串,马拉车算法
    // 12212321 => $#1#2#2#1#2#3#2#1#
    char* s = "$#1#2#2#1#2#3#2#1#";
    // 假设我们已经有了 P[0,1...j] 现在要求 P[j+1]
    // 怎么能最好的利用之前的信息呢？
    // 假设 id 是 0-j 中 P[id] 最大的，那意味着
    //  (id - P[id]     id  ... id + P[id]) 注意都是开区间 是我们能覆盖的回文区间
    // 现在有 i ， 其对称点为 k = 2*id - i ，P[k]
    // 设置 mx = id + P[id] , i, P[k]
    // if (mx - i) < P[k] P[i] = mx - i
    // else P[i] = P[k]
//    const int size = strlen(s);
    int P[18] = {0};
    manacher(s,P);
    cout << P << endl;
}

