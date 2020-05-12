//
// Created by Fangzhou Zhang on 2020/5/12.
//
class Solution {
public:
    int res = 0;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> map(n);
        for (vector<int> &e : edges) {
            map[e[0]].push_back(e[1]);
        }
        dfs(map, 0, hasApple);
        return res * 2;
    }

    bool dfs(vector<vector<int>> &map, int idx, vector<bool>& hasApple) {
        bool apple_exist = false;
        if (hasApple[idx]) apple_exist = true;
        for (int e : map[idx]) {
            if (dfs(map, e, hasApple)) {
                apple_exist = true;
                res++;
            }
        }
        return apple_exist;
    }
};
