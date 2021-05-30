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
    unordered_map<TreeNode*, int> lis;
    unordered_map<TreeNode*, int> lds;
    
    void dfs_lis(TreeNode* node) {
        int val = 0; 
        if (node->left) {
            dfs_lis(node->left);
            if (node->left->val == node->val + 1) {
                val = max(val, lis[node->left]);
            }
        }
        if (node->right) {
            dfs_lis(node->right);
            if (node->right->val == node->val + 1) {
                val = max(val, lis[node->right]);
            }
        }
        lis[node] = val + 1;
    }
    
    void dfs_lds(TreeNode* node) {
        int val = 0;
        if (node->left) {
            dfs_lds(node->left);
            if (node->left->val == node->val - 1) {
                val = max(val, lds[node->left]);
            }
        }
        if (node->right) {
            dfs_lds(node->right);
            if (node->right->val == node->val - 1) {
                val = max(val, lds[node->right]);
            }
        }
        lds[node] = val + 1;
    }
    
    void dfs_merge(TreeNode* node, TreeNode* par) {
        if (node->val == par->val + 1) {
            lds[node] = max(lds[node], lds[par] + 1);
        } else if (node->val == par->val - 1) {
            lis[node] = max(lis[node], lis[par] + 1);
        }
        if (node->left) dfs_merge(node->left, node);
        if (node->right) dfs_merge(node->right, node);
    }
    
    int longestConsecutive(TreeNode* root) {
        dfs_lis(root);
        dfs_lds(root);
        if (root->left) dfs_merge(root->left, root);
        if (root->right) dfs_merge(root->right, root);
        
        int ans = 1;
        for (auto& p: lis) ans = max(ans, p.second);
        for (auto& p: lds) ans = max(ans, p.second);
        return ans;
    }
};
