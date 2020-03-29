//
// Created by Fangzhou Zhang on 2020/3/28.
//
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int sum = a[i] - '0' + b[j] - '0' + carry;
            res.push_back((char)(sum % 2 + '0'));
            carry = sum / 2;
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = a[i] - '0' + carry;
            res.push_back((char)(sum % 2 + '0'));
            carry = sum / 2;
            i--;
        }
        while (j >= 0) {
            int sum = b[j] - '0' + carry;
            res.push_back((char)(sum % 2 + '0'));
            carry = sum / 2;
            j--;
        }
        if (carry != 0) res.push_back((char)(carry + '0'));
        i = 0, j = res.size() - 1;
        while (i <= j) swap(res[i++], res[j--]);
        return res;
    }
};
