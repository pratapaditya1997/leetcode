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
    vector<int> one, two, ans;
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1, 1);
        dfs(root2, 2);
        merge();
        return ans;
    }
    
    void merge() {
        int n = one.size(), m = two.size();
        int i=0, j=0;
        while(i<n && j<m) {
            if(one[i] <= two[j]) ans.push_back(one[i++]);
            else ans.push_back(two[j++]);
        }
        while(i<n) ans.push_back(one[i++]);
        while(j<m) ans.push_back(two[j++]);
    }
    
    void dfs(TreeNode* node, int type) {
        if(node == nullptr) return;
        dfs(node->left, type);
        if(type == 1) one.push_back(node->val);
        else two.push_back(node->val);
        dfs(node->right, type);
    }
};
