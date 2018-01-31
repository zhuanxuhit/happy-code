//
// Created by zhuanxu on 2018/1/29.
//

#include <cstring>
#include <vector>
#include <iostream>
#include "prettyprint.h"

using namespace std;

void getNext(const char *p, vector<int> &next) {
    // 已知 next[0..j] 求 next[j+1]
    // next[j] = k 的含义是什么？
    // p[0.1.2..k-1]  == p[j-k..j-1]
    // 现在求next[j+1] 此时是 p[j+1] != t[i+j+1]
    // 那我们就看 p[k] ?= p[j]
    // if p[k] == p[j] next[j+1] = next[j] + 1
    // else  因为 p[0.1.2..k-1]  == p[j-k..j-1] , 但是 p[k] != p[j]，
    // 相当于 h = next[k]
    // p[0..h] == p[k-h..k-1],比较 p[h+1] ?= p[j]

    // a  b a a b c a b a
    // -1 0 0 1 1 2 0 1 2
    auto size = strlen(p);
    next[0] = -1;
    for (int j = 1; j < size - 1; j++) {
        // 求 next[j+1]
        int k = next[j];
        while (k != -1) {
            if (p[k] == p[j]) {
                break;
            } else { //p[k] != p[j]
                k = next[k];
            }
        }
        next[j + 1] = k + 1;
    }
    cout << p << endl;
    cout << next << endl;
}

int kmp(const char *t, const char *p) {
    vector<int> next(strlen(p), 0);
    getNext(p, next);
    auto p_len = strlen(p);
    auto t_len = strlen(t);
    // t = "abac"
    // p = "ba"
    int answer = -1;
    for (int i = 0, j = 0; i < t_len;) {
        if (j == -1) {
            i++;
            j = 0;
        }
        if (t[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == p_len){
            // 标准答案
            answer = i - j;
            break;
        }
    }
    return answer;
}

int main() {
    const char *p = string("abaabcaba").data();
    const char *t = string("asabaabcaba").data();

    cout << kmp(t,p) << endl;

}

