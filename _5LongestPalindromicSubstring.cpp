//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = 1, start = 0, end = 0;
        for (int offset = 0; offset < n; offset++) {
            for (int i = 0; offset + i < n; i++) {
                if (offset == 0) {
                    dp[i][i + offset] = 1;
                }
                else if (offset == 1) {
                    dp[i][i + offset] = (s[i] == s[i + offset]) ? 1 : 0;
                } else {
                    if (s[i] == s[i + offset]) {
                        dp[i][i + offset] = dp[i + 1][i + offset - 1];
                    } else {
                        dp[i][i + offset] = 0;
                    }
                }
                if (dp[i][i + offset] == 1 && offset + 1 > res) {
                    res = offset + 1;
                    start = i;
                    end = i + offset;
                }
            }
        }
        return s.substr(start, res);
    }
};
