#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // 输入：
//    X X X X
//    X O O X
//    X X O X
//    X O X X
// 输出：
//    X X X X
//    X X X X
//    X X X X
//    X O X X
    bool bfs(vector<vector<char>>& board, int i, int j,map<pair<int,int>,bool> &visited){
        if (i <= 0 || i>=(board.size()-1) || j<=0 || j >= (board[0].size() -1)) {
            return false;
        }
//        if ( visited.find(make_pair(i,j)) != visited.end() ){
//        }
        visited[make_pair(i,j)] = true;
        // 判断4个角落是否都是
        bool ret = true;
        vector<vector<int>> directions = {
                {i,j-1},
                {i,j+1},
                {i-1,j},
                {i+1,j},
        };
        int d = 0;
        while (ret && d < 4){
            int d1 = directions[d][0];
            int d2 = directions[d][1];
            if (board[d1][d2] == 'O' && visited.find(make_pair(d1,d2)) == visited.end() ){
                ret = bfs(board,d1,d2,visited);
            }
            d++;
        }
        return ret;
    }

    void solve_1(vector<vector<char>>& board) {
        // 要被包围的，O 转换为 X
        int m = board.size();
        if (m<=0){
            return;
        }
        // 这样子做会超时，因为我们找寻的是所有O，我们可以换个思路
        // 当我们遇到在矩阵4边上的O的时候，肯定是不行的
        // 于是我们就换做找边上的连通域

        int n = board[0].size();
        // runtime error.
        for (int i=1;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j] == 'O'){
                    // 开始深度搜索
                    map<pair<int,int>,bool> visited;
                    if (bfs(board,i,j,visited)) {
                        // 对于visited的数进行
                        for (auto v : visited){
                            board[v.first.first][v.first.second] = 'X';
                        }
                    }
                }
            }
        }
    }



    void solve(vector<vector<char> >& board) {
        // 要被包围的，O 转换为 X
        int m = board.size();
        if (m<=0){
            return;
        }
        // 这样子做会超时，因为我们找寻的是所有O，我们可以换个思路
        // 当我们遇到在矩阵4边上的O的时候，肯定是不行的
        // 于是我们就换做找边上的连通域

        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                    solveDFS(board, i, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void solveDFS(vector<vector<char> > &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O')
                solveDFS(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O')
                solveDFS(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                solveDFS(board, i + 1, j);
            if (j > 1 && board[i][j - 1] == 'O')
                solveDFS(board, i, j - 1);
        }
    }
};

int main () {
    Solution s;
    vector<vector<char>> board = {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
    };
    s.solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}
