//
// Created by Fangzhou Zhang on 2020/3/1.
//
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                if (nums[i] > nums[j]) sum++;
            }
            res[i] = sum;
        }
        return res;
    }
};
