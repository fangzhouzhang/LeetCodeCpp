//
// Created by Fangzhou Zhang on 2020/3/17.
//
struct cmp{
    int base;
    bool operator()(const int a, const int b) {
        if (abs(a - base) < abs(b - base)) return a > b;
        else if (abs(a - base) > abs(b - base)) return b < a;
        else return a > b;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        priority_queue<int, vector<int>, cmp> pq;
        for (int &a : arr) {
            if (pq.size() < k) {
                pq.push(a);
            } else {
                if (abs(a - x) < abs(pq.top() - x)) {
                    pq.pop();
                    pq.push(a);
                }
            }
        }
        while (pq.size() > 0) {
            res.push_back(pq.top());
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
