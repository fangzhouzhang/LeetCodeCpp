//
// Created by Fangzhou Zhang on 2020/4/8.
//
class Solution {
public:
    int numTrees(int n) {
        if (0 == n) return 0;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int res = 0;
        return dfs(dp, 1, n);
    }

    int dfs(vector<vector<int>> &dp, int start, int end) {
        if (start >= end) return 1;

        if (dp[start][end] != -1) return dp[start][end];

        int cnt = 0;
        for (int i = start; i <= end; i++) {
            int l = dfs(dp, start, i - 1);
            int r = dfs(dp, i + 1, end);
            cnt += l * r;
        }
        return dp[start][end] = cnt;
    }
};
