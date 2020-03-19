//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int idx = 0;
        vector<string> tmp(numRows);
        while (idx < n) {
            for (int i = 0; i < numRows && idx < n; i++) tmp[i].push_back(s[idx++]);
            for (int i = numRows - 2; i >= 1 && idx < n; i--) tmp[i].push_back(s[idx++]);
        }
        string res;
        for (int i = 0; i < numRows; i++) res += tmp[i];
        return res;
    }
};
