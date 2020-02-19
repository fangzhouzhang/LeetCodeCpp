//
// Created by Fangzhou Zhang on 2020/2/18.
//
class UnionFind {
public:
    int c;
    vector<vector<int>> parent;
    vector<vector<int>> rank;
    UnionFind(int n) {
        c = n;
        parent = vector<vector<int>> (n, vector<int>(n));
        rank = vector<vector<int>> (n, vector<int>(n));
        for (int i = 0; i < parent.size(); i++) {
            for (int j = 0; j < parent[i].size(); j++) {
                parent[i][j] = i * n + j;
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    parent[i][j] = 0;
                }
            }
        }
        rank[0][0] = 1;
    }

    int findParent(int const x) {
        if (parent[x / c][x % c] != x) {
            parent[x / c][x % c] = findParent(parent[x / c][x % c]);
        }
        return parent[x / c][x % c];
    }

    void getUnion(int a, int b) {
        int rootA = findParent(a);
        int rootB = findParent(b);
        if (rootA == rootB) return;
        if (rank[rootA / c][rootA % c] < rank[rootB / c][rootB % c]) {
            parent[rootA / c][rootA % c] = rootB;
        } else if (rank[rootA / c][rootA % c] > rank[rootB / c][rootB % c])  {
            parent[rootB / c][rootB % c] = rootA;
        } else {
            parent[rootB / c][rootB % c] = rootA;
            rank[rootA / c][rootA % c]++;
        }
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        UnionFind uf(grid.size() + 1);
        int m = grid.size() + 1;
        int res = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int a, b;
                if (grid[i][j] == '/') {
                    a = uf.findParent((i + 1) * m + j);
                    b = uf.findParent((i) * m + j + 1);
                    if (a == b) {
                        res++;
                    } else {
                        uf.getUnion((i + 1) * m + j, i * m + j + 1);
                    }
                } else if (grid[i][j] == '\\') {
                    a = uf.findParent(i * m + j);
                    b = uf.findParent((i + 1) * m + j + 1);
                    if (a == b) {
                        res++;
                    } else {
                        uf.getUnion(i * m + j, (i + 1) * m + j + 1);
                    }
                }
            }
        }
        return res;
    }
};
