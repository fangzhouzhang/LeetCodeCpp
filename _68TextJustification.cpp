//
// Created by Fangzhou Zhang on 2020/2/15.
//
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.size() == 0) return res;
        int idx = 0;
        while (idx < words.size()) {
            int chars = words[idx].size();
            int next = idx + 1;
            while ( next < words.size() && chars + 1 + words[next].size() <= maxWidth) {
                chars = chars + 1 + words[next].size();
                next++;
            }
            string line;
            line += words[idx];
            if (next == words.size() || next - idx == 1) {
                //it means this is last line or this line can only hold one word
                for (int i = idx + 1; i < next; i++) {
                    line.push_back(' ');
                    line += words[i];
                }
                while (line.size() < maxWidth) line.push_back(' ');
            } else {
                int gaps = next - idx - 1;
                int avg = (maxWidth - chars) / gaps;
                int size = (maxWidth - chars) % gaps;
                int cnt = 0, i = idx + 1;
                while (cnt < size) {
                    int k = 2 + avg;
                    while (k > 0) {
                        line.push_back(' ');
                        k--;
                    }
                    line += words[i++];
                    cnt++;
                }
                while (i < next) {
                    int k = 1 + avg;
                    while (k > 0) {
                        line.push_back(' ');
                        k--;
                    }
                    line += words[i++];
                }
            }
            res.push_back(line);
            idx = next;
        }
        return res;
    }
};