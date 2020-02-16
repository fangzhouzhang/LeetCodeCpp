//
// Created by Fangzhou Zhang on 2020/2/16.
//
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size();
        if (r == 0) return 0;
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            int a = binarySearch(grid[i]);
            res += a;
        }
        return res;
    }
private:
    int binarySearch(vector<int>& a) {
        int start = 0, end = a.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (a[mid] < 0) end = mid;
            else start = mid;
        }
        if (a[start] < 0) return a.size() - start;
        else if (a[end] < 0) return a.size() - end;
        else return 0;
    }
};
