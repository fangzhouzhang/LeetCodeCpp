//
// Created by Fangzhou Zhang on 2020/4/12.
//
class Solution {
public:
    string entityParser(string text) {
        if (text.size() == 0) return "";
        string res;
        int idx = 0;
        while (idx < text.size()) {
            char c = text[idx];
            if (c == '&') {

                if (idx + 6 < text.size() && text[idx + 1] == 'f' && text[idx + 2] == 'r' && text[idx + 3] == 'a' && text[idx + 4] == 's' && text[idx + 5] == 'l' && text[idx + 6] == ';') {
                    res.push_back('\/');
                    idx = idx + 7;
                }

                else if (idx + 5 < text.size() && text[idx + 1] == 'a' && text[idx + 2] == 'p' && text[idx + 3] == 'o' && text[idx + 4] == 's'&& text[idx + 5] == ';') {
                    res.push_back('\'');
                    idx = idx + 6;
                }
                else if (idx + 5 < text.size() && text[idx + 1] == 'q' && text[idx + 2] == 'u' && text[idx + 3] == 'o' && text[idx + 4] == 't'&& text[idx + 5] == ';') {
                    res.push_back('\"');
                    idx = idx + 6;
                }


                else if (idx + 4 < text.size() && text[idx + 1] == 'a' && text[idx + 2] == 'm' && text[idx + 3] == 'p'&& text[idx + 4] == ';') {
                    res.push_back('&');
                    idx = idx + 5;
                }



                else if (idx + 3 < text.size() && text[idx + 1] == 'g' && text[idx + 2] == 't' && text[idx + 3] == ';') {
                    res.push_back('>');
                    idx = idx + 4;
                }
                else if (idx + 3 < text.size() && text[idx + 1] == 'l' && text[idx + 2] == 't' && text[idx + 3] == ';') {
                    res.push_back('<');
                    idx = idx + 4;
                }
                else {

                    res.push_back(text[idx]);
                    idx++;

                }
            } else {

                res.push_back(text[idx]);
                idx++;

            }
        }
        return res;
    }
};
