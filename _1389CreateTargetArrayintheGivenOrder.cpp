//
// Created by Fangzhou Zhang on 2020/5/12.
//
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for (int i = 0; i < index.size(); i++) {
            if (index[i] == res.size()) res.push_back(nums[i]);
            else res.insert(index[i] + res.begin(), nums[i]);
        }
        return res;
    }
};
