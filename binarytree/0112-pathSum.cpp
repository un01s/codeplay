/*
 * leetcode 112 path sum
 *
 */

class Solution {
private:
    bool res_ {false};
    int targetSum_;
public:
    void pathSum(TreeNode* cur, int sum) {
        // when current node is a leaf, compare sum and targetSum_
        if (cur->left && !cur->right) {
            sum += cur->val;
            if (sum == targetSum_) res_ = true;
        }
        // if left subtree is not empty, compute its pathsum
        if (cur->left) {
            pathSum(cur->left, sum+cur->val);
        }
        // if right subtree is not empty,
        if (cur->right) {
            pathSum(cur->right, sum+cur->val);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        targetSum_ = targetSum;
        if (!root) return false;
        pathSum(root, 0);
        return res_;    
    }
};
