//
// Created by Fangzhou Zhang on 2020/5/5.
//
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if (0 == n) return false;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return dfs(s, 0, set, dp) == 1;
    }

    int dfs(string &s, int idx, unordered_set<string> &set, vector<int> &dp) {
        if (s.size() == idx) return 1;

        if (dp[idx] != -1) return dp[idx];
        for (int i = idx; i < s.size(); i++) {
            string cur = s.substr(idx, i - idx + 1);
            if (set.count(cur) > 0) {
                if (dfs(s, i + 1, set, dp) > 0) {
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
};
