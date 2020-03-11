//
// Created by Fangzhou Zhang on 2020/3/10.
//
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*

            23551
            25135
        */
        int end = nums.size() - 1;
        bool appear = false;
        while (end > 0 && nums[end - 1] >= nums[end]) end--;
        if (end > 0 && (nums[end - 1] < nums[end])) {
            int target = nums[end - 1];
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > target) {
                    swap(nums, i, end - 1);
                    int k = end, m = nums.size() - 1;
                    while (k < m) {
                        swap(nums, k++, m--);
                    }
                    return;
                }
            }
        } else {
            //reverse all numbers
            int k = 0, m = nums.size() - 1;
            while (k < m) {
                swap(nums, k++, m--);
            }
            return;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
