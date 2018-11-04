//
// Created by zhuanxu on 2018/2/2.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
    //write your code here
    // 走bfs
    vector<int> distance(adj.size(),-1);
    distance[s] = 0;
    deque<int> q;
    q.push_back(s);
    while (!q.empty()){
        int w = q.front();
        q.pop_front();
        for(auto v: adj[w]){
            if (distance[v] == -1){// 未被访问过
                distance[v] = distance[w] + 1;
                q.push_back(v);
            }
            if (v == t){
                return distance[v];
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
