//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string &s : strs) {
            vector<char> m(26, '0');
            for (int i = 0; i < s.size(); i++) m[s[i] - 'a']++;
            string key;
            for (int i = 0; i < 26;i++) {
                key.push_back(m[i]);
            }
            map[key].push_back(s);
        }
        vector<vector<string>> res;
        unordered_map<string, vector<string>>::iterator it = map.begin();
        while (it != map.end()) {
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};
