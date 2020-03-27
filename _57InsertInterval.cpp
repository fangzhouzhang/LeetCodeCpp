//
// Created by Fangzhou Zhang on 2020/3/27.
//
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        int start = newInterval[0], end = newInterval[1];
        bool add = false;
        for (vector<int> &cur : intervals) {
            if (cur[1] < start) {
                res.push_back(cur);
            }
            else if (end < cur[0]) {
                if (!add) {
                    res.push_back({start, end});
                    add = true;
                }
                res.push_back(cur);
            }
            else {
                start = min(start, cur[0]);
                end = max(end, cur[1]);
            }
        }
        if (!add) res.push_back({start, end});
        return res;
    }
};
