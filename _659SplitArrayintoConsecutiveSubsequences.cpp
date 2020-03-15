//
// Created by Fangzhou Zhang on 2020/3/15.
//
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int &a : nums) map[a]++;
        unordered_map<int, int> end;
        for (int &a : nums) {
            if (map[a] == 0) continue;
            map[a]--;
            if (end[a - 1] > 0) {
                end[a - 1]--;
                end[a]++;
            } else if (map[a + 1] > 0 && map[a + 2] > 0) {
                map[a + 1]--;
                map[a + 2]--;
                end[a + 2]++;
            } else return false;
        }
        return true;
    }
};
