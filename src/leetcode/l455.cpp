#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        // g 是需求
        // s 是满足
        int gg=0, ss = 0, ans =0;
        while (gg < g.size() && ss < s.size()) {
            if (g[gg] <= s[ss]){
                ans++;
                gg++;
                ss++;
            }else {
                ss++;
            }
        }
        return ans;
    }
};

int main () {
    Solution s;
    vector<int> g = {1,2};
    vector<int> ss = {1,2,3};
    cout << s.findContentChildren(g,ss) << endl;
}
