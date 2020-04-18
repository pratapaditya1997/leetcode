class Solution {
public:
    bool ok = true;
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parCount(n,0);
        int edges = 0;
        
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1) {
                parCount[leftChild[i]]++;
                edges++;
            }
            if(rightChild[i] != -1) {
                parCount[rightChild[i]]++;
                edges++;
            }
        }
        
        int noParent = 0, root = 0;
        for(int i=0; i<n; i++) {
            if(parCount[i] > 1) return false;
            if(!parCount[i]) {
                noParent++;
                root = i;
            }
        }
        
        if(edges != n-1) return false;
        
        vector<int> vis(n,0);
        dfs(root, leftChild, rightChild, vis);
        
        if(!ok) return false;
        for(int i=0; i<n; i++) if(vis[i] == 0) return false;
        return true;
    }
    
    void dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<int>& vis) {
        if(vis[node] == 1) {
            ok = false;
            return;
        }
        vis[node] = 1;
        if(leftChild[node] != -1) dfs(leftChild[node], leftChild, rightChild, vis);
        if(rightChild[node] != -1) dfs(rightChild[node], leftChild, rightChild, vis);
    }
};
