//
// Created by Fangzhou Zhang on 2020/4/22.
//
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> map;
        int max_v = 0;
        for (int i = 1; i <= n; i++) {
            int sum = count(i);
            map[sum]++;
            if (max_v < map[sum]) max_v = map[sum];
        }
        int res = 0;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            if (it->second == max_v) res++;
        }
        return res;
    }

    int count(int a) {
        int res = 0;
        while (a != 0) {
            int digit = a % 10;
            res += digit;
            a /= 10;
        }
        return res;
    }
};
