#include <iostream>
#include <string>
#include <vector>
//#include <map>
#include <unordered_map>

using namespace std;

class Solution {

public:
    bool dfs(int pos, int x, int y) {
        if (pos == word_.length()) {
            return true;
        }
        if (x >= board_.size() || x < 0 || y >= board_[0].size() || y < 0) {
            return false; // 越界了
        }

        if (visited_[x][y] == true) {
            return false;
        }

        // 需要知道哪些已经有了
        if (word_[pos] == board_[x][y]) {
            visited_[x][y] = true;
            if (dfs(pos + 1, x - 1, y) || dfs(pos + 1, x + 1, y) || dfs(pos + 1, x, y - 1) || dfs(pos + 1, x, y + 1)) {
                return true;
            }
            visited_[x][y] = false;
        }
        return false;
    }


    bool exist(vector<vector<char>> &board, string word) {
        word_ = word;
        board_ = board;
        visited_.resize(board.size());
        for (int i = 0; i < visited_.size(); i++) {
            visited_[i].resize(board[0].size());
            for (int j = 0; j < visited_[i].size(); j++) {
                visited_[i][j] = false;
            }
        }
        for (int i = 0; i < visited_.size(); i++) {
            for (int j = 0; j < visited_[0].size(); j++) {
                if (dfs(0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    vector<vector<char>> board_;
    vector<vector<bool>> visited_;
    string word_;
};

int main() {
    Solution s;
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'},
    };
    cout << s.exist(board,"ABCCED") << endl;
    cout << s.exist(board,"SEE") << endl;
    cout << s.exist(board,"ABCB") << endl;
}
