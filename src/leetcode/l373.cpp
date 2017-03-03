//
// Created by zhuanxu on 17/3/3.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 找到第一个和第二个组合中 sum 最小的
        int length1 = nums1.size();
        int length2 = nums2.size();
        auto cmp = [](pair<int,int>&n1,pair<int,int>&n2){ return (n1.first+n1.second) > (n2.first+n2.second);};
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> q1(cmp);
        for(auto n1 : nums1){
            for (auto n2 : nums2){
                q1.push(make_pair(n1,n2));
            }
        }
        vector<pair<int, int>> res;
        for(int i=0;i<k && !q1.empty();i++){
            res.push_back(q1.top());q1.pop();
        }
        return res;
    }
};

void print(vector<pair<int, int>> vec) {
    for(auto iter : vec){
        cout << "(" << iter.first << "," << iter.second << ")" << endl;
    }
}


int main() {
    vector<int> num1 = {1,7,11};
    vector<int> num2 = {2,4,6};
    Solution s;
    auto result = s.kSmallestPairs(num1,num2,3);
    print(result);
}