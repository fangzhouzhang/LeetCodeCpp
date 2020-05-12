//
// Created by Fangzhou Zhang on 2020/5/12.
//
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int &n : nums) {
            int num = 0;
            int sum = 0;
            for (int i = 1; i * i <= n; i++) {
                if ((n % i) == 0) {
                    if (i * i == n) num++;
                    else num += 2;
                    sum += i;
                    sum += n / i;
                }
            }
            if (num == 4) res += sum;
        }
        return res;
    }
};
