//
// Created by Fangzhou Zhang on 2020/4/17.
//
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        int val = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            val ^= nums[i];
        }
        int r = val & (-val);
        int count = 0;
        while (r != 0) {
            r >>= 1;
            count++;
        }
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < nums.size(); i++) {
            if (((nums[i] >> (count - 1)) & 1) == 0) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        int v1 = a[0];
        for (int i = 1; i < a.size(); i++) {
            v1 ^= a[i];
        }
        res.push_back(v1);
        v1 = b[0];
        for (int i = 1; i < b.size(); i++) {
            v1 ^= b[i];
        }
        res.push_back(v1);
        return res;
    }
};
