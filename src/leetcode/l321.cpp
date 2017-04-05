#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:

    bool str_greater(string &l, string &r) {
        if (l.size() != r.size()) {
            return l.size() > r.size();
        }
        for (int i=0;i<l.size();i++){
            if (l[i] == r[i]){
                continue;
            }else {
                return l[i] > r[i];
            }
        }
        return false;
    }

    string getMax(vector<vector<vector<string>>> &dp,int i, int j, int l,vector<int>& nums1, vector<int>& nums2){
//        if (dp[i][j][l]!=""){
//            return dp[i][j][l];
//        }

        string maxn = "";
        if (i > 0 ){
            string n1 = to_string(nums1[nums1.size() - i]) + dp[i-1][j][l-1];
            maxn = str_greater(n1,maxn) ? n1 : maxn;

            if (dp[i-1][j][l] != "") {
                string n2 = (dp[i-1][j][l]);
                maxn = str_greater(n2,maxn) ? n2 : maxn;
            }

        }
        if (j > 0) {
            string n1 = to_string(nums2[nums2.size() - j]) + dp[i][j-1][l-1];
            maxn = str_greater(n1,maxn)  ? n1 : maxn;
            if (dp[i][j-1][l] != ""){
                string n2 = (dp[i][j-1][l]);
                maxn = str_greater(n2,maxn) ? n2 : maxn;
            }

        }
        return  maxn;
    }
    // 超时了。囧
    // 复杂度
    vector<int> maxNumber_v1(vector<int>& nums1, vector<int>& nums2, int k) {
        // 思路就是dp
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<vector<string>>> dp(m+1,vector<vector<string>>(n+1,vector<string>(k+1,"")));
        // m*n*k // 会超时，怎么优化呢？
        for (int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for (int l=1;l<=k;l++){
//                    if (l == 0) {
//                        dp[i][j][l] = "";
//                    }
                    if (l> i + j){
                        dp[i][j][l] = "";
                    }
                    else {
                        dp[i][j][l] =  getMax(dp,i,j,l,nums1, nums2);
                    }
                }
            }
        }
        string num =  (dp[m][n][k]);
        vector<int> ans;
        for (auto i : num){
            ans.push_back(i - '0');
        }
        return ans;
    }


    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
        // 将两个队列合并，返回最大的
        vector<int> res;
        while (nums1.size() + nums2.size()) {
            vector<int> &tmp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }

    vector<int> maxVector(vector<int> nums, int k) {
        // 从nums中取出有序的k个最大数,还要保持有序
        // case nums = [3,4,6,5], k = 2
        int drop = nums.size() - k;
        vector<int> res;
        for (int n : nums){
            while (drop > 0 && res.size()>0 && res.back() < n){ // drop > 0,但是 res.back() > n 则此时还是会将数入队的
                res.pop_back();
                drop--;
            }
            res.push_back(n);
        }
        res.resize(k); // 这句必须加上，假设 k = 0, 如果不加就会有问题
        return res;
    }
    // 思路2
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // 思路1中超时特别严重，我们换一个思路，采取枚举的方法
        // 我们要k个数，那可能的场景是第一个最少取的数是： max(0,k-nums2.size())
        // 最多能取的数是 min(k, nums1.size())
        vector<int> res;
        for (int i=max(0,(int)(k-nums2.size()));i<=min(k, (int)nums1.size());i++){
            res = max(res, mergeVector(maxVector(nums1,i),maxVector(nums2,k-i)));
        }
        return res;
    }
};

int main () {
    // [2,5,6,4,4,0]
//    [7,3,8,0,6,5,7,6,2]
//    15
    // case
    // [6,7,5]
//    [4,8,1]
//    3
    Solution s;
    vector<int> nums1 = {6,7,5};
    vector<int> nums2 = {4,8,1};
    vector<int> ans = s.maxNumber(nums1,nums2,3);
    cout << "[";
    for (auto i : ans) {
        cout << i;
        cout << ",";
    }
    cout << "]" << endl; //[9, 8, 6, 5, 3]
}
