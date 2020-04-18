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
    int max_level = -1;
    vector<int> level_sum;
    
    int maxLevelSum(TreeNode* root) {
        dfs(root,0);
        int ans = 0, best = 0;
        for(int i=0; i<max_level; i++) {
            if(level_sum[i] > best) {
                best = level_sum[i];
                ans = i+1;
            }
        }
        return ans;
    }
    
    void dfs(TreeNode* node, int level) {
        if(node == nullptr) return;
        if(level > max_level) {
            max_level = level;
            level_sum.push_back(0);
        }
        level_sum[level] += node->val;
        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }
};

