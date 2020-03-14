//
// Created by Fangzhou Zhang on 2020/3/13.
//
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<int> map(26);
        for (char &c : source) {
            int idx = c - 'a';
            map[idx]++;
        }
        for (char &c : target) {
            int idx = c - 'a';
            if (map[idx] == 0) return -1;
        }
        int res = 1;
        while (1) {
            string concat;
            for (int k = 0; k < res; k++) concat += source;
            if (contain(concat, target)) return res;
            res++;
        }
        return -1;
    }

    bool contain(string s, string t) {
        int idxs = 0, idxt = 0;
        while (idxs < s.size() && idxt < t.size()) {
            if (s[idxs] == t[idxt]) {
                idxs++;
                idxt++;
            } else idxs++;
        }
        if (idxs == s.size() && idxt < t.size()) return false;
        return true;
    }
};
