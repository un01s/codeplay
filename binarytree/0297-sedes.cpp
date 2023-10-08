/*
 * leetcode 297
 * serialize and deserialize a binary tree
 * 
 * level traversal, use N to represent NULL
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        sf(root, res)
        return res;        
    }

    void sf(TreeNode* root, string& res) {
        if (root == nullptr) {
            if (res.size() == 0) {
                res += "N";
                return;
            } else {
                res += ",N";
                return;
            }
        }
        if (res.size() == 0) {
            res += to_string(root->val);
        } else {
            res += ",";
            res += to_string(root->val);
        }
        sf(root->left, res);
        sf(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string tmp;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ",") {
                nodes.push_back(tmp);
                tmp.clear();
            } else {
                tmp += data[i];
            }
        }    
        if (tmp.size()) {
            nodes.push_back(tmp);
        }
        int index = 0;
        TreeNode* root = deserializefun(nodes, index);
        return root;
    }
    TreeNode* deserializefun(vector<string>& nodes, int& index) {
        if (nodes[index] == "N") {
            ++index;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(nodes[index]));
        ++index;
        node->left = deserialize_help(nodes, index);
        node->right = deserialize_help(nodes, index);
        return node;
    }
};

