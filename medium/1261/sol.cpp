/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int> s;
    
    void dfs(TreeNode* node, int x) {
        if(node == nullptr) return;
        node->val = x;
        s.insert(x);
        dfs(node->left, 2*x+1);
        dfs(node->right, 2*x+2);
    }
    
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
