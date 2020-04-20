//
// Created by Fangzhou Zhang on 2020/4/19.
//
class Solution {
public:
    string reformat(string s) {
        if (s.size() == 0) return "";
        vector<int> ds;
        vector<int> cs;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                ds.push_back(i);
            }
            if (isalpha(s[i])) {
                cs.push_back(i);
            }
        }
        if (abs((int)ds.size() - (int)cs.size()) > 1) return "";
        string res;
        if (ds.size() > cs.size()) {
            int i = 0, j = 0;
            while (i < ds.size()) {
                res.push_back(s[ds[i++]]);
                if (j < cs.size()) res.push_back(s[cs[j++]]);
            }
        } else if (cs.size() >= ds.size()) {
            int i = 0, j = 0;
            while (i < cs.size()) {
                res.push_back(s[cs[i++]]);
                if (j < ds.size()) res.push_back(s[ds[j++]]);
            }
        }
        return res;
    }
};
