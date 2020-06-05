class Solution {
public:
    vector<vector<pair<int,int>>> g;
    vector<int> vis;
    int ans = 0;
    
    void dfs(int u) {
        vis[u] = 1;
        for(auto v: g[u]) {
            if(!vis[v.first]) {
                ans += v.second;
                dfs(v.first);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.assign(n, false);
        
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back({v,1});
            g[v].push_back({u,0});
        }
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) dfs(i);
        }
        return ans;
    }
};
