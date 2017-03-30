#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        // 先按points的start排序
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(),points.end(),[](pair<int, int> &p1,pair<int, int> &p2){
            return p1.first <= p2.first;
        });
        int ans = 1;
        int terminal = points[0].second;
        for(int i=1;i<points.size();i++){
            if (points[i].first > terminal){
                ans++;
                terminal = points[i].second;
            }else if (points[i].second<terminal){
                terminal = points[i].second;
            }
        }
        return ans;
    }
};

int main () {
    Solution s;
    vector<pair<int,int>> points = {make_pair(10,16), make_pair(2,8), make_pair(1,6), make_pair(7,12)};
    cout << s.findMinArrowShots(points) << endl;
}
