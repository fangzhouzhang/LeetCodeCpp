//
// Created by Fangzhou Zhang on 2020/3/13.
//
class Solution {
public:
    int longestRepeatingSubstring(string S) {
        /**
            get all sub string from s,
            count frequency
            return longest string whose repeating time is > 1

        */
        int start = 1, end = S.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (search(mid, S)) start = mid + 1;
            else end = mid - 1;
        }
        return start - 1;
    }

    bool search(int l, string s) {
        unordered_set<long> set;
        long h = 0, baseL = 1, M = 1000000007;
        int base = 26;
        for (int i = 0; i < l; i++) {
            h = (h * base + (s[i] - 'a')) % M;
            baseL = baseL * base % M;
        }
        set.insert(h);
        for (int start = 1; start <= s.size() - l; start++) {
            h = (h * base - (s[start - 1] - 'a') * baseL % M + M) % M;
            h = (h + (s[start + l - 1] - 'a')) % M;
            if (set.find(h) != set.end()) return true;
            set.insert(h);
        }
        return false;
    }
};
