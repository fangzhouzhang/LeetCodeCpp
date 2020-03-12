//
// Created by Fangzhou Zhang on 2020/3/12.
//
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> map(n);
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) continue;
            map[manager[i]].push_back(i);
        }
        return dfs(map, headID, informTime);
    }

    int dfs(vector<vector<int>>& map, int cur, vector<int>& informTime) {
        if (informTime[cur] == 0) return 0;
        int res = 0;
        for (int &nei : map[cur])
            res = max(res, dfs(map, nei, informTime) + informTime[cur]);
        return res;
    }
};
