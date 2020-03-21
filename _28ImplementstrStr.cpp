//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    int M = 1e9 + 7;
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        long n_v = 0;
        for (char &c : needle) {
            int bit = c - 'a';
            n_v = (n_v * 26 + bit) % M;
        }
        long h_v = 0;
        long al = 1;
        int n = needle.size();
        for (int i = 0; i < n; i++) {
            int bit = haystack[i] - 'a';
            h_v = (h_v * 26 + bit) % M;
            al = al * 26 % M;
        }
        if (h_v == n_v) return 0;
        for (int i = n; i < haystack.size(); i++) {
            int del = haystack[i - n] - 'a';
            int bit = haystack[i] - 'a';
            h_v = (h_v * 26 - del * al %M + M) % M;
            h_v = (h_v + bit) % M;
            if (h_v == n_v) return i - n + 1;
        }
        return -1;
    }
};
