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


int main() {
    string s;
    LCS("ABCBDAB","BDCABA",s);
    cout << s << endl;
}