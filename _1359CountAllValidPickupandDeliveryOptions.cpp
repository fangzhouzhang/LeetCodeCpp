//
// Created by Fangzhou Zhang on 2020/2/23.
//
class Solution {
public:
    int M = 1e9 + 7;
    int countOrders(int n) {
        //1
        //1 1
        //2
        //c 42 c22
        //3
        //c62 c42 c22 6 * 5 / 2 * 6
        int total = 2 * n;
        long res = 1;
        while (total >= 2) {
            res *= total * (total - 1) / 2;
            res %= M;
            total -= 2;
        }
        return (int)(res % M);
    }
};
