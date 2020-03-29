//
// Created by Fangzhou Zhang on 2020/3/29.
//
class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0) return "";
        deque<string> dq;
        int idx = 0;
        while (idx < path.size()) {
            if (path[idx] == '\/') {
                int next = idx + 1;
                string cur;
                while (next < path.size() && path[next] != '\/') {
                    cur.push_back(path[next]);
                    next++;
                }
                if (cur.compare(".") == 0 || cur.compare("") == 0) {

                } else if (cur.compare("..") == 0) {
                    if (dq.size() > 0) dq.pop_back();
                } else {
                    dq.push_back(cur);
                }
                idx = next;
            }
        }
        string res;
        for (string s : dq) {
            res.push_back('\/');
            res += s;
        }
        return res == "" ? "\/" : res;
    }
};
