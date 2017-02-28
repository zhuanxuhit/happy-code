//
// Created by zhuanxu on 17/2/28.
//

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements_v1(vector<int>& nums) {
        // 暴力搜索
        int size = (int) nums.size();
        vector<int> next(size);
        for(int i=0;i<size;i++){
            int j = i+1;
            while ( (j % size) != i ) {
                if (nums[j % size] > nums[i]){
                    next[i] = nums[j % size];
                    break;
                }
                j = (j + 1) % size;
            }
            if ((j % size)==i){
                next[i] = -1;
            }
        }
        return next;
    }

    vector<int> nextGreaterElements_v2(vector<int>& nums) {
        // 怎么进行优化，其实一个思路就是将每次向后找到的数能保存下来，不用每次都重新还是遍历
        int size = nums.size();
        if (size == 0){
            return nums;
        }
        vector<int> ret(size,-1);
        stack<int> idx;
        for(int i=0;i<size;i++){
            while (!idx.empty() && nums[idx.top()] < nums[i]){
                ret[idx.top()] = nums[i];
                idx.pop();
            }
            idx.push(i);
        }
        for(int i=0;i<size;i++){
            while (!idx.empty() && nums[idx.top()] < nums[i]){
                ret[idx.top()] = nums[i];
                idx.pop();
            }
            if (idx.empty()) break;
        }
        return ret;
    }
};

void print_vec(vector<int>&nums) {
    for(auto i : nums){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> nums = {1,2,1};
    auto res = s.nextGreaterElements_v1(nums);
    print_vec(res);
}