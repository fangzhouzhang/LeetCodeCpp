//
// Created by Fangzhou Zhang on 2020/2/14.
//
class TrieNode {
public:
    bool isEnd;
    TrieNode *children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
        isEnd = false;
    }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (cur->children[c - 'a'] == NULL) cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (cur->children[c - 'a'] == NULL) return false;
            cur = cur->children[c - 'a'];
        }
        return cur->isEnd == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix[i];
            if (cur->children[c - 'a'] == NULL) return false;
            cur = cur->children[c - 'a'];
        }
        return true;
    }

};
