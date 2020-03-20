//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0) return res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            while (dq.size() > 0 && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            if (dq.size() == 0 || nums[dq.back()] >= nums[i]) dq.push_back(i);
            if (i + 1 - k >= 0) {
                res.push_back(nums[dq.front()]);
                if (dq.size() > 0 && dq.front() <= i + 1 - k) dq.pop_front();
            }
        }
        return res;
    }
};
