//
// Created by zhuanxu on 2018/1/29.
//

#include <string>
#include <vector>
#include <iostream>
#include "prettyprint.h"

using namespace std;
void LCS(const char* str1, const char* str2, string &str){
    auto size1 = static_cast<unsigned  long>(strlen(str1));
    auto size2 = static_cast<unsigned  long>(strlen(str2));
    // 计数从 1 开始。
    const char* s1 = str1 - 1;
    const char* s2 = str2 - 1;

    vector<vector<int>> chess(size1+1, vector<int>(size2+1));
    for(int i=0;i<=size1;i++){
        chess[i][0] = 0;
    }
    for(int j=0;j<=size2;j++){
        chess[0][j] = 0;
    }
    // chess[i][j] 表示 x[1-i], y[1-j] 最大公共子序列长度
    // chess[i][j] = 0 if i==0 || j == 0
    //             = chess[i-1][j-1] if x[i]==y[i]
    //             = max(chess[i-1][j],chess[i][j-1]) if x[i]!=y[i]
    for (int i=1;i<=size1;i++){
        for (int j=1;j<=size2;j++){
            if (s1[i] == s2[j]){
                chess[i][j] = chess[i-1][j-1] + 1;
            }
            else {
                chess[i][j] = max(chess[i][j-1],chess[i-1][j]);
            }
        }
    }
    for (int i=0;i<=size1;i++){
        cout << chess[i] << endl;
    }
    // 怎么找到这个路径
    auto i = static_cast<int>(size1);
    auto j = static_cast<int>(size2);
    while (i>0 && j>0){
        if (s1[i] == s2[j]){
            str.push_back(s1[i]);
            i--;
            j--;
        }else {
            if (chess[i][j-1] > chess[i-1][j]){
                j--;
            }else {
                i--;
            }
        }
    }

    reverse(str.begin(),str.end());
}


// 567128
int LIS(const char* s){
    // 假设我们知道了 L[i] = [x0,x1,x2...xi]
    // 此时 b[i] 为以 xi 结尾的最长递增子序列
    // 那怎么求 b[i] 呢？ 遍历 x[0-i-1], if x[j]<x[i], 则 b[i] = max(b[j] + 1)
    auto length = strlen(s);
    vector<int> b(length,0);
    b[0] = 1;
    for (int i=1;i<length;i++){
        int max_len = 1;
        for (int j=0;j<i;j++){
            if (s[j] < s[i]){
                max_len = max(max_len, b[j]);
            }
        }
        b[i] = max_len+1;
    }
    cout << b << endl;
    return *max_element(b.begin(), b.end());
}

void LIS(const char* s, string &str) {
    auto length = strlen(s);
    string s2 = string(s,s+length);
//    cout << s2 << endl;
    sort(s2.begin(), s2.end());
//    cout << s2 << endl;
    LCS(s,s2.data(),str);
}

int main() {
    string s;
    LIS("567128",s);
    cout << s << endl;
    cout << LIS("1462897") << endl;
}