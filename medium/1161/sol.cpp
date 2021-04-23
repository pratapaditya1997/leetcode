/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int N = 1e4 + 4;
int level_sum[N];

class Solution {
public:
    int max_level = -1;
    
    int maxLevelSum(TreeNode* root) {
        memset(level_sum, 0, sizeof level_sum);
        dfs(root,0);
        int ans = 0, best = INT_MIN;
        for(int i=0; i<max_level; i++) {
            if(level_sum[i] > best) {
                best = level_sum[i];
                ans = i+1;
            }
        }
        return ans;
    }
    
    void dfs(TreeNode* node, int level) {
        max_level = max(max_level, level);
        if(node == nullptr) return;
        level_sum[level] += node->val;
        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }
};
