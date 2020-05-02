//
// Created by Fangzhou Zhang on 2020/5/1.
//
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (0 == s.size()) return res;
        vector<string> tmp;
        dfs(s, 0, 0, res, tmp);
        return res;
    }

    void dfs(string &s, int pre, int cur, vector<vector<string>> &res, vector<string> &tmp) {
        if (cur == s.size()) {
            if (pre == s.size()) res.push_back(tmp);
            return;
        }


        dfs(s, pre, cur + 1, res, tmp);
        if (is_palin(s, pre, cur)) {
            string part = s.substr(pre, cur - pre + 1);
            tmp.push_back(part);
            dfs(s, cur + 1, cur + 1, res, tmp);
            tmp.pop_back();
        }

    }

    bool is_palin(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
