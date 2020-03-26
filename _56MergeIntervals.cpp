//
// Created by Fangzhou Zhang on 2020/3/25.
//
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};
