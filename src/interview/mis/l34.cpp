//
// Created by zhuanxu on 2018/7/7.
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        std::vector<int> bound;
        bound.resize(2,-1);
        while (left<=right){
            int mid = left + (right-left)/2;
            if (target > nums[mid]) {
                left = mid + 1;
            }else if (target < nums[mid]){
                right = mid  - 1;
            }else {
                // 找左右Bound
                int m = mid;
                while (m >=0 && nums[m]==target){
                }
            }
        }
    }
};