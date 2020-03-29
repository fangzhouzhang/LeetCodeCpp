//
// Created by Fangzhou Zhang on 2020/3/28.
//
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if (digits.size() == 0) return res;
        int carry = 1;
        int idx = digits.size() - 1;

        while (idx >= 0) {
            int sum = digits[idx] + carry;
            digits[idx] = sum % 10;
            carry = sum / 10;
            idx--;
        }
        if (carry != 0) res.push_back(carry);
        for (int &a : digits) res.push_back(a);
        return res;
    }
};
