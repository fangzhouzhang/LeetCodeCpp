//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        long res = 0;
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
        long input = abs((long)dividend);
        long d = abs((long)divisor);
        function<long(long, long)> calc = [&](long input, long d){
            if (input == 0 || input < d) return 0l;
            long ret = 1;
            long ori = d;
            while (d + d <= input) {
                d = d + d;
                ret += ret;
            }
            return ret + calc(input - d, ori);
        };
        res = calc(input, d);
        res *= sign;
        if (res < INT_MIN || res >= INT_MAX) return INT_MAX;
        return res;
    }
};
