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
    int i = 0;
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MIN, INT_MAX);
    }
    
    TreeNode* helper(vector<int>& pre, int low, int high) {
        if(i == pre.size() || pre[i] > high || pre[i] < low) return nullptr;
        TreeNode* node = new TreeNode(pre[i++]);
        node->left = helper(pre, low, node->val);
        node->right = helper(pre, node->val, high);
        return node;
    }
};
