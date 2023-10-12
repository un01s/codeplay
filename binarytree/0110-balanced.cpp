/*
 * leetcode 110 
 * balanced binary tree
 *
 */

class Solution {
public:
    int f(TreeNode* cur) {
        if (cur == nullptr) return 0;

        int left = f(cur->left);
        if (left == -1) return -1;

        int right = f(cur->right);
        if (right == -1) return -1;

        return abs(left-right) < 2 ? max(left, right)+1 : -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return f(root) != -1;
    }
};

