//
// Created by zhuanxu on 2018/2/2.
//


#include <iostream>
#include <algorithm>
#include <vector>

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

vector<int> toposort(vector<vector<int> > &adj) {
    vector<int> used(adj.size(), 0);
    vector<int> order;
    //write your code here
    dfs(adj, used, order);
    reverse(order.begin(),order.end());
    return order;
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
    vector<int> order = toposort(adj);
    for (size_t i = 0; i < order.size(); i++) {
        std::cout << order[i] + 1 << " ";
    }
}
