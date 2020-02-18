//
// Created by Fangzhou Zhang on 2020/2/17.
//
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp);
        bool visit[100001] = {0};
        int res = 0;
        for (auto e : events) {
            for (int i = e[0]; i <= e[1]; i++) {
                if (visit[i]) continue;
                visit[i] = true;
                res++;
                break;
            }
        }
        return res;
    }
};
