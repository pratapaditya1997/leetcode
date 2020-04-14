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
    int cur_max = 0;
    int ans = 0;
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    
    void dfs(TreeNode* node, int height) {
        if(node == nullptr) return;
        if(height == cur_max) ans += node->val;
        if(height > cur_max) {
            ans = node->val;
            cur_max = height;
        }
        dfs(node->left, height+1);
        dfs(node->right, height+1);
    }
};
