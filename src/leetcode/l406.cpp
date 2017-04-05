#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Input:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

//Output:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // 先排序
        // pair 中 first 是身高， second 是之前比其高的数
        // 先按身高降序，再按个数升序
        sort(people.begin(), people.end(), [](pair<int, int>&a,pair<int, int> &b){
            return a.first == b.first ? a.second < b.second :  a.first > b.first;
        });
        vector<pair<int, int>> ans;
//        ans.resize(people.size());
        // 按身高排序后，
        // 它的前面是没有比他高的人，
        // 按这个思路，第一个元素在第一个位置，
        // 比如说按他给的案列，先插入的是（7,0），（7,1）
        // 这样来一个（6,1）他插入的位置前面的数都是大于等于它的，有it.second个，所以插入在这个位置
        for(auto p : people){
            ans.insert(ans.begin()+p.second,p);
        }
        return  ans;
    }
};



int main () {
    Solution s;
//    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    vector<pair<int, int>> people = {make_pair(7,0),make_pair(4,4),
                                     make_pair(7,1),make_pair(5,0),make_pair(6,1),make_pair(5,2)};
    auto ans = s.reconstructQueue(people);
    cout << "[";
    for(auto p : ans){
        cout << "[" << p.first << "," << p.second << "]";
        if (people[people.size()-1] != p){
            cout << ",";
        }
    }
    cout << "]";
}
