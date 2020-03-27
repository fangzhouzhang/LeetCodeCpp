//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n == 0) return res;
        int l = 0;//left
        int r = n - 1;//right
        int u = 0;//up
        int d = n - 1;//down
        int num = 1;
        while (l <= r && u <= d) {
            if (l <= r && u <= d) {
                for (int i = l; i <= r; i++) {
                    res[u][i] = num++;
                }
                u++;
            }
            if (l <= r && u <= d) {
                for (int i = u; i <= d; i++) {
                    res[i][r] = num++;
                }
                r--;
            }
            if (l <= r && u <= d) {
                for (int i = r; i >= l; i--) {
                    res[d][i] = num++;
                }
                d--;
            }
            if (l <= r && u <= d) {
                for (int i = d; i >= u; i--) {
                    res[i][l] = num++;
                }
                l++;
            }
        }
        return res;
    }
};
