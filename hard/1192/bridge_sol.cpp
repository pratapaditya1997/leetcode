const int N = 1e5 + 5;

vector<int> g[N];
vector<bool> vis;
vector<int> tin, low;
int timer;

vector<vector<int>> ans;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = ++timer;
    
    for (int to: g[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                ans.push_back({v, to});
            }
        }
    }
}

void init(int n) {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i=0; i<N; i++) g[i].clear();
    ans.clear();
}

class Solution {
public:
    /**
    * basically find the bridges in the graph
    */
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        init(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        for (int i=0; i<n; i++) {
            if (!vis[i]) dfs(i);
        }
        
        return ans;
    }
};
