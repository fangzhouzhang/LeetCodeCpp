//
// Created by Fangzhou Zhang on 2020/3/15.
//
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> people(n);
        for (int i = 0; i < n; i++) people[i] = make_pair(speed[i], efficiency[i]);
        sort(people.begin(), people.end(), [](const pair<int, int> a, const pair<int, int> b){
            return a.second < b.second;
        });
        priority_queue<int, vector<int>, greater<int> > times;

        long res = -1;
        long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (times.size() < k) {
                sum += people[i].first;
                times.push(people[i].first);
            } else {

                sum -= times.top();
                times.pop();
                sum += people[i].first;
                times.push(people[i].first);

            }
            res = max(res, sum * people[i].second);
        }
        return (int)(res % (1000000007));
    }
};
