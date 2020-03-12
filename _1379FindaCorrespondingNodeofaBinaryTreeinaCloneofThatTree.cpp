//
// Created by Fangzhou Zhang on 2020/3/11.
//
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> map;
        traverse(map, original, cloned);
        return map[target];
    }

    void traverse(unordered_map<TreeNode*, TreeNode*> &map, TreeNode* original, TreeNode* cloned) {
        if (original == NULL) return;
        map[original] = cloned;
        traverse(map, original->left, cloned->left);
        traverse(map, original->right, cloned->right);
    }
};
