//
// Created by Fangzhou Zhang on 2020/4/18.
//
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return dfs(s, 0, t, 0, dp);
    }

    int dfs(string s, int idxs, string t, int idxt, vector<vector<int>> &dp) {
        if (idxt == t.size()) return 1;
        if (idxs == s.size()) {
            if (idxt == t.size()) return 1;
            return 0;
        }

        if (dp[idxs][idxt] != -1) return dp[idxs][idxt];
        int sum = 0;
        sum += dfs(s, idxs + 1, t, idxt, dp);
        if (s[idxs] == t[idxt]) sum += dfs(s, idxs + 1, t, idxt + 1, dp);
        return dp[idxs][idxt] = sum;
    }
};
