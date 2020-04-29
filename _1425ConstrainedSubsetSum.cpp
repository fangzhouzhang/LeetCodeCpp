//
// Created by Fangzhou Zhang on 2020/4/28.
//
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        if (0 == n) return 0;
        deque<pair<int, int>> dq;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (!dq.empty()) {
                if (i - dq.front().first > k) dq.pop_front();
            }
            int cur_val;
            if (!dq.empty()) {
                cur_val = max(0, dq.front().second) + nums[i];
            } else {
                cur_val = nums[i];
            }
            res = max(res, cur_val);
            while (!dq.empty() && dq.back().second < cur_val) dq.pop_back();
            dq.push_back(make_pair(i, cur_val));
        }
        return res;
    }
};
