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
    map<pair<TreeNode*,int>,int> best;
    
    int longestZigZag(TreeNode* root) {
        return helper2(root)-1;
    }
    
    int helper2(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = max(helper(root,0), helper(root,1));
        ans = max({ans,helper2(root->left), helper2(root->right)});
        return ans;
    }
    
    int helper(TreeNode *node, int isRight) {
        if(node == nullptr) return 0;
        if(best.find({node,isRight}) != best.end()) {
            return best[{node, isRight}];
        }
        int val;
        if(isRight) {
            val = helper(node->right, 0)+1;
        } else {
            val = helper(node->left, 1)+1;
        }
        best[{node, isRight}] = val;
        return val;
    }
};
