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
    int max_height = 0;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        max_height = calcMaxHeight(root);
        return dfs(root,1);
    }
    
    TreeNode* dfs(TreeNode* node, int height) {
        if(node == nullptr) return nullptr;
        if(height == max_height) return node;
        TreeNode* left = dfs(node->left, height+1);
        TreeNode* right = dfs(node->right, height+1);
        if(left != nullptr && right != nullptr) return node;
        if(left != nullptr) return left;
        return right;
    }
    
    int calcMaxHeight(TreeNode* node) {
        if(node == nullptr) return 0;
        return 1 + max(calcMaxHeight(node->left), calcMaxHeight(node->right));
    }
};
