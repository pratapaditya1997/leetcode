class Solution {
public:
    bool ans = true;
    vector<int> color;
    
    void dfs(vector<vector<int>>& g, int u, int c) {
        color[u] = c;
        int nc = 1-c;
        for(int v: g[u]) {
            if(color[v] == nc) continue;
            if(color[v] != -1) {
                ans = false;
                break;
            }
            dfs(g, v, nc);
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, -1);
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) dfs(graph,i,0);
        }
        
        return ans;
    }
};
