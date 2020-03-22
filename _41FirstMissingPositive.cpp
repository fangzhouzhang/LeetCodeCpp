//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        int idx = 0,n = nums.size();
        while (idx < n) {
            long pos = (long)nums[idx] - 1;
            if (pos == idx) {
                idx++;
                continue;
            } else {
                if (pos >= 0 && pos < n && nums[pos] != pos + 1) {
                    swap(nums[pos], nums[idx]);
                } else {
                    idx++;
                    continue;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
