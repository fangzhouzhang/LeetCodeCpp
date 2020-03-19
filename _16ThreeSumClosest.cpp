//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        pair<int, int> p = {INT_MAX, 0};
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int cur_sum = nums[i] + nums[j] + nums[k];
                if (cur_sum < target) {
                    if (abs(target - cur_sum) < p.first) {
                        p.first = abs(target - cur_sum);
                        p.second = cur_sum;
                    }
                    j++;
                } else if (cur_sum > target) {
                    if (abs(target - cur_sum) < p.first) {
                        p.first = abs(target - cur_sum);
                        p.second = cur_sum;
                    }
                    k--;
                } else return target;
            }
        }
        return p.second;
    }
};
