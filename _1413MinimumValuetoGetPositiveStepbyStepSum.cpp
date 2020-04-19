//
// Created by Fangzhou Zhang on 2020/4/19.
//
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int min_v = INT_MAX;
        for (int n : nums) {
            sum += n;
            min_v = min(min_v, sum);
        }
        return max(1 - min_v, 1);
    }
};
