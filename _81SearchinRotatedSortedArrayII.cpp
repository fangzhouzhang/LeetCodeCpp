//
// Created by Fangzhou Zhang on 2020/4/3.
//
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] > nums[start]) {
                if (nums[mid] > target && target >= nums[start]) end = mid - 1;
                else start = mid + 1;
            } else if (nums[mid] < nums[start]) {
                if (nums[mid] < target && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            } else {
                start++;
            }
        }
        return false;
    }
};
