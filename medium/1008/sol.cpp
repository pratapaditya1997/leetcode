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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return helper(preorder,0,n-1);
    }
    
    TreeNode* helper(vector<int>& pre,int l, int r) {
        if(l>r) return nullptr;
        TreeNode* node = new TreeNode(pre[l]);
        if(l==r) return node;
        
        int i=0;
        for(i=l; i<=r; i++) {
            if(pre[i] > pre[l]) break;
        }
        node->left = helper(pre, l+1, i-1);
        node->right = helper(pre, i, r);
        return node;
    }
};
