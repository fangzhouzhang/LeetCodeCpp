//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        if (nums[0] >= target) return 0;
        if (nums[nums.size() - 1] < target) return nums.size();
        if (nums[nums.size() - 1] == target) return nums.size() - 1;
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) start = mid;
            else end = mid;
        }
        if (nums[start] == target) return start;
        else return end;
    }
};
