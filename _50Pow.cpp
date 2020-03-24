//
// Created by Fangzhou Zhang on 2020/3/23.
//
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1) return x;
        if (n == 0) return 1;
        int sign = n >= 0 ? 1 : -1;
        long N = abs((long)n);
        function<double(long)> dfs = [&](long mi){
            if (mi == 1) return x;

            double ret = dfs(mi / 2);
            if (mi % 2 == 0) {
                return ret * ret;
            } else {
                return ret * ret * x;
            }
        };

        double res = dfs(N);
        if (sign == 1) return res;
        else return 1 / res;
    }
};
