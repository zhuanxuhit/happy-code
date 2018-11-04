#include <iostream>
#include <vector>
#include "prettyprint.h"

using namespace std;

# define INF 0x3f3f3f3f

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
    //write your code here
    vector<int> dist(adj.size(), INF);
    dist[0] = 0;
    // 判断是否有负环，更新V个循环，如果一直有
    int iterations = adj.size();
    while (iterations>0){
        bool update = false;
        for(int u=0;u<adj.size();u++){
            for (int j=0;j<adj[u].size();j++){
                int v = adj[u][j];
                if (dist[v] > dist[u] + cost[u][j]) {
                    dist[v] = dist[u] + cost[u][j];
                    update = true;
                }
            }
        }
        if (!update){
            break;
        }
        iterations--;
    }
    return iterations > 0 ? 0 : 1;
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
    cout << cost << endl;
    std::cout << negative_cycle(adj, cost);
}
