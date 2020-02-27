//
// Created by Fangzhou Zhang on 2020/2/27.
//
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) continue;
                if (i == 0 || j == 0) res++;
                else {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                    res += matrix[i][j];
                }
            }
        }
        return res;
    }
};
