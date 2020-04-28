//
// Created by Fangzhou Zhang on 2020/4/28.
//
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        if (0 == n) return 0;
        if (1 == n) return nums[0];
        int res = nums[0];
        deque<pair<int,int>> dq;
        dq.push_front(make_pair(0,nums[0]));
        for (int i = 1; i < n; i++) {
            if (!dq.empty()) {
                if (i - dq.front().first > k) {
                    dq.pop_front();
                }
            }
            if (!dq.empty()) {
                int cur_val = max(0, dq.front().second) + nums[i];
                res = max(res, cur_val);
                if (!dq.empty() && dq.front().second < cur_val) {
                    dq.pop_front();
                    dq.push_front(make_pair(i, cur_val));
                } else if (!dq.empty() && dq.front().second >= cur_val && cur_val > dq.back().second) {
                    while (!dq.empty() && dq.back().second < cur_val) {
                        dq.pop_back();
                    }
                    dq.push_back(make_pair(i, cur_val));
                } else if (!dq.empty() && dq.back().second >= cur_val) {
                    dq.push_back(make_pair(i, cur_val));
                }

            } else dq.push_back(make_pair(i, nums[i]));
        }
        return res;
    }
};
