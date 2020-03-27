//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int x, int y){
            if (x == m - 1 && y == n - 1) {
                dp[x][y] = 1;
                return 1;
            }

            if (dp[x][y] != -1) return dp[x][y];

            int res = 0;
            if (x + 1 >= 0 && x + 1 < m) res += dfs(x + 1, y);
            if (y + 1 >= 0 && y + 1 < n) res += dfs(x, y + 1);

            return dp[x][y] = res;
        };
        return dfs(0, 0);
    }
};
