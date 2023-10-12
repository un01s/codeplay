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

// 
// get the depth first
//
class Solution {
public:
    int depth(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int left = depth(cur->left);
        int right = depth(cur->right);
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = depth(root->left);
        int right = depth(root->right);

        return abs(left-right)<2 && isBalanced(root->left) && isBalanced(root->right);
    }
};
