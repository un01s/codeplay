/*
 * leetcode 102
 *
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> que;
        // store the root to the queue for traversal
        if (root != nullptr) que.push(root);
  
        while (!que.empty()) {
            int qSize = que.size();
            vector<int> tmp;
            for (int i = 0; i < qSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                tmp.push_back(node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};
