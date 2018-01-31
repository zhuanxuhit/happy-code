//
// Created by zhuanxu on 2018/1/31.
//

#include <cstring>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "prettyprint.h"

using namespace std;

void PreBmBc(const char *pattern, int n, unordered_map<char, int> &bmBc) {
    int i;

    for (i = 1; i <= n; i++) {
        bmBc[pattern[i]] = i;
    }
}



void SuffixLength(const char *pattern, int n, int N[]) {
    for (int j = 1; j < n; j++) {
        int i;
        for (i = 0; pattern[n - i] == pattern[j - i] && i <= j; i++) {
        }
        N[j] = i;
    }
    N[n] = n;
}
void CalL(const char* pattern, int n, int L[], const int N[]){
    for (int i=1;i<=n;i++){
        L[i] = 0; // L[1] 是没意义的，这里也初始化为0
    }
    for (int j=1;j<n;j++){ // N[n] 是没有意义的，或者说 N[n] 一定为 n
        if (N[j]>0){
            int i = n - N[j] + 1; // N[j] = 0, i = n+1
            L[i] = j;
        }
    }
}

void Call(const char* pattern, int n, int l[], const int N[]){
    for (int i=1;i<=n;i++){
        l[i] = 0; // l[1]其实没有意义，
    }
    for(int j=1;j<n;j++){
        if (N[j] == j){
            for (int i=1;i<=n-j+1;i++){
                l[i] = j;
            }
        }
    }
    l[1] = 0;
}

void PreBmGs(const char *pattern, int n, int bmGs[]) {
//    const char* p = pattern - 1; // 让下标从1开始
    vector<int> N(n+1);
    vector<int> L(n+1);
    vector<int> l(n+1);
    SuffixLength(pattern, n, N.data());

    CalL(pattern,n,L.data(),N.data());
    Call(pattern,n,l.data(),N.data());



    for (int i=2;i<n;i++){
        if (L[i]>0){
            bmGs[i] = n - L[i];
        }else {
            bmGs[i] = n - l[i];
        }
    }
    bmGs[n] = 1; // special case

    cout << vector<char>(pattern+1, pattern+n+1)<< endl;
    cout << vector<int>(N.begin()+1,N.end()) << endl;
    cout << vector<int>(L.begin()+1,L.end()) << endl;
    cout << vector<int>(l.begin()+1,l.end()) << endl;
    cout << vector<int>(bmGs+1, bmGs+n+1) << endl;
}

void BM (const char *T, const char *P){
    const char* target = T - 1;
    const char* pattern = P - 1;
    auto m = static_cast<int>(strlen(T));
    auto n = static_cast<int>(strlen(P));

//    vector<int> BmBc(256);
    unordered_map<char, int> BmBc;
    vector<int> BmGs(n+1);
    PreBmBc(pattern,n, BmBc);

    cout << BmBc << endl;
//    return;

    PreBmGs(pattern,n, BmGs.data());
//    return;
    for (int k=n;k<=m;){
        int i=n;
        int h = k;
        while (i>0 && target[h] == pattern[i] ) {
            h--;
            i--;
        }
        if(i==0){
            // 代表完全匹配了。
            cout << h+1 << endl; // 输出匹配开始的下标
            cout << "shift " << BmGs[2] << endl;
            k = k + BmGs[2];  // 此时相当于 mismatch 发送在 i = 1中，则shift BmGs[2]
        }
        else {
            int bc = 0;
            int gs = 1;
            // 此时相当于 i 位置发生 mismatch P[i+1 .. n] 都是 match
            auto iter = BmBc.find(target[h]);

            if(iter != BmBc.end())
            {
                bc = BmBc[target[h]];
            }else {
                bc = 0;
            }
            if (i != n){ // 发生在最末尾，我们取 gs = 1
                gs = BmGs[i+1];
            }else {
                gs = 1;
            }
            int shift = max(i-bc,gs);
            cout << "shift " << shift << endl;
            k += shift;
        }
    }
}
int main() {
    BM( "GCATCGCAGAGAGTATACAGTACG","GCAGAGAG");
}