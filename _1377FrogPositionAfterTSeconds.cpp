//
// Created by Fangzhou Zhang on 2020/3/8.
//
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> map(n + 1, vector<int>());
        for (auto &a: edges) {
            map[a[0]].push_back(a[1]);
            map[a[1]].push_back(a[0]);
        }
        queue<pair<int, double>> q;
        q.push(make_pair(1, 1));
        unordered_set<int> set;
        set.insert(1);
        int second = 0;
        while (second <= t && q.size() > 0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                pair p = q.front();
                q.pop();
                int total = 0;
                for (int i = 0; i < map[p.first].size(); i++) {
                    if (set.find(map[p.first][i]) == set.end()) total++;
                }
                if (p.first == target) {
                    if (second == t || total == 0) return p.second;
                    else return 0;
                }

                for (int i = 0; i < map[p.first].size(); i++) {
                    if (set.find(map[p.first][i]) == set.end()) {
                        set.insert(map[p.first][i]);
                        q.push(make_pair(map[p.first][i], p.second / total));
                    }
                }
            }
            second++;
        }
        return 0;
    }
};
