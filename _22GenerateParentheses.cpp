//
// Created by Fangzhou Zhang on 2020/3/20.
//
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;
        string tmp;
        function<void(int, int, int)> dfs = [&](int l, int r, int n){
            if (l == n && r == n) {
                res.push_back(tmp);
                return;
            }

            if (l < n && l >= r) {
                tmp.push_back('(');
                dfs(l + 1, r, n);
                tmp.pop_back();
            }

            if (r < n && l > r) {
                tmp.push_back(')');
                dfs(l, r + 1, n);
                tmp.pop_back();
            }
        };
        dfs(0, 0, n);
        return res;
    }
};
