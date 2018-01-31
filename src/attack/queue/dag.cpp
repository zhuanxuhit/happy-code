//
// Created by zhuanxu on 2018/1/27.
//

#include <vector>
#include <queue>
#include <iostream>


int graph[13][13] = {0};


void initGraph() {
    graph[0][1] = 1;
    graph[0][5] = 1;
    graph[0][6] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[3][5] = 1;
    graph[5][4] = 1;
    graph[6][4] = 1;
    graph[6][9] = 1;
    graph[7][6] = 1;
    graph[8][7] = 1;
    graph[9][10] = 1;
    graph[9][11] = 1;
    graph[9][12] = 1;
    graph[11][12] = 1;
}

void TopoLogic(std::vector<int> &toposort, int* inDegree){
    std::queue<int> q;
    for(int i=0;i<13;i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        toposort.push_back(cur);
        for(int i=0;i<13;i++){
            if (graph[cur][i]>0){
                inDegree[i] --;
                if (inDegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    initGraph();
    // 计算每个节点的入度
    int inDegree[13] = {0};
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++){
            if (graph[i][j] == 1){
                inDegree[j] += 1;
            }
        }
    }
    std::vector<int> toposort;
    TopoLogic(toposort, inDegree);
    for(auto iter : toposort){
        std::cout << iter << std::endl;
    }
}