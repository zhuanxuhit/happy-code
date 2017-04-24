#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // 由于线性时间，想到的职能是桶排序或者基排序了
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1){
            return 0;
        }

        auto minmax = minmax_element(nums.begin(),nums.end());
        int minn  = *minmax.first;
        int maxn  = *minmax.second;
        // 现在我们有 max - min 区间，里面会有n个元素，那如果我们将其划分为n-1个区间，则必然会有2个元素在一个区间
        // 现在我们将元素分到具体的区间中去，此时区间之间的差值肯定小于 max-min / (n-1)
        // 如果所有元素之间的差值都小于  max-min / (n-1) ， 那肯定不可能会有 max-min 这么多差距
        // 所以必然不同区间的元素差距会大于  max-min / (n-1) , 于是找最大差距就从 区间的min - 前一个区间的max 就可以了。
        // 此处 bucket_len 和 bucket_size 的选择非常重要
        // case:1,1,1,1
        // case:1,100000
//        int bucket_len = floor((maxn- minn) / (nums.size() -1) + 1); // 希望最小是1，不能是0
//        int bucket_size = floor((maxn-minn)/bucket_len + 1);
        int bucket_len = max( (int)((maxn- minn) / (nums.size()-1)) , 1); // 希望最小是1，不能是0
        int bucket_size = (maxn-minn)/bucket_len + 1;
        cout << "bucket_len:"<<bucket_len << " bucket_size:" << bucket_size << endl;
        vector<int> bucket_max = vector<int>(bucket_size,INT_MIN);
        vector<int> bucket_min = vector<int>(bucket_size,INT_MAX);
        for(auto n : nums){
            int bucket = (n - minn) / bucket_len;
            bucket_max[bucket] = max(bucket_max[bucket], n);
            bucket_min[bucket] = min(bucket_min[bucket], n);
        }
        // 找出最大间隔
        int ans = INT_MIN;
        int previous = minn;
        for (int i=0;i<bucket_size;i++){
            if (bucket_max[i] == INT_MIN ) {
                continue;
            }
            ans = max(ans, bucket_min[i] - previous);
            previous = bucket_max[i];
        }
        return ans;
    }
};

int main () {
    Solution s;
//    vector<int> nums = {1,1,1,1};
    vector<int> nums = {1,100000};
    cout << s.maximumGap(nums) << endl;
}
