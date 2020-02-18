//
// Created by Fangzhou Zhang on 2020/2/17.
//
class UnionFind{
public:
    int parent[26];
    int rank[26];
    UnionFind() {
        for (int i = 0; i < 26; i++) parent[i] = i;
    }
    int findParent(int x) {
        if (parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }
    void getUnion(int x, int y) {
        int rootA = findParent(x);
        int rootB = findParent(y);
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (auto& s : equations) {
            if (s[1] == '=') {
                int a = s[0] - 'a';
                int b = s[3] - 'a';
                uf.getUnion(a, b);
            }
        }
        for (auto& s : equations) {
            if (s[1] == '!') {
                int a = s[0] - 'a';
                int b = s[3] - 'a';
                if (uf.findParent(a) == uf.findParent(b)) return false;
            }
        }
        return true;
    }
};
