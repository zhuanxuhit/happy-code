//
// Created by zhuanxu on 2018/2/1.
//
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

void explore(unordered_map<int,bool > &visited, unordered_map<int,vector<int>> &adj_edges,int v){
    cout << "visited " << v << endl;
    visited[v] = true;
    if (adj_edges.find(v)!=adj_edges.end()){
        for(auto w : adj_edges[v]){
            if (!visited[w]) {
                explore(visited, adj_edges, w);
            }
        }
    }
}

void addEdges(unordered_map<int,vector<int>> &adj_edges, int b, int e) {
    if(adj_edges.find(b) == adj_edges.end()){
        adj_edges[b] = vector<int>(1,e);
    }else {
        adj_edges[b].push_back(e);
    }
}


void dfs(vector<int> &vs, vector<pair<int,int>>&es) {
    unordered_map<int,bool > visited;
    unordered_map<int,vector<int>> adj_edges;
    for(auto v : vs ){
        visited[v] = false;
    }
    for(auto e:es){
        addEdges(adj_edges, e.first, e.second);
        addEdges(adj_edges, e.second, e.first);
    }
    for(auto v : vs){
        if (!visited[v]){
            explore(visited, adj_edges, v);
        }
    }
}

int main() {
    vector<int> v = {1,2,3,4,5};
    vector<pair<int,int>> e = {make_pair(1,2),make_pair(1,3),make_pair(4,5)};
    dfs(v,e);
}