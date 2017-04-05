#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 求交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int m=nums1.size(), n = nums2.size();
        for(int i=0,j=0;i<m && j<n;){
            if (nums1[i] < nums2[j]) {
                i++;
            }else if (nums1[i] > nums2[j]){
                j++;
            }else {
                int num = nums1[i];
                res.push_back(num);
                while(i<m&&nums1[++i] == num){}
                while(j<n&&nums2[++j] == num){}
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {1,2};
    vector<int> ans = s.intersection(nums1,nums2);
    cout << "[";
    for (auto i : ans) {
        cout << i;
        cout << ",";
    }
    cout << "]" << endl; //[9, 8, 6, 5, 3]
}
