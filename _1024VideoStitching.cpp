//
// Created by Fangzhou Zhang on 2020/2/29.
//
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });
        if (clips[0][0] > 0) return -1;
        int curEnd = 0;int maxEnd = 0;int res = 0;int i = 0;
        while (i < clips.size()) {
            while (i < clips.size() && clips[i][0] <= curEnd) {
                if (clips[i][1] > maxEnd) maxEnd = clips[i][1];
                i++;
            }
            res++;
            curEnd = maxEnd;
            if ((i < clips.size() && clips[i][0] > maxEnd) || maxEnd >= T) break;
        }
        if (curEnd < T) return -1;
        return res;
    }
};
