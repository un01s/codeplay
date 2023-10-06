/*
 * leetcode 100
 * same tree
 *
 */

class Solution {
public:
    bool sameTree(TreeNode* p, TreeNode* q) {
        // if both empty, they are the same
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else if (p->val != q->val) return false;
        else {
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return sameTree(p, q);
    }
};
