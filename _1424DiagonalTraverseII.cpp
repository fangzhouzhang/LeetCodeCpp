//
// Created by Fangzhou Zhang on 2020/4/26.
//
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        int rows = nums.size();
        int maxKey = 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                map[i + j].push_back(nums[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }

        for (int i = 0; i <= maxKey; i++) {
            vector<int> &cur = map[i];
            res.insert(res.end(), cur.rbegin(), cur.rend());
        }
        return res;
    }
};
