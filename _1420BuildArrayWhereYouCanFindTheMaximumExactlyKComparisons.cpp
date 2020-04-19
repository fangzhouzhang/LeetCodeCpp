//
// Created by Fangzhou Zhang on 2020/4/19.
//
class Solution {
public:
    int M = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        vector<int> arr(n, 0);
        return dfs(arr, 0, m, k, 0, dp);
    }

    int dfs(vector<int> &arr, int idx, int m, int k, int max_v, vector<vector<vector<int>>> &dp) {
        if (k < 0) return 0;
        if (idx == arr.size() && k == 0) return 1;
        if (idx == arr.size() && k != 0) return 0;
        if (dp[idx][k][max_v] != -1) return dp[idx][k][max_v];
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            arr[idx] = i;
            if (max_v < arr[idx]) {
                sum = (sum + dfs(arr, idx + 1, m, k - 1, arr[idx], dp)) % M;
            } else {
                sum = (sum + dfs(arr, idx + 1, m, k, max_v, dp)) % M;
            }
        }
        return dp[idx][k][max_v] = sum;
    }
};
