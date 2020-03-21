//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int slow = 1, fast = 1;
        while (fast < nums.size()) {
            if (nums[fast] == nums[slow - 1]) fast++;
            else nums[slow++] = nums[fast++];
        }
        return slow;
    }
};
