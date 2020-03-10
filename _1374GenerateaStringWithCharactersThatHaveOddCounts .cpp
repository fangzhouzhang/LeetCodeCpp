//
// Created by Fangzhou Zhang on 2020/3/9.
//
class Solution {
public:
    string generateTheString(int n) {
        if (n == 0) return "";
        string res;
        dfs(res, 0, n);
        return res;
    }

    void dfs(string &res, int alpha, int t) {
        if (t == 0) return;
        int cur = 0;
        if (t % 2 == 0) cur = t - 1;
        else if (t != 1) cur = t - 2;
        else cur = 1;
        char a = (char)(alpha + 'a');
        for (int k = 0; k < cur; k++) res.push_back(a);
        dfs(res, alpha + 1, t - cur);
    }
};
