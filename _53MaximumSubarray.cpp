//
// Created by Fangzhou Zhang on 2020/3/25.
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> prefix(nums.size() + 1, 0);
        int sum = 0;
        for (int i = 1; i < prefix.size(); i++) {
            sum += nums[i - 1];
            prefix[i] = sum;
        }

        int res = INT_MIN;
        for (int i = 0; i < prefix.size() - 1; i++) {
            for (int j = i + 1; j < prefix.size(); j++) {
                res = max(res, prefix[j] - prefix[i]);
            }
        }
        return res;
    }
};
