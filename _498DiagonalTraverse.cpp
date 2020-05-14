//
// Created by Fangzhou Zhang on 2020/5/13.
//
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        unordered_map<int, vector<int>> map;
        int rows = matrix.size();
        if (0 == rows) return res;
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                map[i + j].push_back(matrix[i][j]);
            }
        }
        bool reverse = true;
        for (int i = 0; i <= rows + cols - 2; i++) {
            vector<int> &cur = map[i];
            if (!reverse) {
                for (int i = 0; i < cur.size(); i++) res.push_back(cur[i]);
                reverse = true;
            } else {
                for (int i = cur.size() - 1; i >= 0; i--) res.push_back(cur[i]);
                reverse = false;
            }


        }
        return res;
    }
};
