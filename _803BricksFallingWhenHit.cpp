//
// Created by Fangzhou Zhang on 2020/5/15.
//
class UnionFind {
public:
    vector<int> parent;
    vector<int> s;
    UnionFind(int rows, int cols) {
        int size = rows * cols;
        parent.resize(size);
        s.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            s[i] = 1;
        }
    }

    int getParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = getParent(parent[x]);
    }

    void union_(int x, int y) {
        int a = getParent(x);
        int b = getParent(y);
        if (a == b) return;
        if (a == 0) {
            parent[b] = a;
            s[a] += s[b];
        } else if (b == 0) {
            parent[a] = b;
            s[b] += s[a];
        } else if ( s[a] > s[b]) {
            parent[b] = a;
            s[a] += s[b];
        } else if (s[a] <= s[b]) {
            parent[a] = b;
            s[b] += s[a];
        }
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> res(hits.size(), 0);
        if (0 == grid.size()) return res;
        int m = grid.size(), n = grid[0].size();
        UnionFind *uf = new UnionFind(m, n);
        for (vector<int> &h : hits) {
            if (grid[h[0]][h[1]] == 1) {
                grid[h[0]][h[1]] = 2;
                if (h[0] == 0) {
                    uf->s[h[1]]--;
                }
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                uf->union_(0, i);
                set.insert(i);
                dfs(grid, 0, i, uf, set);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    set.insert(i * n + j);
                    dfs(grid, i, j, uf, set);
                }
            }
        }
        int brickLeft = uf->s[0];
        for (int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            if (2 == grid[x][y] ) {
                grid[x][y] = 1;
                if (x == 0) {
                    uf->parent[y] = 0;
                    uf->s[0]++;

                }
                for (vector<int> &dir : dirs) {
                    if (check_boundary(grid, x + dir[0], y + dir[1])) {
                        if (grid[x + dir[0]][y + dir[1]] == 1) {
                            uf->union_((x + dir[0]) * n + (y + dir[1]), x * n + y);
                        }
                    }
                }
            }
            int curBrick = uf->s[0];
            res[i] = max(curBrick - brickLeft - 1, 0);
            brickLeft = curBrick;
        }
        return res;
    }


    void dfs(vector<vector<int>>& grid, int row, int col, UnionFind *uf, unordered_set<int> &set) {
        for (vector<int> &dir : dirs) {
            if (check_boundary(grid, row + dir[0], col + dir[1])) {
                if (grid[row + dir[0]][col + dir[1]] == 1 && set.find((row + dir[0]) * grid[row].size() + col + dir[1]) == set.end()) {
                    uf->union_(row * grid[row].size() + col, (row + dir[0]) * grid[row].size() + col + dir[1]);
                    set.insert((row + dir[0]) * grid[row].size() + col + dir[1]);
                    dfs(grid, row + dir[0], col + dir[1], uf, set);
                }
            }
        }
    }


    bool check_boundary(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size()) return false;
        if (j < 0 || j >= grid[i].size()) return false;
        return true;
    }
};
