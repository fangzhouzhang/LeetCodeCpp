//
// Created by Fangzhou Zhang on 2020/2/17.
//
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if (rows[i] > 1 || cols[j] > 1) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
