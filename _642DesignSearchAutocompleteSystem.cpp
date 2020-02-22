//
// Created by Fangzhou Zhang on 2020/2/21.
//
class TrieNode{
public:
    TrieNode *children[128];
    vector<TrieNode*> hot;
    bool isEnd;
    string word;
    int times;
    TrieNode(){
        for (int i = 0; i < 128; i++) children[i] = NULL;
        isEnd = false;
        times = 0;
    }
};

bool cmp(const TrieNode* a, const TrieNode* b) {
    if (a->times != b->times) return b->times < a->times;
    return a->word < b->word;
}

class AutocompleteSystem {
private:
    TrieNode* root;
    TrieNode* current;
    string sb = "";
    void buildTrie(string sentence, int times) {
        TrieNode* cur = root;
        vector<TrieNode*> paths;
        for (int i = 0; i < sentence.size(); i++) {
            int c = sentence[i];
            if (cur->children[c] == NULL) cur->children[c] = new TrieNode();
            paths.push_back(cur->children[c]);
            cur = cur->children[c];
        }
        cur->word = sentence;
        cur->times += times;
        for (int i = 0; i < paths.size(); i++) {
            if (find(paths[i]->hot.begin(), paths[i]->hot.end(), cur) == paths[i]->hot.end()) paths[i]->hot.push_back(cur);
            sort(paths[i]->hot.begin(), paths[i]->hot.end(), cmp);
            if (paths[i]->hot.size() > 3) paths[i]->hot.pop_back();
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        current = root;
        for (int i = 0; i < sentences.size(); i++) {
            buildTrie(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        vector<string> res;
        // return res;
        if (c == '#') {
            buildTrie(sb, 1);
            sb = "";
            current = root;
            return res;
        } else {
            sb += c;
            if (current == NULL) {
                return res;
            }
            current = current->children[c];
            if (current == NULL) {
                return res;
            }
            for (auto& node : current->hot) res.push_back(node->word);
            return res;
        }
    }
};
