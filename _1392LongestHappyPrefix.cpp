//
// Created by Fangzhou Zhang on 2020/4/6.
//
class Solution {
public:
    string longestPrefix(string s) {
        if (s.size() == 0) return "";
        long l = 0, r = 0, aL = 1;
        int k = 0, n = s.size();
        int M = 1e9 + 7;
        for (int i = 0; i < n - 1; i++) {
            l = (l * 31 + (s[i] - 'a')) % M;
            r = ((s[n - 1 - i] - 'a') * aL + r) % M;
            if (l == r) k = i + 1;
            aL = aL * 31 % M;
        }
        return s.substr(0, k);
    }
};
