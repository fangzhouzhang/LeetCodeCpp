//
// Created by Fangzhou Zhang on 2020/2/22.
//
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int, vector<int>, less<int>> pq(target.begin(), target.end());
        long sum = 0;
        for (auto n : target) {
            if (n <= 0) return false;
            sum += n;
        }
        while (1) {
            int max = pq.top();
            pq.pop();
            long rest_sum = sum - max;
            if (max == 1 || rest_sum == 1) return true;
            if (rest_sum <= 0 || rest_sum > sum / 2 || sum % rest_sum == 0) return false;
            int new_elem = sum % rest_sum;
            sum = rest_sum + new_elem;
            pq.push(new_elem);
        }
        return false;
    }
};
