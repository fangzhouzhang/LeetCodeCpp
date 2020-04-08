//
// Created by Fangzhou Zhang on 2020/4/7.
//
class Solution {
public:
    int res = 0;
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        unordered_map<int, int> map;
        return dfs(s, 0, map);
    }

    int dfs(string s, int idx, unordered_map<int, int>& map) {
        if (idx >= s.size()) {
            return 1;
        }
        if (s[idx] == '0') return 0;
        if (map.find(idx) != map.end()) return map[idx];

        int res = 0;
        res += dfs(s, idx + 1, map);
        if (isValid(s, idx)) res += dfs(s, idx + 2, map);
        return map[idx] = res;
    }

    bool isValid(string s, int idx) {
        if (idx + 1 < s.size() && s[idx] == '1') return true;
        if (idx + 1 < s.size() && s[idx] == '2' && s[idx + 1] <= '6') return true;
        return false;
    }
};
