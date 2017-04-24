#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
//    Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
//    The distance between two adjacent cells is 1.

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) {
            return vector<vector<int>>{};
        }
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        // 找到为0的点,并设置0周围的点正确
        vector<pair<int, int>> bfs;
//        bool cond = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0;
                    bfs.push_back(make_pair(i, j));
                }
            }
        }
        int depth = 0;
        while (!bfs.empty()) {
            vector<pair<int, int>> bfs_temp;
            depth++;
            for (auto p : bfs) {
                int i = p.first;
                int j = p.second;
                if (i > 0 && ans[i - 1][j] == -1) { // 上
                    ans[i - 1][j] = depth;
                    bfs_temp.push_back(make_pair(i - 1, j));
                }
                if (i < m - 1 && ans[i + 1][j] == -1) { // 下
                    ans[i + 1][j] = depth;
                    bfs_temp.push_back(make_pair(i + 1, j));
                }
                if (j > 0 && ans[i][j - 1] == -1) {// 左
                    ans[i][j - 1] = depth;
                    bfs_temp.push_back(make_pair(i, j - 1));
                }
                if (j < n - 1 && ans[i][j + 1] == -1) {// 右
                    ans[i][j + 1] = depth;
                    bfs_temp.push_back(make_pair(i, j + 1));
                }
            }
            bfs.swap(bfs_temp);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                                  {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
                                  {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                                  {1,
                                      0,
                                         1,
                                            0,
                                               1,
                                                  1,
                                                     1,
                                                        1,
                                                           1,
                                                              1},
                                  {0,
                                      1,
                                         0,
                                            1,
                                               1,
                                                  0,
                                                     0,
                                                        0,
                                                           0,
                                                              1},
                                  {0,
                                      0,
                                         1,
                                            0,
                                               1,
                                                  1,
                                                     1,
                                                        0,
                                                           1,
                                                              0},
                                  {0,
                                      1,
                                         0,
                                            1,
                                               0,
                                                  1,
                                                     0,
                                                        0,
                                                           1,
                                                              1},
                                  {1,
                                      0,
                                         0,
                                            0,
                                               1,
                                                  1,
                                                     1,
                                                        1,
                                                           0,
                                                              1},
                                  {1,
                                      1,
                                         1,
                                            1,
                                               1,
                                                  1,
                                                     1,
                                                        0,
                                                           1,
                                                              0},
                                  {1,
                                      1,
                                         1,
                                            1,
                                               0,
                                                  1,
                                                     0,
                                                        0,
                                                           1,
                                                              1}};
    auto ans = s.updateMatrix(matrix);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
}
