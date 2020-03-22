//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        if (candidates.size() == 0) return res;
        function<void(int, int)> dfs = [&](int idx, int remain){
            if (remain == 0 && idx <= candidates.size()) {
                res.push_back(tmp);
                return;
            }
            if (idx == candidates.size() || remain == 0) {
                return;
            }

            for (int k = 0; remain - candidates[idx] * k >= 0; k++) {
                for (int j = 0; j < k; j++) tmp.push_back(candidates[idx]);
                dfs(idx + 1, remain - candidates[idx] * k);
                for (int j = 0; j < k; j++)  tmp.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};
