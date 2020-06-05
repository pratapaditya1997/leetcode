const int INF = 1e5;

class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    vector<vector<bool>> is_reachable;
    
    void dfs(int u, int par) {
        vis[u] = true;
        is_reachable[par][u] = true;
        for(int v: g[u]) {
            if(!vis[v]) dfs(v, par);
        }
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<bool> ans(q, false);
        
        g.resize(n);
        for(int i=0; i<n; i++) g[i].clear();
        is_reachable.resize(n, vector<bool>(n, false));
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
        }
        
        for(int i=0; i<n; i++) {
            vis.assign(n, false);
            dfs(i,i);
        }
        
        for(int i=0; i<q; i++) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = is_reachable[u][v];
        }
        return ans;
    }
};
