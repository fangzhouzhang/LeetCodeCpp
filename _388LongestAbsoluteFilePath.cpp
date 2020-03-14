//
// Created by Fangzhou Zhang on 2020/3/13.
//
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> ss = split(input, '\n');
        int res = 0;
        stack<int> stack;
        for(auto n:ss) {
            int cur_level = n.find_last_of("/\t") + 1;
            while (stack.size() > cur_level) {
                stack.pop();
            }
            if (n.find(".") != -1) {
                //document
                int prev_len = stack.size() == 0 ? 0 : stack.top();
                int cur_len = prev_len == 0 ? prev_len + n.size() - cur_level : prev_len + (n.size() - cur_level + 1);
                res = max(res, cur_len);
            } else {
                if (cur_level == 0) stack.push(n.size());
                else stack.push(stack.top() + n.size() - cur_level + 1);
            }
        }
        return res;
    }

    vector<string> split(string &input, char c) {
        vector<string> res;
        string buff;
        for (auto &a : input) {
            if (a != c) buff.push_back(a);
            else if (a == c && buff != "") {
                res.push_back(buff);
                buff = "";
            }
        }
        if (buff != "") res.push_back(buff);
        return res;
    }
};
