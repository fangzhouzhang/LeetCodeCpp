//
// Created by Fangzhou Zhang on 2020/4/18.
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int num : nums) {
                if (((num >> i) & 1) == 1) count++;
            }
            if (count % 3 != 0) res += (1 << i);
        }
        return res;
    }
};
