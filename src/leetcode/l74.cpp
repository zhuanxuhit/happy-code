
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 编程语言,
// 抽象能力, 对于平时代码中的一个问题稍微深入下就不知道了
// 数据结构
// 算法掌握 二分不会写
// 系统知识 TCP为什么要有3次握手



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0){
            return false;
        }

        int column = matrix[0].size();

//        [
//        [1,   3,  5,  7],
//        [10, 11, 16, 20],
//        [23, 30, 34, 50]
//        ]
        // 矩阵排列的规则是 从左上角开始行递增，然后列也是增大的
        // [(0,0),(row,column)]
        // 都是闭区间
        int left = 0;
        int right = row * column - 1;
        while(left <= right){
            int m = left + (right - left) / 2;
            int temp_row = m / column;
            int temp_column = m % column;
            int value = matrix[temp_row][temp_column];
            if (value < target) {
                left = m + 1;
            }else if (value > target){
                right = m - 1;
            }else {
                return true;
            }
        }
        return false;
    }

    // 稍微优化下的版本
    bool searchMatrix_v2(vector<vector<int>>& matrix, int target) {
        // treat the matrix as an array, just taking care of indices
        // [0..n*m]
        // (row, col) -> row*n + col
        // i -> [i/n][i%n]
        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int e = matrix[mid/n][mid%n];
            if(target < e)
            {
                end = mid - 1;
            }
            else if(target > e)
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    // 二分的方法
    // 从左下角，大于它的肯定在右面，小于的肯定在上面
    bool searchMatrix_v3(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()){
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        // 左下角开始找
        for(int i=m-1,j=0;i>=0 &&  j<n;){
            if (matrix[i][j] < target) {
                j++;
            }else if (matrix[i][j] > target) {
                i--;
            }else {
                return true;
            }
        }
        return  false;
    }
    // 从右上角，小于的肯定在左边，大于的肯定在下面
};
int main() {
    vector<vector<int>> matrix = {
            {1,   3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50},
    };
    Solution s;
    cout << s.searchMatrix_v3(matrix,2) << endl;
    cout << s.searchMatrix_v3(matrix,34) << endl;
}