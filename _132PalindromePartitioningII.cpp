//
// Created by Fangzhou Zhang on 2020/5/2.
//
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(s, 0, 0, dp);
    }

    int dfs(string &s, int pre, int cur, vector<vector<int>> &dp) {
        if (cur == s.size()) {
            if (pre == s.size()) return 0;
            return INT_MAX;
        }
        if (dp[pre][cur] != -1) return dp[pre][cur];
        int res = INT_MAX;
        int val = dfs(s, pre, cur + 1, dp);
        if (INT_MAX != val) res = min(res, val);

        if (is_palin(s, pre, cur)) {
            int val_2 = dfs(s, cur + 1, cur + 1, dp);
            if (INT_MAX != val_2) {
                if (s.size() - 1 != cur) res = min(res, val_2 + 1);
                else res = min(res, val_2);
            }
        }
        return dp[pre][cur] = res;
    }

    bool is_palin(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
