//
// Created by Fangzhou Zhang on 2020/3/17.
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int hold = INT_MIN, sold = 0;
        for (int &p : prices) {
            int hold_tmp = hold, sold_tmp = sold;
            hold = max(hold_tmp, 0 - p);
            sold = max(sold_tmp, hold_tmp + p);
        }
        return sold;
    }
};
