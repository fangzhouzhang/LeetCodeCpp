//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> subs(9, vector<bool>(10, false));
        vector<int> vec;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    vec.push_back(i * 9 + j);
                    continue;
                }
                int val = board[i][j] - '0';
                rows[i][val] = true;
                cols[j][val] = true;
                subs[i / 3 * 3 + (j / 3)][val] = true;
            }
        }
        function<bool(int)> dfs = [&](int idx){
            if (idx == vec.size()) return true;
            int i = vec[idx] / 9;
            int j = vec[idx] % 9;
            for (int k = 1; k < 10; k++) {
                if (rows[i][k] || cols[j][k] || subs[i / 3 * 3 + (j / 3)][k]) continue;
                rows[i][k] = true;
                cols[j][k] = true;
                subs[i / 3 * 3 + (j / 3)][k] = true;
                if (dfs(idx + 1)) {
                    board[i][j] = (char)(k + '0');
                    return true;
                } else {
                    rows[i][k] = false;
                    cols[j][k] = false;
                    subs[i / 3 * 3 + (j / 3)][k] = false;
                }
            }
            return false;
        };
        dfs(0);
    }
};
