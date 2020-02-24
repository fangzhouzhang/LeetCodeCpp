//
// Created by Fangzhou Zhang on 2020/2/23.
//
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res{0, INT_MAX};
        getDiv(res, num + 1);
        getDiv(res, num + 2);
        return res;
    }
    void getDiv(vector<int>& res, int n) {
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                int div = n / i;
                if (abs(i - div) < abs(res[0] - res[1])) {
                    res[0] = i;
                    res[1] = div;
                }
            }
        }
    }
};
