//
// Created by Fangzhou Zhang on 2020/5/16.
//
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (flights[i][j] == 1) {
                    g[i].push_back(j);
                }
            }
            g[i].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(k, -1));
        return dfs(g, days, 0, 0, dp);
    }

    int dfs(vector<vector<int>> &g, vector<vector<int>>& days, int flight, int idx, vector<vector<int>> &dp) {
        if (days[0].size() == idx) return 0;
        if (-1 != dp[flight][idx]) return dp[flight][idx];
        int res = INT_MIN;
        if (idx == 0) {
            for (int f : g[0]) {
                res = max(res, dfs(g, days, f, idx + 1, dp) + days[0][0]);
                for (int x : g[f]) {
                    res = max(res, dfs(g, days, x, idx + 1, dp) + days[f][0]);
                }
            }
        } else {
            for (int f : g[flight]) {
                res = max(res, dfs(g, days, f, idx + 1, dp) + days[flight][idx]);
            }
        }
        return dp[flight][idx] = res;
    }
};
