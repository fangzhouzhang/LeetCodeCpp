//
// Created by Fangzhou Zhang on 2020/3/17.
//
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int rows = M.size();
        if (rows == 0) return 0;
        int cols = M[0].size();
        int len = max(rows, cols);
        int res = 0;

        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int x = i, y = 0; x < rows && y < cols; y++) {
                if (M[x][y] == 1) {
                    count += 1;
                    res = max(res, count);
                } else count = 0;
            }
        }

        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int x = 0, y = i; x < rows && y < cols; x++) {
                if (M[x][y] == 1) {
                    count += 1;
                    res = max(res, count);
                } else count = 0;
            }
        }

        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int x = i, y = 0; x < rows && y < cols; x++, y++) {
                if (M[x][y] == 1) {
                    count += 1;
                    res = max(res, count);
                } else count = 0;
            }
        }

        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int x = 0, y = i; x < rows && y < cols; x++, y++) {
                if (M[x][y] == 1) {
                    count += 1;
                    res = max(res, count);
                } else count = 0;
            }
        }

        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int x = 0, y = i; x < rows && y >= 0 && y < cols; x++, y--) {
                if (M[x][y] == 1) {
                    count += 1;
                    res = max(res, count);
                } else count = 0;
            }
        }

        for (int i = 0; i < len; i++) {
            int count = 0;
            for (int x = i, y = cols - 1; x < rows && y >= 0; x++, y--) {
                if (M[x][y] == 1) {
                    count += 1;
                    res = max(res, count);
                } else count = 0;
            }
        }
        return res;
    }
};
