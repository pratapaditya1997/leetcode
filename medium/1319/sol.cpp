vector<vector<int>> g;
vector<int> vis;

void Dfs(int v) {
    vis[v] = 1;
    for (int to: g[v]) {
        if (!vis[to]) Dfs(to);
    }
}

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() < n-1) return -1;
        
        g = vector<vector<int>> (n, vector<int>());
        vis = vector<int> (n, 0);
        
        for (auto edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int comps = 0;
        for (int i=0; i<n; ++i) {
            if (!vis[i]) {
                ++comps;
                Dfs(i);
            }
        }
        
        return comps - 1;
    }
};
