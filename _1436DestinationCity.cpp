//
// Created by Fangzhou Zhang on 2020/5/3.
//
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        if (paths.size() == 0) return "";
        unordered_map<string, int> map;
        for (vector<string> &p: paths) {
            map[p[0]]++;
            if (map.count(p[1]) == 0) {
                map[p[1]] = 0;
            }
        }
        string res;
        for (unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++) {
            if (it->second == 0) res = it->first;
        }
        return res;
    }
};
