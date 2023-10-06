/*
 * leetcode 543
 * diameter: the longest length between two nodes.
 * it may not go through the root node.
 * 
 * the length between two nodes is the numbder of edges connecting both.
 *
 */

class Solution {
public:
    int max_depth = 0;
    int depth(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int l = depth(cur->left);
        int r = depth(cur->right);
        // the sum of max depth of left sub and max depth of right sub
        // is the diameter of current tree.
        max_depth = max(max_depth, l+r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_depth;
    }
};

