//
// Created by Fangzhou Zhang on 2020/5/10.
//
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if (0 == n) return 0;
        int res = 0;
        int sum;
        for (int i = 0; i < n - 1; i++) {
            sum = arr[i];
            for (int j = i + 1; j < n; j++) {
                sum ^= arr[j];
                if (sum == 0) res += j - i;
            }
        }
        return res;
    }
};
