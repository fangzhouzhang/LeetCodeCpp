//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};
