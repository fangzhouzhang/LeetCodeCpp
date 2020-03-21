//
// Created by Fangzhou Zhang on 2020/3/21.
//
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stack.push(i);
            else {
                if (stack.size() > 0 && s[stack.top()] == '(') stack.pop();
                else stack.push(i);
                int left = stack.size() == 0 ? -1 : stack.top();
                res = max(res, i - left);
            }
        }
        return res;
    }
};
