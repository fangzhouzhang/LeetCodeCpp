//
// Created by Fangzhou Zhang on 2020/2/23.
//
class Solution {
public:
    int numberOfSubstrings(string s) {
        if ( s.size() == 0) return 0;
        int res = 0;
        vector<int> map(3, 0);
        int rem = 3;
        int slow = 0, fast = 0;
        while (fast < s.size()) {
            int idx = s[fast] - 'a';
            map[idx]++;
            if (map[idx] == 1) rem--;
            while (rem == 0) {
                int idx2 = s[slow] - 'a';
                map[idx2]--;
                if (map[idx2] == 0) rem++;
                slow++;
            }
            res += slow;
            fast++;
        }
        return res;
    }
};
