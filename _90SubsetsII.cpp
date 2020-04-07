//
// Created by Fangzhou Zhang on 2020/4/7.
//
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        if (nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, res, tmp);
        return res;
    }

    void dfs(vector<int>& nums, int idx, vector<vector<int>> &res, vector<int>& tmp) {
        if (idx == nums.size()) {
            res.push_back(tmp);
            return;
        }

        tmp.push_back(nums[idx]);
        dfs(nums, idx + 1, res, tmp);
        tmp.pop_back();

        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) idx++;
        dfs(nums, idx + 1, res, tmp);
    }
};

