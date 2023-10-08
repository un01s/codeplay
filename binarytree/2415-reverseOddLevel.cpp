/*
 * leetcode 2415
 * reverse odd level of a binary tree 
 * 
 * a perfect binary tree:
 * A binary tree is perfect if all parent nodes have two children and 
 * all leaves are on the same level.
 */

class Solution {
public:
    void dfs(TreeNode* l, TreeNode* r, int level) {
        if (l == nullptr || r == nullptr) return;
        if (level%2 == 1) swap(l->val, r->val);
        level++;
        dfs(l->left, r->right, level);
        dfs(l->right, r->left, level);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;    
    }
};

