//
// Created by Fangzhou Zhang on 2020/3/18.
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> map(128, 0);
        int left = 0, right = 0;
        int violate = 0;
        while (right < s.size()) {
            int idx = s[right];
            map[idx]++;
            if (map[idx] == 2) violate++;
            while (violate > 0) {
                int l = s[left];
                map[l]--;
                if (map[l] == 1) violate--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
