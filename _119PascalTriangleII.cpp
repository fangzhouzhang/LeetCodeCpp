//
// Created by Fangzhou Zhang on 2020/4/21.
//
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        vector<int> pre(rowIndex + 1, 1);
        for (int i = 0; i < rowIndex + 1; i++) {
            if (i == 0 || i == 1) {
                pre = res;
                continue;
            }
            for (int j = 1; j < i; j++) {
                res[j] = pre[j - 1] + pre[j];
            }
            pre = res;
        }
        return res;
    }
};
