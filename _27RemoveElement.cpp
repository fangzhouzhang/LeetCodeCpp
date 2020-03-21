//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] == val) r++;
            else swap(nums[l++], nums[r++]);
        }
        return l;
    }
};
