//
// Created by Fangzhou Zhang on 2020/4/5.
//
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        if (stoneValue.size() == 0) return "Tie";
        vector<int> dp(stoneValue.size(), -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx == stoneValue.size()) return 0;
            if (dp[idx] != -1) return dp[idx];
            int cur_max = INT_MIN, sum = 0;
            for (int i = 0; i < 3 && idx + i < stoneValue.size(); i++) {
                sum += stoneValue[idx + i];
                cur_max = max(cur_max, sum - dfs(idx + i + 1));
            }
            return dp[idx] = cur_max;
        };
        int ret = dfs(0);
        if (ret > 0) return "Alice";
        else if (ret == 0) return "Tie";
        return "Bob";
    }
};
