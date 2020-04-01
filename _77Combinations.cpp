//
// Created by Fangzhou Zhang on 2020/3/31.
//
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < k) return res;
        vector<int> tmp;
        function<void(int)> dfs = [&](int num) {
            if (tmp.size() == k) {
                res.push_back(tmp);
                return;
            }
            if (num == n + 1) return;

            tmp.push_back(num);
            dfs(num + 1);
            tmp.pop_back();

            dfs(num + 1);
        };
        dfs(1);
        return res;
    }
};
