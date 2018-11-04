//
// Created by zhuanxu on 2018/2/3.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

# define INF 0x3f3f3f3f

struct pairGreater {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
        return x.second > y.second;
    }
};

int distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t) {
    //write your code her
    // 计算两点之间的距离
    vector<int> dist(adj.size(), INF);
    vector<int> prev(adj.size(), -1);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, pairGreater> q; // 小堆
    for (int i = 0; i < adj.size(); i++) {
        q.push(make_pair(i, dist[i]));
    }
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        for (int i=0;i<adj[u.first].size();i++){
            int v = adj[u.first][i];
            if (dist[v] > dist[u.first] + cost[u.first][i]) {
                dist[v] = dist[u.first] + cost[u.first][i];
                prev[v] = u.first;
                // 更新距离
                q.push(make_pair(v, dist[v]));
            }
        }
    }

    return dist[t] == INT_MAX ? -1 : dist[t];
}


int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
