//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int x, int y){
            if (x == m - 1 && y == n - 1) {
                return grid[x][y];
            }

            if (dp[x][y] != -1) return dp[x][y];

            int res = INT_MAX;
            if (x + 1 >= 0 && x + 1 < m) res = min(res, dfs(x + 1, y) + grid[x][y]);
            if (y + 1 >= 0 && y + 1 < n) res = min(res, dfs(x, y + 1) + grid[x][y]);

            return dp[x][y] = res;
        };
        return dfs(0, 0);
    }
};
