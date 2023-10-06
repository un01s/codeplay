/*
 * 572 subtree of another tree
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

    bool res = false;
    void subTree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return;
        if (sameTree(root, subRoot)) res = true;

        // check current left and right subtrees
        subTree(root->left, subRoot);
        subTree(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subTree(root, subRoot);
        return res;
    }
};
