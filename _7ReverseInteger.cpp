//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    int reverse(int x1) {
        bool neg = x1 < 0;
        long x = abs((long)x1);
        long r = 0;
        while (x > 0) {
            int bit = x % 10;
            r = r * 10 + bit;
            x /= 10;
        }
        if (neg) r = r * -1;
        if (r < INT_MIN || r > INT_MAX) return 0;
        return r;
    }
};
