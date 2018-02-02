//
// Created by zhuanxu on 2018/2/1.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



void explore(unordered_map<int, bool> &visited, vector<vector<int> > &adj, int v){
    visited[v] = true;
    for(auto w : adj[v]){
        if (!visited[w]){
            explore(visited,adj,w);
        }
    }
}

int reach(vector<vector<int> > &adj, int x, int y) {
    // 判断 x -> y 是否有路径
    auto size = adj.size();
    unordered_map<int, bool> visited;
    for(int i=0;i<size;i++){
        visited[i] = false;
    }
    explore(visited, adj, x);

    return visited[y] ? 1 : 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>()); // 邻接矩阵
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
}