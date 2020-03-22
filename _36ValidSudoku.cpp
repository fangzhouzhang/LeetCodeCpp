//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> subs(9, vector<bool>(10, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                if (rows[i][val] || cols[j][val] || subs[i / 3 * 3 + (j / 3)][val]) return false;
                rows[i][val] = true;
                cols[j][val] = true;
                subs[i / 3 * 3 + (j / 3)][val] = true;
            }
        }
        return true;
    }
};
