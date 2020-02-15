//
// Created by Fangzhou Zhang on 2020/2/15.
//
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.size() == 0) return res;
        int n = words.size();
        int idx = 0;
        while (idx < n) {
            int chars = words[idx].size();
            int next = idx + 1;
            while (next < n && chars + 1 + words[next].size() <= maxWidth) {
                chars += 1 + words[next].size();
                next++;
            }
            //number of word gaps in one line
            int num_of_word_gap = next - 1 - idx;
            string str = words[idx];
            if (next == n || num_of_word_gap == 0) {
                //it means this is last line or this line can only hold one word
                for (int k = idx + 1; k < next; k++) {
                    str += ' ';
                    str += words[k];
                }
                for (int l = 0; l < maxWidth - chars; l++) str.push_back(' ');
            } else {
                int min_avg_space = (maxWidth - chars) / num_of_word_gap + 1;
                int num_of_gaps_take_more_space = (maxWidth - chars) % num_of_word_gap;
                int k = idx + 1;
                for (int i = 0; i < num_of_gaps_take_more_space; i++) {
                    for (int l = 0; l < min_avg_space + 1; l++) str.push_back(' ');
                    str += words[k++];
                }
                while (k < next) {
                    for (int l = 0; l < min_avg_space; l++) str.push_back(' ');
                    str += words[k++];
                }
            }
            res.push_back(str);
            idx = next;
        }
        return res;
    }
};
