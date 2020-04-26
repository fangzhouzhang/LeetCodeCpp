//
// Created by Fangzhou Zhang on 2020/4/25.
//
class Solution {
public:
    int maxScore(string s) {
        if (0 == s.size()) return 0;
        int zeros = 0, ones = 0;
        for (char c : s) {
            if (c == '0') zeros++;
            else ones++;
        }

        int lz = 0;
        int lo = 0;
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                lz++;
            } else {
                lo++;

            }
            res = max(res, lz + (ones - lo));
        }
        return res;
    }
};
