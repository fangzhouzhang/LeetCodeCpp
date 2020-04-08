//
// Created by Fangzhou Zhang on 2020/4/8.
//
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        if (s1.size() + s2.size() != s3.size()) return false;
        return dfs(s1, 0, s2, 0, s3, 0, dp) == 1;
    }

    int dfs(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>> &dp) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int res = 0;
        if (i < s1.size() && s1[i] == s3[k]) res |= dfs(s1, i + 1, s2, j, s3, k + 1,dp);
        if (j < s2.size() && s2[j] == s3[k]) res |= dfs(s1, i, s2, j + 1, s3, k + 1,dp);
        if (res == 1) {
            return dp[i][j] = 1;
        } else return dp[i][j] = 0;
    }
};
