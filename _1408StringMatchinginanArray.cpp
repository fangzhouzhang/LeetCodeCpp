//
// Created by Fangzhou Zhang on 2020/4/12.
//
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int M = 1e9 + 7;
        vector<string> res;
        if (words.size() == 0) return res;
        function<bool(string, int, long)> is_substr = [&](string s, int n, long target) {
            long cur = 0;
            long aL = 1;
            for (int i = 0; i < n; i++) {
                int val = s[i] - 'a';
                cur = (cur * 26 + val) % M;
                aL = aL * 26 % M;
            }
            if (cur == target) return true;
            for (int i = n; i < s.size(); i++) {
                int del_val = s[i - n] - 'a';
                int cur_val = s[i] - 'a';
                cur = (cur * 26 - del_val * aL % M + M) % M;
                cur = (cur + cur_val) % M;
                if (cur == target) return true;
            }
            return false;
        };
        for (int i = 0; i < words.size(); i++) {
            long target = 0;
            for (char c : words[i]) {
                int val = c - 'a';
                target = (target * 26 + val) % M;
            }
            for (int j = 0; j < words.size(); j++) {
                if (i == j || words[i].size() > words[j].size()) continue;
                if (is_substr(words[j], words[i].size(), target)) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }

};
