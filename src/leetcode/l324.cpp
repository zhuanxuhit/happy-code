#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
//    (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
//    (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

    void wiggleSort(vector<int>& nums) {
        // 先排序
        auto tmp = nums;
        sort(tmp.begin(), tmp.end()); // 升序
        int n = nums.size(), k = (n + 1) / 2, j = n;
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }

    // 时间复杂度 0(n) 或者 空间复杂度 0(1)
    void wiggleSort_v2(vector<int>& nums) {
        int n = nums.size();

        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());

    }
};

int main () {
    Solution s;
}
