/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int INF = 1e5;

class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int ans;
    
    void dfs(TreeNode* v) {
        int res = -INF;
        if (v->left) {
            dfs(v->left);
            res = dp[v->left];
        }
        if (v->right) {
            dfs(v->right);
            res = max(res, dp[v->right]);
        }
        dp[v] = max(res + v->val, v->val);
        int val = max(dp[v->left] + dp[v->right] + v->val, dp[v->left] + v->val);
        val = max(val, dp[v->right] + v->val);
        val = max(val, v->val);
        ans = max(ans, val);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = -INF;
        dfs(root);
        return ans;
    }
};
