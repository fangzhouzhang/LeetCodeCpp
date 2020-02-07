//
// Created by Fangzhou Zhang on 2020/2/6.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        if (!root) return res;
        unordered_map<string, int> map;
        dfs(root, res, map);
        return res;
    }

private:
    string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& map) {
        if (!root) return "#";
        string key = to_string(root->val) + "," + dfs(root->left, res, map) + "," + dfs(root->right, res, map);
        map[key]++;
        if (map[key] == 2) res.push_back(root);
        return key;
    }
};
