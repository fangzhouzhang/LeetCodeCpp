//
// Created by Fangzhou Zhang on 2020/5/9.
//
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        string tmp;
        vector<int> dp(s.size(), -1);
        dfs(s, 0, tmp, set, res, dp);
        return res;
    }

    int dfs(string &s, int idx, string &tmp, unordered_set<string> &set, vector<string> &res, vector<int> &dp) {
        if (idx == s.size()) {
            res.push_back(tmp);
            return 1;
        }
        if (dp[idx] == 0) return 0;
        string cur;
        int prev = res.size();
        for (int i = idx; i < s.size(); i++) {
            cur.push_back(s[i]);
            if (set.count(cur) > 0) {
                string next = tmp.size() == 0 ? cur : tmp + " " + cur;
                dfs(s, i + 1, next, set, res, dp);
            }
        }
        if (res.size() == prev) {
            return dp[idx] = 0;
        } else {
            return dp[idx] = 1;
        }
    }
};
