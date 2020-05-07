//
// Created by Fangzhou Zhang on 2020/5/6.
//
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || n == 1) return true;
        int min_len = INT_MAX;
        int slow = 0, fast = 0;
        while (slow < n && nums[slow] == 0) {
            slow++;
        }
        if (slow == n) return true;
        fast = slow + 1;
        while (fast < n) {
            if (nums[fast] == 0) fast++;
            else {
                if (min_len > fast - slow - 1) {
                    min_len = fast - slow - 1;
                    if (min_len < k) return false;
                }
                slow = fast;
                fast++;
            }
        }
        return true;
    }
};
