//
// Created by Fangzhou Zhang on 2020/4/2.
//
class Solution {
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (board.size() == 0 || board[0].size() == 0) return false;
        function<bool(int, int, int)> dfs = [&](int r, int c, int idx) {
            if (idx == word.size()) return true;
            if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size()) return false;
            if (word[idx] != board[r][c]) return false;
            char tmp = board[r][c];
            board[r][c] = '#';
            for (auto dir : dirs) {
                int new_r = dir[0] + r;
                int new_c = dir[1] + c;
                if (dfs(new_r, new_c, idx + 1)) return true;
            }
            board[r][c] = tmp;
            return false;
        };
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
