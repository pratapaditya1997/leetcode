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
    TreeNode* ans = nullptr;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ans = nullptr;
        helper(original, cloned, target);
        return ans;
    }
    
    void helper(TreeNode* a, TreeNode* b, TreeNode* c) {
        if(ans != nullptr) return;
        if(a == c) {
            ans = b;
            return;
        }
        if(a->left != nullptr) helper(a->left, b->left, c);
        if(a->right != nullptr) helper(a->right, b->right, c);
        return;
    }
};
