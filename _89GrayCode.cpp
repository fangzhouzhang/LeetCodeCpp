//
// Created by Fangzhou Zhang on 2020/4/7.
//
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0) return {};
        int len = 1 << n;
        vector<int> res (len, 0);
        for (int i = 0; i < len; i++) {
            res[i] = (i ^ (i >> 1));
        }
        return res;
    }
};
