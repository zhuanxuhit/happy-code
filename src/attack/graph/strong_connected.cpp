//
// Created by zhuanxu on 2018/2/2.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "prettyprint.h"

using namespace std;

void explore(vector<vector<int> > &adj, vector<int> &used,  vector<int> &order, int x){
    used[x] = 1;
    for(auto w:adj[x]){
        if (0==used[w]){
            explore(adj, used, order, w);
        }
    }
    order.push_back(x);
}


void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order) {
    for(int i=0;i<adj.size();i++){
        if (!used[i]){
            explore(adj, used, order, i);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int> > &adj) {
    int result = 0;

    // 有多少个强连接的。
    // 我们可以先将Graph逆转，然后进行 dfs 的 postOrder 编码，接着从 最大点开始 explore
    // 最大的点意味着在 逆Graph 中是 source，也就意味着这 Graph 中是 sink
    vector<vector<int> > reverse_adj(adj.size(), vector<int>());
    for (int i=0;i<adj.size();i++){
        for (auto w : adj[i]){
            reverse_adj[w].push_back(i);
        }
    }
    // dfs 编码
    vector<int> order;
    vector<int> used(adj.size(), 0);
    dfs(reverse_adj, used, order);
    reverse(order.begin(), order.end());
    used.clear();
    used.resize(adj.size());
//    cout << used << endl;
    vector<int> dummy;
    for (auto v : order){
        if (used[v]){
            continue;
        }
        explore(adj,used,dummy,v);
        result++;
    }

    return result;
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
    std::cout << number_of_strongly_connected_components(adj);
}

