//
// Created by zhuanxu on 2018/7/7.
//


class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<int> index;
        for (int i=0;i<nums.size(); i++){
            index.push_back(i+nums[i]);
        }
        int jump = 0;
        int max_jump = index[0];
        while (jump<nums.size() && jump <= max_jump){
            if (max_jump<index[jump]){
                max_jump = index[jump];
            }
            jump++;
        }
        return jump == index.size();
    }
};