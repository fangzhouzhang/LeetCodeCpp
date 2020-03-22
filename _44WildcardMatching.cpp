//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        function<int(int, int)> dfs = [&](int idxs, int idxp){
            if (idxp == p.size() && idxs == s.size()) {
                return 1;
            }
            if (idxp == p.size()) {
                return 0;
            }

            if (idxs == s.size()) {
                while (idxp < p.size()) {
                    if (p[idxp] != '*') return 0;
                    idxp++;
                }
                return 1;
            }
            if (dp[idxs][idxp] != -1) return dp[idxs][idxp];
            int ret = 0;
            if (s[idxs] == p[idxp] || p[idxp] == '?') {
                ret = dfs(idxs + 1, idxp + 1);
            }

            if (p[idxp] == '*') {
                ret =  dfs(idxs + 1, idxp + 1) || dfs(idxs, idxp + 1) ||dfs(idxs + 1, idxp);
            }

            return dp[idxs][idxp] = ret;
        };
        return dfs(0, 0);
    }
};
