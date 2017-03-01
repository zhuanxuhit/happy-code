//
// Created by zhuanxu on 17/3/1.
//

#include <iostream>
#include <vector>
using namespace std;

// Given [3,2,1,5,6,4] and k = 2, return 5.
class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        return nums[k-1];
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    Solution s;
    cout << s.findKthLargest(nums,2) << endl;
}
