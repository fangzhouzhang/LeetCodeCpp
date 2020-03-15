//
// Created by Fangzhou Zhang on 2020/3/15.
//
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        return dfs(s1, 0, s1.size() - 1, s2, 0, s2.size() - 1);
    }

    bool dfs(string s1, int l1, int r1, string s2, int l2, int r2) {
        if (l1 == r1 && l2 == r2 && s1[l1] == s2[l2]) return true;
        if (l1 == r1 && l2 == r2 && s1[l1] != s2[l2]) return false;
        if (r2 - l2 != r1 - l1) return false;
        vector<int> map (26);

        for (int i = l1; i <= r1; i++) {
            map[s1[i] - 'a']++;
        }
        for (int i = l2; i <= r2; i++) {
            map[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (map[i] != 0) return false;
        }
        //cut point from l1 to r1
        for (int i = 0; i < r1 - l1; i++) {
            if (dfs(s1, l1, l1 + i, s2, l2, l2 + i) &&
                dfs(s1, l1 + i + 1, r1, s2, l2 + i + 1, r2)) return true;
            if (dfs(s1, l1, l1 + i, s2, r2 - i, r2) &&
                dfs(s1, l1 + i + 1, r1, s2, l2, r2 - i - 1)) return true;
        }
        return false;
    }
};
