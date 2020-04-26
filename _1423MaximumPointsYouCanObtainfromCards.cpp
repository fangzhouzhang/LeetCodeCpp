//
// Created by Fangzhou Zhang on 2020/4/26.
//
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() == 0) return 0;
        if (k == cardPoints.size()) {
            int sum = 0;
            for (int n : cardPoints) sum += n;
            return sum;
        }
        int n = cardPoints.size();
        int sum = 0;
        int res = 0;
        int first = 0;
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];
            if (i == n - k - 1) {
                first = sum;
            }
        }
        res = sum - first;
        for (int i = n - k; i < n; i++) {
            first -= cardPoints[i - (n - k)];
            first += cardPoints[i];
            res = max(res, sum - first);
        }
        return res;
    }
};
