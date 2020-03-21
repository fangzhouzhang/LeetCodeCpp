//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() == 0 || words.size() == 0) return res;
        int w_s = words.size();//word_size
        int w_l = words[0].size();//word_len
        int total = w_s * w_l;
        if (s.size() < total) return res;
        unordered_map<string, int> ori;
        for (string &word: words) ori[word]++;
        int cnt = ori.size();
        for (int i = 0; i <= s.size() - total; i++) {
            unordered_map<string, int> c(ori);
            int cur_cnt = cnt;
            for (int k = i; k <= i + total - 1; k += w_l) {
                string key = s.substr(k, w_l);
                if (c.find(key) == c.end()) break;
                c[key]--;
                if (c[key] == 0) cur_cnt--;
            }
            if (cur_cnt == 0) res.push_back(i);
        }
        return res;
    }
};
