//
// Created by Fangzhou Zhang on 2020/4/14.
//
class State {
public:
    vector<vector<int>> b;
    int x;
    int y;
    State(const vector<vector<int>>& board, int row, int col) {
        b.resize(2, vector<int>(3, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = board[i][j];
            }
        }
        x = row;
        y = col;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        unordered_set<string> set;
        queue<State*> q;
        State *state = new State(board, x, y);
        q.push(state);
        string init;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                init.push_back(board[i][j] + '0');
            }
        }
        set.insert(init);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                State *cur = q.front();
                vector<vector<int>> b = cur->b;
                if (valid(b)) return res;
                q.pop();
                int r = cur->x;
                int c = cur->y;
                for (vector<int> dir : dirs) {
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];
                    if (new_r >= 0 && new_r < 2 && new_c >= 0 && new_c < 3) {
                        int tmp = b[new_r][new_c];
                        b[new_r][new_c] = b[r][c];
                        b[r][c] = tmp;
                        string cur_arr;
                        for (int i = 0; i < 2; i++) {
                            for (int j = 0; j < 3; j++) {
                                cur_arr.push_back(b[i][j] + '0');
                            }
                        }
                        if (set.find(cur_arr) == set.end()) {
                            State *new_state = new State(b, new_r, new_c);
                            q.push(new_state);
                            set.insert(cur_arr);
                        }
                        b[new_r][new_c] = tmp;
                        b[r][c] = 0;
                    }
                }
            }
            res++;
        }
        return -1;
    }

    bool valid(vector<vector<int>> a) {
        int val = 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] != val) {
                    return false;
                } else {
                    val++;
                    if (val == 6) val = 0;
                }
            }
        }
        return true;
    }
};
