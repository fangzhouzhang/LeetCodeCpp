//
// Created by Fangzhou Zhang on 2020/5/15.
//
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        unordered_map<string, int> m;
        for (string &word : words) {
            m[word]++;
        }
        for (unordered_map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (isSub(it->first, S)) res += it->second;
        }
        return res;
    }

    bool isSub(const string &t, const string &s) {
        int m = t.size();
        int n = s.size();
        if (m > n) return false;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (t[i] == s[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return (i == m);
    }
};
