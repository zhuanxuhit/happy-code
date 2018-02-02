//
// Created by zhuanxu on 2018/2/2.
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


int acyclic(vector<vector<int> > &adj) {
    // 不断找出 source 点，直到没有了，但是图中还有点，说明有环。

}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj);
}

