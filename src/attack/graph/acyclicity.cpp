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
    // 因为环中所有节点肯定有入度和出度
    unordered_map<int,int> inDegree;
    for (int i=0;i<adj.size();i++){
        inDegree[i] = 0;
    }
    for(int i=0;i<adj.size();i++){
        for (auto w : adj[i]){
            inDegree[w]++;
        }
    }
    bool noSource = false;
    while (!noSource){
        // 找到 inDegree 为0的点
        int source = -1;
        for(auto e : inDegree){
            if (e.second == 0){
                source = e.first;
                break;
            }
        }
        if (source != -1){
            inDegree.erase(source);
            for (auto w : adj[source]){
                inDegree[w]--;
            }
        }else {
            noSource = true;
        }
    }
    return inDegree.empty() ? 0 : 1;
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

