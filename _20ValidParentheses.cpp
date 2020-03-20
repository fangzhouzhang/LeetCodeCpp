//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')') {
                if (stack.size() == 0 || stack.top() != '(') return false;
                stack.pop();
            } else if (c == '}') {
                if (stack.size() == 0 || stack.top() != '{') return false;
                stack.pop();
            } else if (c == ']') {
                if (stack.size() == 0 || stack.top() != '[') return false;
                stack.pop();
            }
        }
        return stack.size() == 0;
    }
};
