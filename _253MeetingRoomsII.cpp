//
// Created by Fangzhou Zhang on 2020/3/26.
//
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> points;
        for (vector<int> &i: intervals) {
            points.push_back({i[0], 0});
            points.push_back({i[1], 1});
        }

        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b){
            if (a.first != b.first) return a.first < b.first;
            return b.second < a.second;
        });

        int res = 0, cur = 0;
        for (auto &p : points) {
            if (p.second == 0) {
                cur++;
                res = max(res, cur);
            } else {
                cur--;
            }
        }
        return res;
    }
};
