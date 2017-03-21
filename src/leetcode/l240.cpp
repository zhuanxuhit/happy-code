
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
//    [
//    [1,   4,  7, 11, 15],
//    [2,   5,  8, 12, 19],
//    [3,   6,  9, 16, 22],
//    [10, 13, 14, 17, 24],
//    [18, 21, 23, 26, 30]
//    ]
    // 二分的方法
    // 从左下角，大于它的肯定在右面，小于的肯定在上面
    bool searchMatrix_v3(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        // 左下角开始找
        for (int i = m - 1, j = 0; i >= 0 && j < n;) {
            if (matrix[i][j] < target) {
                j++;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                return true;
            }
        }
        return false;
    }
    // 从右上角，小于的肯定在左边，大于的肯定在下面
};

int main() {
    vector<vector<int>> matrix = {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    Solution s;
    cout << s.searchMatrix_v3(matrix, 5) << endl;
    cout << s.searchMatrix_v3(matrix, 20) << endl;
}