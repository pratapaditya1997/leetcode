/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class FindElements {
    private HashMap<Integer, Integer> mp;
    
    private void traverse(TreeNode node, int x) {
        if(node == null) return;
        node.val = x;
        mp.put(x, 1);
        if(node.left != null) traverse(node.left, 2*x+1);
        if(node.right != null) traverse(node.right, 2*x+2);
    }
    
    public FindElements(TreeNode root) {
        mp = new HashMap<Integer, Integer>();
        traverse(root, 0);
    }
    
    public boolean find(int target) {
        return mp.containsKey(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
