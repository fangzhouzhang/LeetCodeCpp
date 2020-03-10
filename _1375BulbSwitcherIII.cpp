//
// Created by Fangzhou Zhang on 2020/3/10.
//
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        unordered_map<int, int> map;
        int sum = 0;
        for (int i = 1; i <= light.size(); i++) {
            sum += i;
            map[sum] = i;
        }
        int res = 0, cnt = 0;
        sum = 0;
        for (auto &a : light) {
            sum += a;
            cnt++;
            if (map.find(sum) != map.end() && cnt >= map[sum]) res++;
        }
        return res;
    }
};
