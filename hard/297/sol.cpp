/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return f(data);
    }
    
    TreeNode* f(string& data) {
        if (data[0] == '#') {
            if (data.size() > 1) data.erase(0, 2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = f(data);
            node->right = f(data);
            return node;
        }
    }
    
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data.erase(0, pos+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
