//
// Created by Fangzhou Zhang on 2020/4/5.
//
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        sort(nums.begin(), nums.end(), greater());
        int sum = 0;
        for (int a : nums) sum += a;
        int k = 0;
        for (int a : nums) {
            res.push_back(a);
            k += a;
            if (k > sum / 2) return res;
        }
        return res;
    }
};
