/*
 * leetcode 226 invert
 *
 * binary tree template
 *
 */

class Solution {
public:
    // the same idea as maxDepth problem
    // recursive
    // think about the current level only
    void invert(TreeNode* root) {
        // base condition or stop condition
        // if null, no need to invert
        if (!root) {
            return;
        }
        // 
        invert(root->left);
        invert(root->right);
        
        // 
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

/*

https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/1413111/yi-tao-mo-ban-jie-jue-duo-ge-by-zhang-xi-yqep/

*/

