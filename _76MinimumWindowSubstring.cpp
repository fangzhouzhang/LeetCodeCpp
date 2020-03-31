//
// Created by Fangzhou Zhang on 2020/3/30.
//
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int l = -1, r = -1, min_len = INT_MAX;
        unordered_map<char, int> map;
        for (char c : t) map[c]++;
        int slow = 0, fast = 0, rem = map.size();
        while (fast < s.size()) {
            if (map.find(s[fast]) != map.end()) {
                map[s[fast]]--;
                if (map[s[fast]] == 0) rem--;
            }
            while (rem == 0) {

                if (min_len > fast - slow + 1) {
                    min_len = fast - slow + 1;
                    r = fast;
                    l = slow;
                }
                if (map.find(s[slow]) != map.end()) {
                    map[s[slow]]++;
                    if (map[s[slow]] == 1) rem++;
                }
                slow++;
            }
            fast++;
        }
        if (min_len == INT_MAX) return "";
        return s.substr(l, min_len);
    }
};
