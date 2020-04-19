//
// Created by Fangzhou Zhang on 2020/4/18.
//
class Solution {
public:
    int M = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return dfs(s, 0, k, dp);
    }

    int dfs(string &s, int idx, int k, vector<int> &dp) {
        if (idx == s.size()) return 1;
        long val = 0;int res = 0;
        if (s[idx] == '0') return 0;
        if (dp[idx] != -1) return dp[idx];
        for (int i = idx; i < s.size(); i++) {
            val = (val * 10 + s[i] - '0');
            if (val > k) break;
            if (0 < val && val <= k) {
                res = (res + dfs(s, i + 1, k, dp)) % M;
            }
        }
        return dp[idx] = res;
    }
};
