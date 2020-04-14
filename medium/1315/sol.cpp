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
    
    void dfs(TreeNode* node,int baap, int dada) {
        if(node == nullptr) return;
        if(baap > 0 && dada > 0 && dada%2 == 0) {
            ans += node->val;
        }
        dfs(node->left, node->val, baap);
        dfs(node->right, node->val, baap);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, -1, -1);
        return ans;
    }
};
