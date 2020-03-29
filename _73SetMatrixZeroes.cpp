//
// Created by Fangzhou Zhang on 2020/3/29.
//
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        if (cols == 0) return;
        unordered_set<int> rs;
        unordered_set<int> cs;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    rs.insert(i);
                    cs.insert(j);
                }
            }
        }

        unordered_set<int>::iterator it1 = rs.begin();
        while (it1 != rs.end()) {
            for (int i = 0; i < cols; i++) matrix[*it1][i] = 0;
            it1++;
        }

        unordered_set<int>::iterator it2 = cs.begin();
        while (it2 != rs.end()) {
            for (int i = 0; i < rows; i++) matrix[i][*it2] = 0;
            it2++;
        }
    }
};
