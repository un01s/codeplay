/*
 * LCR 174
 * return the kth big node from a binary tree
 * 
 */

class Solution {
private:
    priority_queue<int, vector<int>, greater<int> > que_;
    int k_; 
public:
    // DFS, just think about the current level you are at
    //
    void dfs(TreeNode* cur) {
        if (!cur) return;
        // pre-order travesal
        // current root node
        if (que_.size() ! = k_) {
            que_.push(cur->val);
        } else {
            // only when current val greater than the smallest, update
            // so that the queue always has the largest k values
            if (cur->val > que_.top()) {
                que_.pop();
                que_.push(cur->val);
            }
        }
        //
        dfs(cur->left);
        dfs(cur->right);
    }
    int kthLargest(TreeNode* root, int k) {
        k_ = k;
        dfs(root);
        return que_.top();
    }
};
