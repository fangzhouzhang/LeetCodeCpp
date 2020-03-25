//
// Created by Fangzhou Zhang on 2020/3/25.
//
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);\

        function<bool(int, int)> isValid = [&](int idx, int p){
            for (int k = 0; k < idx; k++) {
                if (pos[k] == p) return false;
                if (abs(k - idx) == abs(pos[k] - p)) return false;
            }
            return true;
        };

        function<void(int)> dfs = [&](int idx){
            if (idx == n) {
                res++;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (isValid(idx, i)) {
                    pos[idx] = i;
                    dfs(idx + 1);
                }
            }
        };
        dfs(0);
        return res;
    }
};
