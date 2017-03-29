#include <iostream>
#include <string>
#include <vector>
//#include <functional>

using namespace std;

// case [1,1,2] have the following unique permutations:
//[
    //[1,1,2],
    //[1,2,1],
    //[2,1,1]
//]
class Solution {
public:
    // permute 排列
    vector<int> next_permute(vector<int>& nums) {
        // 找到第一个不
        int min = -1;
        for(int i=nums.size()-1;i>0;i--) {
            if (nums[i] > nums[i-1]){
                min = i-1;
                break;
            }
        }
        if (min == -1){
            return vector<int>(); // 空
        }
        // 将 min 值 与之前的数查找，找到最小的
        for(int i=nums.size()-1;i>=min+1;i--){
            if (nums[i] > nums[min]) {
                swap(nums[i],nums[min]);
                break;
            }
        }
        // reverse
        reverse(nums.begin()+min+1,nums.end());
        return nums;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.empty()){
            return result;
        }

        sort(nums.begin(),nums.end());
        result.push_back(nums);
        auto ans = next_permute(nums);

        while(!ans.empty()){
            result.push_back(ans);
            ans = next_permute(nums);
        }
        return result;
    }

    void dfs(int size,int pos,vector<int>& path, vector<vector<int>>&ans) {
        if (size == pos) {
            ans.push_back(path);
            return;
        }
        // 决策
        int min = *min_element(path.begin()+pos,path.end()),max = *max_element(path.begin()+pos,path.end());
        vector<bool> b(max-min+1,false);
        for(int i=pos;i<size;i++){
            if (b[path[i]-min] == false){
                // 没当过头节点
                b[path[i]-min] = true;
                swap(path[i],path[pos]);
                dfs(size,pos+1,path,ans);
                // 交换回来
                swap(path[i],path[pos]);
            }
        }
    }

    vector<vector<int>> permuteUnique_v2(vector<int>& nums) {
        // 怎么用回朔的方法
        vector<vector<int>> ans = {};
        dfs(nums.size(),0,nums,ans);
        return ans;
    }
};


int main () {
    Solution s;

    vector<int> nums = {1,2,3};

    auto result = s.permuteUnique_v2(nums);

    for ( const std::vector<int> &v : result )
    {
        for ( int x : v ) std::cout << x << ' ';
        std::cout << std::endl;
    }
}
