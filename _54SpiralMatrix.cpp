//
// Created by Fangzhou Zhang on 2020/3/25.
//
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int l = 0;//left
        int r = matrix[0].size() - 1;//right
        int u = 0;//up
        int d = matrix.size() - 1;//down
        while (l <= r && u <= d) {
            if (l <= r && u <= d) {
                for (int i = l; i <= r; i++) {
                    res.push_back(matrix[u][i]);
                }
                u++;
            }
            if (l <= r && u <= d) {
                for (int i = u; i <= d; i++) {
                    res.push_back(matrix[i][r]);
                }
                r--;
            }
            if (l <= r && u <= d) {
                for (int i = r; i >= l; i--) {
                    res.push_back(matrix[d][i]);
                }
                d--;
            }
            if (l <= r && u <= d) {
                for (int i = d; i >= u; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};
