//
// Created by Fangzhou Zhang on 2020/5/15.
//
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> g(N + 1, vector<int>(N + 1, -1));
        vector<int> dist(N + 1, INT_MAX);
        vector<int> indegree(N + 1, 0);
        dist[K] = 0;
        for (vector<int> &t : times) {
            g[t[0]][t[1]] = t[2];
            indegree[t[1]]++;
        }
        unordered_set<int> set;
        for (int i = 1; i <= N; i++) {
            if (0 == indegree[i]) {
                set.insert(i);
            }
            if (set.size() > 1) return -1;
        }
        queue<int> q;
        q.push(K);
        while (!q.empty()) {
            unordered_set<int> dedup;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int u = q.front();
                q.pop();
                for (int v = 1; v <= N; v++) {
                    if (u == v || g[u][v] == -1) continue;
                    if (dist[u] + g[u][v] < dist[v]) {
                        dist[v] = dist[u] + g[u][v];
                        if (dedup.find(v) == dedup.end()) {
                            dedup.insert(v);
                            q.push(v);
                        }
                    }

                }
            }
        }

        int res = 0;
        for (int i = 1; i <= N; i++) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
