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
    int longestZigZag(TreeNode* root) {
        helper(root,0);
        helper(root,1);
        return ans;
    }
    
    int helper(TreeNode *node, int isRight) {
        if(node == nullptr) return -1;
        if(node->left == nullptr && node->right == nullptr) return 0;
        
        int leftValue = helper(node->left, 0);
        int rightValue = helper(node->right, 1);
        ans = max({ans, 1+leftValue, 1+rightValue});
        if(isRight) {
            return leftValue+1;
        } else {
            return rightValue+1;
        }
    }
};
