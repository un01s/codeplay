/*
 * leetcode 111
 * minDepth
 *
 * binary tree recursive template
 * 
 */

class Solution {
public:
    int depth(TreeNode* cur) {
        if (cur == nullptr) return 0;
        if (cur->letf == nullptr && cur->right == nullptr) return 1;
        int minnum = INT_MAX;
        if (cur->left) minnum = min(depth(cur->left), minnum);
        if (cur->right) minnum = min(depth(cur->right), minnum);
        return minnum;
    }

    int minDepth(TreeNode* root) {
        return depth(root);    
    }
};
