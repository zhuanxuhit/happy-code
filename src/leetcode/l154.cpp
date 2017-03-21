#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
// 进行旋转，并且有重复
class Solution {
public:
    // 0(n)
    int findMin(vector<int>& nums) {
        // 其实就是找到转折点
        // nums[i] > nums[i+1]
        int min = 0;
        for(int i=0;i<nums.size()-1;i++){
            if (nums[i] > nums[i+1]){
                min = i+1;
            }
        }
        return nums[min];
    }
    // 二分法
    int findMin_v1(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        // left  mid right
        // [left, right)
        // if min 在 mid 左边 即  left min mid right 那此时 left > mid && mid < right, right = mid
        // note! 上面的条件有错误，只能是mid < right
        // if min 在 mid 右边 即  left mid min right 那此时 left < mid && mid > right, left = mid+1
        // note! 上面的条件有错误，只能是 mid > right
        // if min 就是 mid    即  left min==mid, right，那此时 left > mid > right,  right = mid
        //
        // 结束的条件是 [left, right) left == right, 返回
        // 此处不变的条件是 min 包含于 [left, right)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else if (nums[mid] > nums[right]) left = mid+1;
            else right--; // 此处为什么不能直接 right = mid，因为此时可能 mid  和 right 是跨越了最小值，
            // 如：3,3,1,3
        }
        return nums[left];
    }

    // 思路类似于解法1，我们的办法是怎么能快速的找到
    // nums[l] > nums[l+1]
    // 或者再换个 nums[l] < nums[l+1]的第一个l
    // [l, r)
    int findMin_v2(vector<int>& nums) {
        int l = 0,r = nums.size() -1,m;
        while(l<r){
            if (nums[l] < nums[r]) break;
            m = l + (r-l)/2;
            if (nums[m]>nums[r]) l = m+1;
            else if (nums[m] < nums[r]) r = m;
            else {r--;};
        }
        return nums[l];
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1};
    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << s.findMin_v1(nums1) << endl;
    cout << s.findMin_v1(nums2) << endl;
    vector<int> nums3 = {3,1};
    cout << s.findMin_v1(nums3) << endl;
    vector<int> nums4 = {3,3,1,3};
    cout << s.findMin_v2(nums4) << endl;
}