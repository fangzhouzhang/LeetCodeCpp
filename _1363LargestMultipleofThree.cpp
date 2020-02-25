//
// Created by Fangzhou Zhang on 2020/2/24.
//
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int maps[10] = {0};
        int rem1 = 0, rem2 = 0, sum = 0;
        for (auto& a : digits) {
            sum += a;
            maps[a]++;
            if (a % 3 == 1) rem1++;
            if (a % 3 == 2) rem2++;
        }
        if (sum % 3 == 1) {
            if (rem1 > 0) rem1 -= 1;
            else if (rem2 > 1) rem2 -= 2;
            else return "";
        } else if (sum % 3 == 2) {
            if (rem2 > 0) rem2 -= 1;
            else if (rem1 > 1) rem1 -= 2;
            else return "";
        }
        string res;
        for (int i = 9; i >= 0; i--) {
            if (i % 3 == 0 && maps[i] > 0) {
                while (maps[i] > 0) {
                    res.push_back((char)(i + '0'));
                    maps[i]--;
                }
            }
            else if (i % 3 == 1) {
                while (maps[i] > 0 && rem1 > 0) {
                    res.push_back((char)(i + '0'));
                    maps[i]--;
                    rem1--;
                }
            } else {
                while (maps[i] > 0 && rem2 > 0) {
                    res.push_back((char)(i + '0'));
                    maps[i]--;
                    rem2--;
                }
            }
        }
        if (res.size() > 0 && res[0] == '0') return "0";
        else return res;
    }
};
