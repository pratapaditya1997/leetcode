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
    vector<int> ans;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return ans;
    }
    
    // # vertices between node & target
    int dfs(TreeNode* node, TreeNode* target, int k) {
        if(node == nullptr) return -1;
        else if(node == target) {
            subtree_add(node, 0, k);
            return 1;
        } else {
            int left = dfs(node->left, target, k);
            int right = dfs(node->right, target, k);
            if(left != -1) {
                if(left == k) ans.push_back(node->val);
                subtree_add(node->right, left + 1, k);
                return left + 1;
            } else if(right != -1) {
                if(right == k) ans.push_back(node->val);
                subtree_add(node->left, right + 1, k);
                return right + 1;
            } else return -1;
        }
    }
    
    // dist - distance covered so far from target
    void subtree_add(TreeNode* node, int dist, int k) {
        if(node == nullptr) return;
        if(dist == k) ans.push_back(node->val);
        else {
            subtree_add(node->left, dist + 1, k);
            subtree_add(node->right, dist + 1, k);
        }
    }
};
