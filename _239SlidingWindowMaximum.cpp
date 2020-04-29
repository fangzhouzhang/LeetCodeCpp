//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (0 == nums.size()) return res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty()) {
                if (i - dq.front() >= k) {
                    dq.pop_front();
                }
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
