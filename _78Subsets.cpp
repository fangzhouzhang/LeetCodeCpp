//
// Created by Fangzhou Zhang on 2020/4/1.
//
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        if (nums.size() == 0) return res;
        function<void(int)> dfs = [&](int idx) {
            if (idx == nums.size()) {
                res.push_back(tmp);
                return;
            }

            tmp.push_back(nums[idx]);
            dfs(idx + 1);
            tmp.pop_back();

            dfs(idx + 1);
        };
        dfs(0);
        return res;
    }
};
