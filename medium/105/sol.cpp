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
    int cur_idx;
    map<int, int> inorder_map;
    
    TreeNode* f(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        
        int cur_root_val = preorder[cur_idx++];
        TreeNode* node = new TreeNode(cur_root_val);
        
        node->left = f(preorder, l, inorder_map[cur_root_val] - 1);
        node->right = f(preorder, inorder_map[cur_root_val] + 1, r);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        cur_idx = 0;
        inorder_map.clear();
        
        int n = inorder.size();
        for (int i=0; i<n; ++i) {
            inorder_map[inorder[i]] = i;
        }
        return f(preorder, 0, n-1);
    }
};
