#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>


using namespace std;

//tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
// ["JFK","ATL"] ["ATL","JFK"] ["JFK","SFO"] ["SFO","ATL"] ["ATL","SFO"]
// 都是从JFK开始
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        if (tickets.size() <=0){
            return ans;
        }
        unordered_map<string,multiset<string>> tree;
        for (auto p : tickets){
            tree[p.first].insert(p.second);
        }
        dfs(tree,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(unordered_map<string,multiset<string>> &tree,string s, vector<string> &ans){
        while(tree[s].size()){
            string t = *tree[s].begin();
            tree[s].erase(tree[s].begin());
            dfs(tree,t,ans);
        }
        ans.push_back(s);
    }
};

int main () {
    Solution s;
}
