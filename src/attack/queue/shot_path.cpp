//
// Created by zhuanxu on 2018/1/28.
//
#include <queue>
#include <iostream>
#include <boost/range/irange.hpp>
#include "prettyprint.h"

const int N = 16;

int Cal(int g[N][N]) {
    int step[N] = {0};
    int path[N] = {0};

    int begin = 0;
    std::queue<int> q;
    q.push(begin);
    step[begin] = 0;
    path[begin] = 1;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 1; i < N; ++i) {
            if (g[cur][i] >0){
                // 联通
                if (step[i] == 0 ){
                    step[i] = step[cur] + g[cur][i];
                    path[i] = path[cur];
                    // 进行首次搜索
                    q.push(i);
                }else if (step[i] > step[cur] + g[cur][i]){
                    // 发现最短路径
                    step[i] = step[cur] + g[cur][i];
                    path[i] = path[cur];
                    // 重新搜索
                    q.push(i);
                }else if (step[i] == step[cur] + g[cur][i]){
                    // 刚好是最短路径
                    path[i] += path[cur];
                } else {
                    // step[i] < step[cur] + g[cur][i]
                    // 不管这种情况，不用更新
                }
            }
        }
    }

    std::cout << boost::irange(0,N) << std::endl;
    std::cout << step << std::endl;
    std::cout << path << std::endl;

    return path[N-1];
}

int main () {
    int g[N][N] = {0};
    g[0][1] = g[0][4] = 1;
    g[1][5] = g[1][2] = 1;
    g[2][6] = g[2][3] = 1;
    g[3][7] = 1;
    g[4][5] = 1;
    g[5][6] =  g[5][9] = 1;
    g[6][7] =  g[6][10] = 1;
    g[8][9] =  g[8][12] = 1;
    g[9][10] =  g[9][13] = 1;
    g[10][11] =  g[10][14] = 1;
    g[11][15] = 1;
    g[12][13] = 1;
    g[13][14] = 1;
    g[14][15] = 1;

    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            if (g[i][j] == 1){
                g[j][i] = 1;
            }
        }
    }
    std::cout << Cal(g) << std::endl;
}
