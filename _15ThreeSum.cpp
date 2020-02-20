//
// Created by Fangzhou Zhang on 2020/2/19.
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 2) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            twoSum(nums, i, 0 - nums[i], res);
        }
        return res;
    }

private:
    void twoSum(vector<int>& nums, int ans, int target, vector<vector<int>>& res) {
        int start = ans + 1, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                addRes(res, nums[ans], nums[start], nums[end]);
                start++;
                end--;
                while (start < end && nums[start - 1] == nums[start]) start++;
                while (start < end && nums[end + 1] == nums[end]) end--;
            } else if (nums[start] + nums[end] < target) {
                start++;
            } else end--;
        }
    }

    void addRes(vector<vector<int>>& res, int i, int j, int k) {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(j);
        tmp.push_back(k);
        res.push_back(tmp);
    }
};
