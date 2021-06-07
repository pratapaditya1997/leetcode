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
    int h;
    
    int f(TreeNode* v) {
        if (v == nullptr) return -1;
        int lh = f(v->left);
        int rh = f(v->right);
        return max(lh, rh) + 1;
    }
    
    bool check(TreeNode* v, int i, int mask) {
        if (i == -1) return true;
        
        int go_right = mask & (1<<i);
        if (go_right) {
            if (v->right) return check(v->right, i-1, mask);
            return false;
        } else {
            if (v->left) return check(v->left, i-1, mask);
            return false;
        }
    }
    
    int countNodes(TreeNode* root) {
        h = f(root);
        if (h == -1) return 0;
        if (h == 0) return 1;
        
        int l = 0, r = (1<<h) - 1, ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(root, h-1, m)) {
                l = m + 1;
                ans = m;
            } else r = m - 1;
        }
        
        if (ans == (1<<h) - 1) return (1<<(h+1)) - 1;
        
        for (int i=0; i<h; ++i) {
            ans += (1<<i);
        }
        return ans + 1;
    }
};
