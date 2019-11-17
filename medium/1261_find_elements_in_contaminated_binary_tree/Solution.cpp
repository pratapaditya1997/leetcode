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
    set<int> s;
    
    void traverse(TreeNode* node,int x) {
        if(node == nullptr) return;
        node->val = x;
        s.insert(x);
        if(node->left != nullptr) traverse(node->left, 2*x+1);
        if(node->right != nullptr) traverse(node->right, 2*x+2);
    }
public:
    FindElements(TreeNode* root) {
        traverse(root, 0);
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
