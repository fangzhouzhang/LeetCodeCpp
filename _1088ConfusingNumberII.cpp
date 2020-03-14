//
// Created by Fangzhou Zhang on 2020/3/14.
//
class Solution {
public:
    vector<int> nums {0,1,6,8,9};
    vector<int> flip {0,1,-1,-1,-1,-1,9,-1,8,6};
    int confusingNumberII(int N) {
        int t = N, len = 0;
        while (t > 0) {
            t /= 10;
            len++;
        }
        queue<long> q;
        q.push(1);
        q.push(6);
        q.push(8);
        q.push(9);
        int res = 0;
        for (int i = 1; i <= len; i++) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                long cur = q.front();
                q.pop();
                long rev = reverse(cur);
                if (rev != cur) res++;
                for (int j = 0; j < 5; j++) {
                    long sum = cur * 10 + nums[j];
                    if (sum <= N) q.push(sum);
                }
            }
        }
        return res;
    }

    long reverse(long n) {
        long ret = 0;
        while (n > 0) {
            long bit = n % 10;
            n /= 10;
            ret = ret * 10 + flip[bit];
        }
        return ret;
    }
};
