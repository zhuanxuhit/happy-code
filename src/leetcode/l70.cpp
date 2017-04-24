#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 超时了
        // dp[n] = dp[n-1] + dp[n-2]
//        int dp[n] = {0};
        vector<int> dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i=2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
//        if (n==1){
//            return 1;
//        }else if (n==2){
//            return 2;
//        }else{
//            return climbStairs(n-1) + climbStairs(n-2);
//        }
    }
};

int main () {
    Solution s;
}
