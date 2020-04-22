//
// Created by Fangzhou Zhang on 2020/4/21.
//
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp(i + 1, 1);
            if (i == 0 || i == 1) {
                res.push_back(tmp);
                continue;
            }
            for (int j = 1; j < i; j++) {
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
