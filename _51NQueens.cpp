//
// Created by Fangzhou Zhang on 2020/2/27.
//
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n <= 0) return res;
        vector<int> pos(n, 0);
        vector<string> tmp;
        string line;

        for (int j = 0; j < n; j++) {
            line.push_back('.');
        }
        for (int i = 0; i < n; i++) {
            tmp.push_back(line);
        }
        dfs(0, pos, res, tmp);
        return res;
    }

private:
    void dfs(int idx, vector<int>& pos, vector<vector<string>>& res, vector<string>& tmp) {
        if (idx == pos.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < pos.size(); i++) {
            pos[idx] = i;
            if (isValid(pos, idx, i)) {
                tmp[idx][i] = 'Q';
                dfs(idx + 1, pos, res, tmp);
                tmp[idx][i] = '.';
            }
        }
    }

    bool isValid(const vector<int>& pos, int line, int idx) {
        for (int i = 0; i < line; i++) {
            if (i == line || pos[i] == idx) return false;
            if (abs(i - line) == abs(pos[i] - idx)) return false;
        }
        return true;
    }
};
