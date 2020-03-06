//
// Created by Fangzhou Zhang on 2020/3/5.
//
class Solution {
public:
    int UNVISIT = -2;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> map(n, vector<int>());
        for (auto &c : connections) {
            map[c[0]].push_back(c[1]);
            map[c[1]].push_back(c[0]);
        }
        vector<int> depth(n, UNVISIT);
        vector<vector<int>> res;
        dfs(0, n, res, 0, map, depth);
        return res;
    }

    int dfs(int cur, int n, vector<vector<int>> &res, int curDepth, vector<vector<int>> &map, vector<int> &depth) {
        if (depth[cur] != UNVISIT) return depth[cur];
        int min_nei = n;
        depth[cur] = curDepth;
        for (auto &v : map[cur]) {
            if (depth[v] == curDepth - 1 || depth[v] == n) continue;
            int nei = dfs(v, n, res, curDepth + 1, map, depth);
            min_nei = min(min_nei, nei);
            if (nei > curDepth) res.push_back({min(cur, v), max(cur, v)});
        }
        depth[cur] = n;
        return min_nei;
    }
};
