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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) { 
        TreeNode* x_node = find(root, x);
        int m1 = n - dfs(x_node);
        int m2 = dfs(x_node->left);
        int m3 = dfs(x_node->right);
        if(max({m1,m2,m3}) > n/2) return true;
        return false;
    }
    
    TreeNode* find(TreeNode* node, int x) {
        if(node == nullptr) return nullptr;
        if(node->val == x) return node;
        else {
            TreeNode* left = find(node->left, x);
            TreeNode* right = find(node->right, x);
            if(left != nullptr) return left;
            return right;
        }
    }
    
    int dfs(TreeNode* node) {
        if(node == nullptr) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        return 1+l+r;
    }
};
