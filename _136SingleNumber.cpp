//
// Created by Fangzhou Zhang on 2020/5/4.
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (0 == nums.size()) return 0;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur ^= nums[i];
        }
        return cur;
    }
};
