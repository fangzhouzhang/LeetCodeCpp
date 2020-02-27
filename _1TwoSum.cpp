//
// Created by Fangzhou Zhang on 2020/2/26.
//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                res[0] = map[target - nums[i]];
                res[1] = i;
                return res;
            } else map[nums[i]] = i;
        }
        return res;
    }
};
