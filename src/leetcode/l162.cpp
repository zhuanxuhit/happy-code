#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 找到峰值元素
        // [1, 2, 3, 1]
        // 如果包含多个峰值，则任意返回一个，其实就是找到最大值
        // 找到一个 m nums[m] > nums[m-1] && nums[m] > nums[m+1]
        // 初始化
        int m,l = 0;
        int r = nums.size() - 1;
        // 不变的是 peak 在 [l,r]之间
        // 初始化, 满足条件 不变量
        // 保持
        // if m > m + 1, h = m, 去除 [m+1,h] 保留 [l,m], 去除的长度 h - m (h != m, l != h)
        // if m < m + 1, l = m+1, 此时去除 [l,m] 保留 [m+1,h] 去除的长度 m - l + 1，并且最大值也在 [m+1,h]中
        // if m == m + 1,
        // 终止
        while (l < r) {
            // [l,r]
            m = l + (r-l)/2;
            if (nums[m] > nums[m+1]) r = m; // 在左半边找
            else l = m + 1; // 在右半找
        }
        // 终止的 l = r
        // 此时对于 r 满足 r > r + 1
        // 对于 l 满足 l < l + 1
        return nums[l];
    }

    // 我们要分析题目的意思:
//    相邻位置的数字是不同的
//    A[0] < A[1] 并且 A[n - 2] > A[n - 1]
//    假定 P 是峰值的位置则满足 A[P] > A[P-1] 且 A[P] > A[P+1]，返回数组中任意一个峰值的位置。
    int findPeakElement_v2(vector<int>& nums) {
        int s = 1;
        int e = nums.size() - 1;

        if (e == 0){
            return 0;
        }

        while(s < e) {
            int m = s + (e-s)/2;
            if (nums[m]>nums[m-1] && nums[m] > nums[m+1]) return m;
            else if (nums[m-1] > nums[m]){
                // 表示左边有升序 maybe m-2 <?> m-1 > m
                e = m-1;
            }else { // nums[m] < nums[m+1]
                // maybe  m < m + 1 <?> m + 2
                s = m + 1;
            }
        }
        // 结束条件 s == e 或者 s < e
        // 但是此时我们不知道是 s or s -1
        return nums[s] > nums[s-1] ? s : s -1;
    }

    int findPeakElement_v3(vector<int>& A) {
        int l = 1, r = A.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;
            if (A[mid] > A[mid-1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;

    }


};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.findPeakElement_v2(nums) << endl;
    vector<int> nums2 = {1, 2, 3, 4,3,1,0};
    cout << s.findPeakElement_v2(nums2) << endl;

    vector<int> nums3 = {2,1};
    cout << s.findPeakElement_v2(nums3) << endl;

    vector<int> nums4 = {3,2,1};
    cout << s.findPeakElement_v2(nums4) << endl;
//    [2,1]
//    vector<int> nums2 = {1, 2, 3, 4,3,1,0};
//    cout << s.findPeakElement_v2(nums2) << endl;
}