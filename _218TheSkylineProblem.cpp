//
// Created by Fangzhou Zhang on 2020/2/21.
//
class Point {
public:
    int x;
    int y;
    bool isRight;
    Point(int _x, int _y, bool _isRight) : x(_x), y(_y), isRight(_isRight){}
};
bool cmp(const Point* a, const Point* b) {
    if (a->x != b->x) {
        return a->x < b->x;
    } else {
        if (!a->isRight && !b->isRight) return b->y < a->y;
        else if (a->isRight && b->isRight) return a->y < b->y;
        else {
            return a->isRight ? 1 : -1;
        }
    }
}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        if (buildings.size() == 0 || buildings[0].size() == 0) return res;
        vector<Point*> points;
        for (auto b : buildings) {
            points.push_back(new Point(b[0], b[2], false));
            points.push_back(new Point(b[1], b[2], true));
        }
        sort(points.begin(), points.end(), cmp);
        map<int, int, greater<int>> map;
        for (auto p : points) {
            if (!p->isRight) {
                if (map.size() == 0 || map.begin()->first < p->y) res.push_back({p->x, p->y});
                map[p->y]++;
            } else {
                map[p->y]--;
                if (map[p->y] == 0) {
                    map.erase(map.find(p->y));
                }
                if (map.size() == 0 || map.begin()->first < p->y) {
                    int h = map.size() == 0 ? 0 : map.begin()->first;
                    res.push_back({p->x, h});
                }
            }
        }
        return res;
    }
};
