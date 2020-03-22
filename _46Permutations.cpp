//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;

        if (nums.size() == 0) return res;
        function<void(int)> dfs = [&](int idx){
            if (idx == nums.size()) {
                res.push_back(tmp);
                return;
            }

            for (int i = idx; i < nums.size(); i++) {
                swap(nums[i], nums[idx]);
                tmp.push_back(nums[idx]);
                dfs(idx + 1);
                tmp.pop_back();
                swap(nums[i], nums[idx]);
            }
        };
        dfs(0);
        return res;
    }
};
