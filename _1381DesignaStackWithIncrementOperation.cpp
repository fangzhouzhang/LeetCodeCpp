//
// Created by Fangzhou Zhang on 2020/3/15.
//
class CustomStack {
public:
    int size;
    vector<int> stack, inc;
    CustomStack(int maxSize) {
        size = maxSize;
        inc.resize(maxSize);
    }

    void push(int x) {
        if (stack.size() < size) stack.push_back(x);
    }

    int pop() {
        int idx = stack.size() - 1;
        if (idx < 0) return -1;
        if (idx > 0) inc[idx - 1] += inc[idx];
        int res = stack[idx] + inc[idx];
        inc[idx] = 0;
        stack.pop_back();
        return res;
    }

    void increment(int k, int val) {
        int idx = min(k, (int)stack.size()) - 1;
        if (idx >= 0) inc[idx] += val;
    }
};
