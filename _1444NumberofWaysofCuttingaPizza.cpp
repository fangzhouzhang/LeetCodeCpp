//
// Created by Fangzhou Zhang on 2020/5/12.
//
class Solution {
public:
    int M = 1e9 + 7;
    int rows = 0;
    int cols = 0;
    int ways(vector<string>& pizza, int k) {
        if (0 == pizza.size()) return 0;
        rows = pizza.size();
        cols = pizza[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        k--;
        return dfs(pizza, 0, 0, k, dp);
    }

    int dfs(vector<string>& p, int row, int col, int k, vector<vector<vector<int>>> &dp) {
        if (k == 0) {
            //check remaining
            if (check(p, row, col, rows - 1, cols - 1)) return 1;
            else return INT_MIN;
        }
        if (dp[row][col][k] != -1) return dp[row][col][k];
        int res = 0;
        //horizon
        for (int i = col; i < cols - 1; i++) {
            if (check(p, row, col, rows - 1, i)) {
                int ret = dfs(p, row, i + 1, k - 1, dp);
                if (ret != INT_MIN) {
                    res = (res + ret) % M;
                }
            }
        }

        //vertical
        for (int i = row; i < rows - 1; i++) {
            if (check(p, row, col, i, cols - 1)) {
                int ret = dfs(p, i + 1, col, k - 1, dp);
                if (ret != INT_MIN) {
                    res = (res + ret) % M;
                }
            }
        }

        return dp[row][col][k] = res;
    }

    bool check(vector<string>& p, int s_r, int s_c, int e_r, int e_c) {
        for (int i = s_r; i <= e_r; i++) {
            for (int j = s_c; j <= e_c; j++) {
                if (p[i][j] == 'A') return true;
            }
        }
        return false;
    }
};
