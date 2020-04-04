//
// Created by Fangzhou Zhang on 2020/4/4.
//
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        int res = 0, idx = 0;
        stack<int> stack;
        while (idx < heights.size()) {
            if (stack.size() == 0 || heights[stack.top()] <= heights[idx]) stack.push(idx++);
            else {
                int h = heights[stack.top()];
                stack.pop();
                int l = stack.size() == 0? -1 : stack.top();
                res = max(res, h * (idx - l - 1));
            }
        }
        while (stack.size() != 0) {
            int h = heights[stack.top()];
            stack.pop();
            int l = stack.size() == 0? -1 : stack.top();
            res = max(res, h * (idx - l - 1));
        }
        return res;
    }
};
