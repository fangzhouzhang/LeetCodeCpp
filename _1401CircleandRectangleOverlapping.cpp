//
// Created by Fangzhou Zhang on 2020/4/22.
//
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int m1 = x_center - radius, n1 = y_center - radius;
        int m2 = x_center + radius, n2 = y_center + radius;
        int i1 = max(m1, x1), j1 = max(n1, y1);
        int i2 = min(m2, x2), j2 = min(n2, y2);
        int x = x_center, y = y_center;
        int sq = radius * radius;
        if (i1 <= i2 && j1 <= j2) {
            if (i1 <= x && x <= i2 && j1 <= y && y <= j2) return true;
            if (i2 < x && y < j1) {
                if (dist(i2, j1, x, y) <= sq) return true;
                return false;
            } else if (i2 <= x && y >= j1 && y <= j2) {
                if (x - i2 <= radius) return true;
                return false;
            } else if (i2 < x && y > j2) {
                if (dist(i2, j2, x, y) <= sq) return true;
                return false;
            } else if (i1 <= x && x <= i2 && y <= j1) {
                if (j1 - y <= radius) return true;
                return false;
            } else if (i1 <= x && x <= i2 && y >= j2) {
                if (y - j2 <= radius) return true;
                return false;
            } else if (x < i1 && y < j1) {
                if (dist(i1, j1, x, y) <= sq) return true;
                return false;
            } else if (j1 <= y && y <= j2 && x <= i1) {
                if (i1 - x <= radius) return true;
                return false;
            } else if (x < i1 && y > j2) {
                if (dist(i1, j2, x, y) <= sq) return true;
                return false;
            } else return false;
        }
        return false;
    }
    int dist(int a, int b, int c, int d) {
        return (a - c) * (a - c) + (b - d) * (b - d);
    }
};
