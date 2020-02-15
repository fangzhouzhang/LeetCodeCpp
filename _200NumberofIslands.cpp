//
// Created by Fangzhou Zhang on 2020/2/15.
//
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (grid[r][c] != '1') return;
        grid[r][c] = '0';
        for (auto dir : dirs) {
            int new_row = r + dir[0];
            int new_col = c + dir[1];
            if (isValid(grid, new_row, new_col)) {
                dfs(grid, new_row, new_col);
            }
        }
    }

    bool isValid(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size()) return false;
        if (c < 0 || c >= grid[r].size()) return false;
        return true;
    }
};
