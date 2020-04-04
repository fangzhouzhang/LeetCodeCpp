//
// Created by Fangzhou Zhang on 2020/4/4.
//
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix[0].size();
        vector<int> a(n);
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') a[j] = 0;
                else a[j] += 1;
            }
            res = max(res, get_max_area(a));
        }
        return res;
    }

    int get_max_area(vector<int> &a){
        stack<int> stack;
        int idx = 0;
        int res = 0;
        while (idx < a.size()) {
            if (stack.size() == 0 || a[stack.top()] <= a[idx]) stack.push(idx++);
            else {
                int h = a[stack.top()];
                stack.pop();
                int l = stack.size() == 0? -1 : stack.top();
                res = max(res, h * (idx - l - 1));
            }
        }
        while (stack.size() != 0) {
            int h = a[stack.top()];
            stack.pop();
            int l = stack.size() == 0? -1 : stack.top();
            res = max(res, h * (idx - l - 1));
        }
        return res;
    }
};
