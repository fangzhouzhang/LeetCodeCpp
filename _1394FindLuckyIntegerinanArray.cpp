//
// Created by Fangzhou Zhang on 2020/4/2.
//
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = -1;
        map<int, int> m;
        for (int n : arr) m[n]++;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->first == it->second) res = it->first;
        }
        return res;
    }
};
