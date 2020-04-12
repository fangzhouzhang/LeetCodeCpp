//
// Created by Fangzhou Zhang on 2020/4/12.
//
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < m; i++) map[i + 1] = i;
        for (int q : queries) {
            for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
                if (it->second < map[q]) it->second++;
            }
            res.push_back(map[q]);
            map[q] = 0;
        }
        return res;
    }
};
