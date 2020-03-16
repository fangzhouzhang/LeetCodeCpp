//
// Created by Fangzhou Zhang on 2020/3/16.
//
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(vector<int>&, int, int)> quick_partition = [&](vector<int> &nums, int start, int end){
            if (start >= end) return;
            int left = start;
            int right = end;
            int pivot = nums[start];
            int p_idx = start;
            start++;
            while (start <= end) {
                while (start <= end && nums[start] < pivot) start++;
                while (start <= end && nums[end] > pivot) end--;
                if (start <= end) {
                    int tmp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = tmp;
                    start++;
                    end--;
                }
            }
            int tmp = nums[p_idx];
            nums[p_idx] = nums[end];
            nums[end] = tmp;
            quick_partition(nums, left, end - 1);
            quick_partition(nums, start, right);
        };
        quick_partition(nums, 0, nums.size() - 1);
        return nums;
    }
};
