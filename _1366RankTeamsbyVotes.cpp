//
// Created by Fangzhou Zhang on 2020/3/1.
//
class cmp {
public:
    vector<vector<int>> vec;
    cmp(vector<vector<int>> v) {
        vec = v;
    }
    bool operator()(const char &a, const char &b) {
        vector<int> &f1 = vec[a - 'A'];
        vector<int> &f2 = vec[b - 'A'];
        for (int i = 0; i < f1.size(); i++) {
            if (f1[i] != f2[i]) {
                return f2[i] < f1[i];
            }
        }
        return a < b;
    }
};
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> map(26, vector<int>(votes[0].size(), 0));
        string res = votes[0];
        for (auto &s : votes) {
            for (int i = 0; i < s.size(); i++) {
                map[s[i] - 'A'][i]++;
            }
        }
        sort(res.begin(), res.end(), cmp(map));
        return res;
    }
};
