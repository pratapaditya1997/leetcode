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
    int ans = 0;
    
    bool check(vector<int>& cnt) {
        int count_odd = 0;
        for(int i: cnt) if(i&1) count_odd++;
        return (count_odd <= 1);
    }
    
    void dfs(TreeNode* node, vector<int>& cnt) {
        if(node == nullptr) return;
        cnt[node->val]++;
        if(!node->left && !node->right && check(cnt)) ans++;
        dfs(node->left, cnt);
        dfs(node->right, cnt);
        cnt[node->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10,0);
        dfs(root, cnt);
        return ans;
    }
};
