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
class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* node, int cur_max) {
        if(node == nullptr) return;
        if(node->val >= cur_max) ans++;
        cur_max = max(cur_max, node->val);
        dfs(node->left, cur_max);
        dfs(node->right, cur_max);
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return ans;
    }
};
