//
// Created by Fangzhou Zhang on 2020/3/4.
//
vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
private:
    bool isValid(int rows, int n, int a, int b) {
        if (a < 0 || a >= rows) return false;
        if (b < 0 || b >= n) return false;
        return true;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        deque<pair<int, int>> q;
        unordered_set<int> set;
        int rows = grid.size();
        int n = grid[0].size();
        q.push_back(make_pair(0, 0));
        while (q.size() > 0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                pair<int, int> p = q.front();
                q.pop_front();
                int r = p.first / n;
                int c = p.first % n;
                if (r == rows - 1 && c == n - 1) return p.second;
                if (set.find(p.first) != set.end()) continue;
                set.insert(p.first);
                for (int m = 0; m < 4; m++) {
                    int new_r = dirs[m][0] + r;
                    int new_c = dirs[m][1] + c;
                    if (!isValid(rows, n, new_r, new_c)) continue;
                    if ((grid[r][c] - 1) % 4 == m) {
                        q.emplace_front(make_pair(new_r * n + new_c, p.second));
                    } else {
                        q.emplace_back(make_pair(new_r * n + new_c, p.second + 1));
                    }
                }
            }
        }
        return -1;
    }
};
