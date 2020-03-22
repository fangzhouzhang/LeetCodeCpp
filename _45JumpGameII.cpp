//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        int n = nums.size();
        int t = n - 1;//t means target
        dp[t] = 0;

        for (int i = n - 2; i >= 0; i--) {
            int min_step = INT_MAX;
            for (int step = nums[i]; step >= 1; step--) {
                if (i + step <= t && dp[i + step] != INT_MAX) {
                    min_step = min(min_step, dp[i + step] + 1);
                } else if (i + step > t) min_step = 1;
            }
            dp[i] = min_step;
        }
        return dp[0];
    }
};
