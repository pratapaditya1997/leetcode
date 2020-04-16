/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    set<int> s;
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete) s.insert(i);
        helper(root, true);
        return ans;
    }
    
    TreeNode* helper(TreeNode* node, bool is_own_root) {
        if(node == nullptr) return nullptr;
        bool to_delete = false;
        if(s.find(node->val) != s.end()) to_delete = true;
        if(is_own_root && !to_delete) {
            ans.push_back(node);
        }
        node->left = helper(node->left, to_delete);
        node->right = helper(node->right, to_delete);
        if(to_delete) return nullptr;
        return node;
    }
};
