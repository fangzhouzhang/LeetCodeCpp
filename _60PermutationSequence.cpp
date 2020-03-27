//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> fac(n, 1);
        int p = 1;
        for (int i = 1; i < n; i++) {
            p *= i;
            fac[i] = p;
        }
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        k--;
        int idx = 0;
        while (idx < n) {
            int q = k / fac[n - 1 - idx];//quoti
            res.push_back((char)(nums[q] + '0'));
            nums.erase(nums.begin() + q);
            k -= q * fac[n - 1 - idx];
            idx++;
        }
        return res;
    }
};
