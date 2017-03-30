#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // prices 是股票价格，
    // Say you have an array for which the ith element is the price of a given stock on day i.
    // 我们只有卖出了才能再买入,然后得出最大利润
    int maxProfit(vector<int>& prices) {
        if (prices.empty()){
            return 0;
        }
        // 动态规划的推导
        int size = (int) prices.size();
        vector<vector<int>> dp(2,vector<int>(size+1,0));
//        vector<vector<int>> dp;
        // 0 买，1卖
//        dp[0][0] = 0;
//        dp[1][0] = 0;
        for(int i=1;i<=size;i++){
            int decision = prices[size-i];
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]-decision);
            dp[1][i] = max(dp[0][i-1]+decision,dp[1][i-1]);
        }
        return dp[0][size];
    }
};

int main () {
    Solution s;
//    vector<int> prices = {1,4,9,2,7,3};
    vector<int> prices = {3,2,6,5,0,3};

    cout << s.maxProfit(prices) << endl;
}
