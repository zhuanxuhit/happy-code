#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // 最少是需要1血量
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        if (row == 0) {
            return 1;
        }
        int column = dungeon[0].size();

        vector<vector<int>> dp(row,vector<int>(column,0));
        dp[row-1][column-1] = 1;
        for (int i=row-2; i>=0;i--){
            dp[i][column-1] = max(1,dp[i+1][column-1] - dungeon[i+1][column-1]);
        }
        for (int i=column-2;i>=0;i--){
            dp[row-1][i] = max(1,dp[row-1][i+1] - dungeon[row-1][i+1]);
        }

        for (int i=row-2;i>=0;i--) {
            for (int j=column-2;j>=0;j--){
                dp[i][j] = max(1,min(dp[i+1][j]-dungeon[i+1][j],dp[i][j+1]-dungeon[i][j+1]));
            }
        }
        return max(1,dp[0][0]-dungeon[0][0]);
    }
};

int main() {
    vector<vector<int>> dungeon1 = {
            {-3},{-7}
    };
    Solution s;
    cout << s.calculateMinimumHP(dungeon1) << endl;
}