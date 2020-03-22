//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "1";
        function<string(string, int)> dfs = [&](string s, int i){
            if (n + 1 == i) return s;
            string cur;
            int idx = 0;
            while (idx <s.size()) {
                int count = 1;
                while (idx + 1 < s.size() && s[idx] == s[idx + 1]) {
                    idx++;
                    count++;
                }
                cur += to_string(count);
                cur.push_back(s[idx++]);
            }
            return dfs(cur, i + 1);
        };
        return dfs("1", 2);
    }
};
