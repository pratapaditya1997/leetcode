class TreeAncestor {
public:
    vector<vector<int>> p;
    
    TreeAncestor(int n, vector<int>& parent) {
        p.resize(n, vector<int>(17, -1));
        for(int i=0; i<n; i++) p[i][0] = parent[i];
        for(int j=1; j<17; j++) {
            for(int i=0; i<n; i++) {
                int par = p[i][j-1];
                if(par != -1) p[i][j] = p[par][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur = node;
        for(int i=16; i>=0; i--) {
            if(k&(1<<i)) cur = p[cur][i];
            if(cur == -1) return cur;
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
