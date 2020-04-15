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
    int ans = 0;
    
    pair<int,int> dfs(TreeNode* node) {
        if(node == nullptr) return {INT_MAX,0};
        pair<int,int> p_left = dfs(node->left);
        pair<int,int> p_right = dfs(node->right);
        pair<int,int> p_cur;
        p_cur.first = min({p_left.first, p_right.first, node->val});
        p_cur.second = max({p_left.second, p_right.second, node->val});
        ans = max(ans, node->val - p_cur.first);
        ans = max(ans, p_cur.second - node->val);
        return p_cur;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
