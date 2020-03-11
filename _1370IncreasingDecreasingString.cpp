//
// Created by Fangzhou Zhang on 2020/3/11.
//
class Solution {
public:
    string sortString(string s) {
        /*
        2^10 = 1024
        2^8 = 256
        2^18 = 256kB
        2^28 = 256MB
        */
        vector<int> map(26, 0);
        for (auto &a : s) {
            map[a - 'a']++;
        }
        string res;
        int rem = s.size();
        while (rem > 0) {
            for (int i = 0; i < 26; i++) {
                if (map[i] > 0) {
                    map[i]--;
                    res.push_back((char)(i + 'a'));
                    rem--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (map[i] > 0) {
                    map[i]--;
                    res.push_back((char)(i + 'a'));
                    rem--;
                }
            }
        }
        return res;
    }
};
