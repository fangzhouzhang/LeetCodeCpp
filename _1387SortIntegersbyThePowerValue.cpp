//
// Created by Fangzhou Zhang on 2020/5/12.
//
struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = lo; i <= hi; i++) {
            int cur = i;
            int steps = 0;
            while (cur != 1) {
                if (cur % 2 == 0) {
                    cur = cur / 2;
                } else {
                    cur = 3 * cur + 1;
                }
                steps++;
            }
            pq.push(make_pair(i, steps));
        }
        int t = 0;
        int res;
        while (t != k) {
            res = pq.top().first;
            pq.pop();
            t++;
        }
        return res;
    }
};
