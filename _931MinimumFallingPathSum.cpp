//
// Created by Fangzhou Zhang on 2020/2/29.
//
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp(A.size(), vector<int> (A.size(), INT_MAX));
        int res = INT_MAX;
        for (int j = 0; j < A[0].size(); j++) {
            res = min(res, dfs(A, 0, j, dp));
        }
        return res;
    }

    int dfs(vector<vector<int>>& A, int row, int col, vector<vector<int>>& dp) {
        if (row == A.size()) return 0;
        if (dp[row][col] != INT_MAX)  return dp[row][col];
        int ret = INT_MAX;
        if (col - 1 >= 0) ret = min(dfs(A, row + 1, col - 1, dp), ret);
        ret = min(dfs(A, row + 1, col, dp), ret);
        if (col + 1 < A.size()) ret = min(dfs(A, row + 1, col + 1, dp), ret);
        dp[row][col] = ret + A[row][col];
        return dp[row][col];
    }
};
