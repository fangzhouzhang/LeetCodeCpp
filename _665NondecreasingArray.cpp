//
// Created by Fangzhou Zhang on 2020/5/16.
//
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (0 == n || 1 == n) return true;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                cnt++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i]) nums[i - 1] = nums[i];
                else nums[i] = nums[i - 1];
            }
        }
        return cnt <= 1;
    }
};
