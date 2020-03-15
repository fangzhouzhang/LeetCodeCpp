//
// Created by Fangzhou Zhang on 2020/3/14.
//

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        int cur_max = INT_MIN;
        for (int i = 0; i < n; i++) {
            int cur_min = INT_MAX;
            for (int j = 0; j < m; j++) cur_min = min(cur_min, matrix[i][j]);
            cur_max = max(cur_max, cur_min);
        }
        int cur_min = INT_MAX;
        for (int j = 0; j < m; j++) {
            int second_max = INT_MIN;
            for (int i = 0; i < n; i++) second_max = max(second_max, matrix[i][j]);
            cur_min = min(cur_min, second_max);
        }
        if (cur_min == cur_max) res.push_back(cur_max);
        return res;
    }
};