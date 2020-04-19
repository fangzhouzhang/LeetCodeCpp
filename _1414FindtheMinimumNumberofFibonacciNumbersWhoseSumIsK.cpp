//
// Created by Fangzhou Zhang on 2020/4/19.
//
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> dp(3, 1);
        int sum = 0;
        int idx = 3;
        while (sum <= k) {
            sum = dp[idx - 1] + dp[idx - 2];
            if (sum <= k) dp.push_back(sum);
            idx++;
        }
        int res = 0;
        while (k > 0) {
            int start = 1, end = dp.size() - 1;
            int idx = b_s(k, dp, start, end);
            k -= dp[idx];
            res += 1;
            end = idx;
        }
        return res;
    }

    int b_s(int k, vector<int> &dp, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (dp[mid] == k) {
                return mid;
            } else if (dp[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};
