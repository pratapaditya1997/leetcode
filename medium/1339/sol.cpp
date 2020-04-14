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
    const long mod = 1e9+7;
    
    long total = 0, ans = 0;
    
    void dfs(TreeNode* node) {
        if(node == nullptr) return;
        total += node->val;
        dfs(node->left);
        dfs(node->right);
    }
    
    int helper(TreeNode* node) {
        if(node == nullptr) return 0;
        int sum_left = helper(node->left);
        int sum_right = helper(node->right);
        ans = max(ans, sum_left * (total - sum_left));
        ans = max(ans, sum_right * (total - sum_right));
        return sum_left + sum_right + node->val;
    }
    
    int maxProduct(TreeNode* root) {
        dfs(root);
        helper(root);
        return ans%mod;
    }
};
