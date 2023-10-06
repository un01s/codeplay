/*
 * leetcode 113 path sum II
 *
 * find all the paths from the root to the leaf whose sum equals to the target
 *
 */

class Solution {
private:
    int targetSum_{0};
    vector<vector<int> > res_{}; 
public:
    void pathSum(TreeNode* cur, vector<int> vec, int sum) {
        // if current node is a leaf, check with targetSum and update vec
        if (!cur->left && !cur->right) {
            if ((sum + cur->val) == targetSum_) {
                vec.emplace_back(cur->val);
                res_.emplace_back(vec);
            }
        }
        // 
        if (cur->left) {
            vector<int> tmp{vec};
            tmp.emplace_back(cur->val);
            pathSum(cur->left, tmp, sum+cur->val);
        }
        if (cur->right) {
            vec.emplace_back(cur->val);
            pathSum(cur->right, vec, sum+cur->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        targetSum_ = targetSum;
        if (!root) return res_;
        int sum{0};
        vector<int> vec{};
        pathSum(root, sum);
        return res_;
    }
};

