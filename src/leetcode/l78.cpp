#include <iostream>
//#include <string>
#include <vector>
//#include <cmath>

using namespace std;

//Given a set of distinct integers, nums, return all possible subsets.
// 输入不重复的集合，返回所有的可能的子序列
class Solution {
public:
    void dfs(vector<int>& nums, int position, vector<int>&path, vector<vector<int>>&ans){
        // 结束条件
        if (position == nums.size()) {
            ans.push_back(path);
            return;
        }
        // 选择
        dfs(nums,position+1,path,ans); // 不选择
        path.push_back(nums[position]); // 选择
        dfs(nums,position+1,path,ans);
        path.pop_back(); // 将数据清除返回
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        // 思路其实也很简单，就是对于nums中的所有数，都有两个选择：选 不选，因此所有的组合是
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums,0,path,ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    auto result = s.subsets(nums);
    for(auto i=result.begin();i!=result.end();i++){
        cout << "[";
        for(auto j=(*i).begin(); j!=(*i).end(); j++){
            cout << *j << ",";
        }
        cout << "]" << endl;
    }
}