//
// Created by Fangzhou Zhang on 2020/3/11.
//
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int state = 0;
        unordered_set<char> set{'a', 'e', 'i', 'o', 'u'};
        vector<int> map(1 << 5, INT_MAX);
        map[0] = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (set.find(s[i]) != set.end()) {
                int bit = 0;
                if (s[i] == 'a') bit = 0;
                else if (s[i] == 'e') bit = 1;
                else if (s[i] == 'i') bit = 2;
                else if (s[i] == 'o') bit = 3;
                else if (s[i] == 'u') bit = 4;
                state ^= (1 << bit);
            }
            if (map[state] != INT_MAX) {
                res = max(res, i + 1 - map[state]);
            } else map[state] = i + 1;
        }
        return res;
    }
};
