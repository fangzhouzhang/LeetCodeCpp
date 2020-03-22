//
// Created by Fangzhou Zhang on 2020/3/22.
//
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0;
        stack<int> stack;
        int idx = 0, res = 0;
        while (idx < height.size()) {
            if (stack.size() == 0 || height[stack.top()] >= height[idx]) stack.push(idx++);
            else {
                int rm = stack.top();
                stack.pop();
                if (stack.size() == 0) continue;
                res += (min(height[idx], height[stack.top()]) - height[rm]) * (idx - stack.top() - 1);
            }
        }
        return res;
    }
};
