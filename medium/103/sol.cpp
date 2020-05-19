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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool dir = 0;
        
        stack<TreeNode*> cur, next;
        if(root) cur.push(root);
        while(!cur.empty()) {
            vector<int> v;
            while(!cur.empty()) {
                TreeNode* cur_node = cur.top(); cur.pop();
                v.push_back(cur_node->val);
                if(!dir) {
                    if(cur_node->left) next.push(cur_node->left);
                    if(cur_node->right) next.push(cur_node->right);
                } else {
                    if(cur_node->right) next.push(cur_node->right);
                    if(cur_node->left) next.push(cur_node->left);
                }
            }
            ans.push_back(v);
            dir = 1 - dir;
            swap(cur, next);
        }
        return ans;
    }
};
