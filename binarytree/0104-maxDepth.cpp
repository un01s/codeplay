/*
 * leetcode 104
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// concise, recursive
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// expand to make it clear
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        // after-order traversal
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        return max(l_depth, r_depth) + 1;
    }
};

// template
class Solution {
public:
    // at one level of the recursive, just think about this level
    // just this level
    int depth(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int l = depth(cur->left);
        int r = depth(cur->right);
        return max(l, r) + 1;
    }
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};
