#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Input: [2, 6, 4, 8, 10, 9,  15]
//Max    [2, 4, 6, 8,  9, 10, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 思路
        // 从头开始找，
        if (nums.size() <= 0){
            return 0;
        }
        // 太麻烦直接排序做
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int min = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] != sorted[i]){
                min = i;
                break;
            }
        }
        int max = 0;
        for (int i=nums.size()-1;i>=0;i--){
            if (nums[i] != sorted[i]){
                max = i;
                break;
            }
        }
        return max == 0 ? 0 : max - min + 1;
    }
};

int main () {
    Solution s;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << s.findUnsortedSubarray(nums) << endl;
}
