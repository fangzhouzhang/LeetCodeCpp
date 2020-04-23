//
// Created by Fangzhou Zhang on 2020/4/22.
//
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        int single = 0;
        vector<int> map(26, 0);
        for (char c : s) {
            int idx = (int)(c - 'a');
            map[idx]++;
        }

        for (int n : map) {
            if (n % 2 == 1) single++;
        }
        return single <= k;
    }
};
