//
// Created by zhuanxu on 2018/2/6.
//
#include <vector>
#include <iostream>
#include "prettyprint.h"
using namespace std;

int maxProfit(const int* price, int size){
    const int* a = price - 1; // 下标从1开始
    // dp[买/卖][1..size], 我们需要求 dp[买][1]的值
    // dp[买][i] 表示从 A[i,i+1..n]
    // dp[买][i] = max(dp[卖][i+1] - a[i], dp[买][i+1])
    // dp[卖][i] = max(dp[卖][i+1],a[i])
    // 0：买 1：卖
    // 我们最终求的是 dp[买][1]
    vector<vector<int>> dp(2, vector<int>(size+2,0));
    // 0：买 1：卖 -1：放弃
    vector<vector<int>> decision(2, vector<int>(size+1,-1));
//    dp[0][size] = 0;
//    dp[1][size] = a[size];
    for ( int i=size;i>0;i--){
        dp[0][i] = max(dp[0][i+1], dp[1][i+1] - a[i]); // 买，不操作
        if (dp[0][i] != dp[0][i+1]){
            decision[0][i] = 0;
        }
        dp[1][i] = max(dp[1][i+1], a[i]); // 卖，不操作
        if (dp[1][i] == a[i]){
            decision[1][i] = 1;
        }
    }
    cout << decision << endl;
    int op = 0; // 先买操作
    string opName[] = {"买","卖"};
    for ( int i=1;i<=size;i++){
        if (decision[op][i] == op){
            cout << opName[op] << " "<< a[i] << endl;
            op = 1 - op;
        }
    }
    return dp[0][1];
}

int maxKProfit(const int* price, int size, int K){
    const int* a = price - 1; // 下标从1开始
    // dp[买/卖][K][1..size], 我们需要求 dp[买][K][1]的值
    // dp[买][K][i] 表示从 A[i,i+1..n] 中买卖K次
    // dp[买][k][i] = max(dp[卖][k][i+1] - a[i], dp[买][k][i+1])
    // dp[卖][k][i] = max(dp[卖][k][i+1],dp[买][k-1][i+1]+a[i])
    // 0：买 1：卖
    // 我们最终求的是 dp[买][1]
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(K+1, vector<int>(size+2,0)));
//    dp[0][k][size] = 0;
//    dp[1][k][size] = a[size];

    // 0：买 1：卖 -1：放弃
    vector<vector<vector<int>>> decision(2, vector<vector<int>>(K+1, vector<int>(size+1,-1)));
    for ( int i=size;i>0;i--){
        for ( int k=1;k<=K;k++){
            dp[0][k][i] =  max(dp[0][k][i+1], dp[1][k][i+1] - a[i]);
            if (dp[0][k][i] != dp[0][k][i+1]){// 买，不操作
                decision[0][k][i] = 0;
            }
            dp[1][k][i] = max(dp[1][k][i+1], dp[0][k-1][i+1]+a[i]);
            // 卖，不操作
            if (dp[1][k][i] != dp[1][k][i+1]){
                decision[1][k][i] = 1;
            }
        }
    }

    cout << decision << endl;
    int op = 0; // 先买操作
    string opName[] = {"买","卖"};
    int num = K * 2;
    for ( int i=1;i<=size;i++){
        if (decision[op][(num+1)/2][i] == op){
            cout << opName[op] << " "<< a[i] << endl;
            op = 1 - op;
            num--;
        }
    }

    return dp[0][K][1];
}


int main() {
    int price[] = {7,1,5,3,6,4}; // 1买6卖 = 5
//    int price[] = {7,6,4,3,1}; // 0
    cout << maxProfit(price, sizeof(price) / sizeof(int)) << endl;
    cout << maxKProfit(price, sizeof(price) / sizeof(int), 2) << endl;
}