//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size(), -1));
        function<int(int, int)> dfs = [&](int idxs, int idxp){
            if (idxp == p.size()) {
                return idxs == s.size() ? 1 : 0;
            }
            if (dp[idxs][idxp] != -1) return dp[idxs][idxp];
            int res;
            //cur char in p is a-z
            int first_match = (idxs < s.size()) && (s[idxs] == p[idxp] || p[idxp] == '.');
            if (idxp + 1 < p.size() && p[idxp + 1] == '*') {
                res = dfs(idxs, idxp + 2) || (first_match && dfs(idxs + 1, idxp));
            } else {
                res = (first_match && dfs(idxs + 1, idxp + 1));
            }
            return dp[idxs][idxp] = res;
        };
        return dfs(0, 0) == 1;
    }
};
