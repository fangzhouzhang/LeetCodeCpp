//
// Created by Fangzhou Zhang on 2020/4/30.
//
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (0 == rows) return;
        int cols = board[0].size();
        unordered_set<int> connects;
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') {
                findConnect(board, 0, i, connects);
            }
            if (board[rows - 1][i] == 'O') {
                findConnect(board, rows - 1, i, connects);
            }
        }

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                findConnect(board, i, 0, connects);
            }
            if (board[i][cols - 1] == 'O') {
                findConnect(board, i, cols - 1, connects);
            }
        }
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (board[i][j] == 'O' && connects.find(i * cols + j) == connects.end()) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void findConnect(vector<vector<char>>& board, int row, int col, unordered_set<int> &connects) {
        if (connects.find(row * board[row].size() + col) != connects.end()) return;
        connects.insert(row * board[row].size() + col);
        for (vector<int> dir : dirs) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if (new_row < 0 || new_row >= board.size() || new_col < 0 || new_col >= board[new_row].size()) continue;
            if (board[new_row][new_col] == 'X') continue;
            findConnect(board, new_row, new_col, connects);
        }
    }
};
