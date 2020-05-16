//
// Created by Fangzhou Zhang on 2020/5/15.
//
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0, j = 0;
        stack<int> stack;
        while (i < n) {
            stack.push(pushed[i]);
            while (!stack.empty() && stack.top() == popped[j]) {
                stack.pop();
                j++;
            }
            i++;
        }
        if (!stack.empty() && stack.top() != popped[j]) return false;
        return j == n && stack.empty();
    }
};
