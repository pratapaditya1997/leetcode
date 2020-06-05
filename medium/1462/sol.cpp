const int INF = 1e5;

class Solution {
public:
    vector<vector<int>> g;
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<bool> ans(q, false);
        
        g.resize(n, vector<int>(n,INF));
        for(int i=0; i<n; i++) g[i][i] = 0;
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            g[u][v] = 1;
        }
        
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        
        for(int i=0; i<q; i++) {
            int u = queries[i][0], v = queries[i][1];
            if(g[u][v] < INF) ans[i] = true; 
        }
        return ans;
    }
};
