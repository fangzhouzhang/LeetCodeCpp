//
// Created by Fangzhou Zhang on 2020/4/2.
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int left = 2, right = 2;
        while (right < nums.size()) {
            if (nums[right] == nums[left - 2]) right++;
            else nums[left++] = nums[right++];
        }
        return left;
    }
};
