//
// Created by Fangzhou Zhang on 2020/3/19.
//
class Trie{
public:
    Trie *children[26];
    int count = 1;
    Trie() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        Trie *root = new Trie();
        function<void(string)> buildTrie = [&](string s){
            Trie *cur = root;
            for (int i = 0; i < s.size(); i++) {
                int idx = s[i] - 'a';
                if (cur->children[idx] == NULL) cur->children[idx] = new Trie();
                else cur->children[idx]->count++;
                if (cur->children[idx]->count == n) res.push_back(s[i]);
                cur = cur->children[idx];
            }
        };
        for (string &s : strs) buildTrie(s);
        return res;
    }
};
