//
// Created by Fangzhou Zhang on 2020/4/29.
//
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (0 == n) return 0;
        unordered_map<int, int> map;
        int low;
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
            low = min(low, nums[i]);
        }
        int res = 0;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            if (it->second > 0) {
                int count = 1;
                int key = it->first - 1;
                while (map.find(key) != map.end() && map[key] > 0) {
                    count++;
                    map[key]--;
                    key--;
                }
                key = it->first + 1;
                while (map.find(key) != map.end() && map[key] > 0) {
                    count++;
                    map[key]--;
                    key++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
