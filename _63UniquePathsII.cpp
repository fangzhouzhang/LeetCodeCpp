//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int x, int y){
            if (x == m - 1 && y == n - 1 && obstacleGrid[x][y] == 0) {
                dp[x][y] = 1;
                return 1;
            }

            if (dp[x][y] != -1) return dp[x][y];

            int res = 0;
            if (x + 1 >= 0 && x + 1 < m && obstacleGrid[x + 1][y] == 0) res += dfs(x + 1, y);
            if (y + 1 >= 0 && y + 1 < n && obstacleGrid[x][y + 1] == 0) res += dfs(x, y + 1);

            return dp[x][y] = res;
        };
        return dfs(0, 0);
    }
};
