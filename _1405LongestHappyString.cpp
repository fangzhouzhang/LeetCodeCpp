//
// Created by Fangzhou Zhang on 2020/4/20.
//
class Solution {
public:
    string res;
    string longestDiverseStringDFS(int a, int b, int c) {
        vector<vector<vector<vector<int>>>> dp(3, vector<vector<vector<int>>>(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, -1))));
        string tmp;
        int d = dfs(a, b, c, tmp,dp, 0);
        gene_str(d, a, b, c, dp);
        return res;
    }

    void gene_str(int d, int a, int b, int c, vector<vector<vector<vector<int>>>> &dp) {
        if (d == 0) return;
        if (a > 0 && dp[0][a - 1][b][c] + 1 == d) {
            res.push_back('a');
            gene_str(d - 1, a - 1, b, c, dp);
        } else if (b > 0 && dp[1][a][b - 1][c] + 1 == d) {
            res.push_back('b');
            gene_str(d - 1, a, b - 1, c, dp);
        } else {
            res.push_back('c');
            gene_str(d - 1, a, b, c - 1, dp);
        }
    }

    int dfs(int a, int b, int c, string &tmp, vector<vector<vector<vector<int>>>> &dp, int cur) {
        if (a < 0 || b < 0 || c < 0) return 0;
        if (dp[cur][a][b][c] != -1) return dp[cur][a][b][c];
        int ret = 0;
        int n = tmp.size();
        int v0 = 0, v1 = 0, v2 = 0;
        if (a > 0) {
            if (tmp.size() > 1 && tmp[n - 1] == tmp[n - 2] && tmp[n - 1] == 'a') {

            } else {
                tmp.push_back('a');
                v0 = dfs(a - 1, b, c, tmp, dp, 0) + 1;
                ret = max(ret, v0);
                tmp.pop_back();
            }
        }
        if (b > 0) {
            if (tmp.size() > 1 && tmp[n - 1] == tmp[n - 2] && tmp[n - 1] == 'b') {

            } else {
                tmp.push_back('b');
                v1 = dfs(a, b - 1, c, tmp, dp, 1) + 1;
                ret = max(ret, v1);
                tmp.pop_back();
            }
        }
        if (c > 0) {
            if (tmp.size() > 1 && tmp[n - 1] == tmp[n - 2]  && tmp[n - 1] == 'c') {

            } else {
                tmp.push_back('c');
                v2 = dfs(a, b, c - 1, tmp, dp, 2) + 1;
                ret = max(ret, v2);
                tmp.pop_back();
            }
        }

        return dp[cur][a][b][c] = ret;
    }

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        if (a > 0) pq.push(make_pair('a', a));
        if (b > 0) pq.push(make_pair('b', b));
        if (c > 0) pq.push(make_pair('c', c));
        bool end = false;
        while (!end && !pq.empty()) {
            pair<char, int> cur = pq.top();
            pq.pop();
            int n = res.size();
            if (res.size() > 1 && res[n - 1] == res[n - 2] && res[n - 1] == cur.first) {
                if (pq.size() > 0) {
                    pair<char, int> another = pq.top();
                    pq.pop();

                    res.push_back(another.first);
                    another.second--;
                    if (another.second > 0) pq.push(another);
                    if (cur.second > 0) pq.push(cur);
                } else end = true;
            } else {
                res.push_back(cur.first);
                cur.second--;
                if (cur.second > 0) pq.push(cur);
            }
        }
        return res;
    }
};
