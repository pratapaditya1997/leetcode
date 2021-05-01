const int N = 2e4 + 4;

vector<int> g[N];
vector<int> dist(N), par(N); 

void dfs(int u) {
    for (int v: g[u]) {
        if (dist[v] != -1) continue;
        dist[v] = dist[u] + 1;
        par[v] = u;
        dfs(v);
    }
}

int dfs_helper(int u) {
    fill(dist.begin(), dist.end(), -1);
    fill(par.begin(), par.end(), -1);
    
    dist[u] = 0;
    dfs(u);
    
    return distance(dist.begin(), max_element(dist.begin(), dist.end()));
}

void init() {
    for (int i=0; i<N; i++) {
        g[i].clear();
    }
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        init();
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int idx1 = dfs_helper(0);
        int idx2 = dfs_helper(idx1);
        
        vector<int> diameter;
        while(idx2 !=- 1) {
            diameter.push_back(idx2);
            idx2 = par[idx2];
        }
        
        int m = diameter.size();
        if (m&1) {
            return {diameter[m/2]};
        } else return {diameter[m/2 - 1], diameter[m/2]};
    }
};
