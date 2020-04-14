//
// Created by Fangzhou Zhang on 2020/4/13.
//
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < routes.size(); i++) {
            sort(routes[i].begin(), routes[i].end());
            for (int j = 0; j < routes[i].size(); j++) {
                map[routes[i][j]].push_back(i);
            }
        }
        unordered_map<int, vector<int>> routes_nei;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = i + 1; j < routes.size(); j++) {
                bool find = false;
                if (routes[i].size() > routes[j].size()) {
                    find = b_s(routes[j], routes[i]);
                } else {
                    find = b_s(routes[i], routes[j]);
                }
                if (find) {
                    routes_nei[i].push_back(j);
                    routes_nei[j].push_back(i);
                }
            }
        }
        queue<int> q;
        unordered_set<int> visit;
        for (int bus: map[S]) {
            q.push(bus);
            visit.insert(bus);
        }

        unordered_set<int> dsts;
        for (int bus: map[T]) {
            dsts.insert(bus);
        }

        int res = 1;
        while (q.size() != 0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int cur_bus = q.front();
                q.pop();
                if (dsts.find(cur_bus) != dsts.end()) return res;
                for (int nei : routes_nei[cur_bus]) {
                    if (visit.find(nei) == visit.end()) {
                        q.push(nei);
                        visit.insert(nei);
                    }
                }
            }
            res++;
        }
        return -1;
    }

    bool b_s(vector<int> a, vector<int> b) {
        for (int target : a) {
            int start = 0, end = b.size() - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (b[mid] == target) {
                    return true;
                } else if (b[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
