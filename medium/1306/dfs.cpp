const int N = 5e4+4;
vector<int> g[N];

class Solution {
public:
    vector<int> vis;
    
    void dfs(int u) {
        vis[u] = 1;
        for(int v: g[u]) {
            if(!vis[v]) dfs(v);
        }
    }
    
    bool canReach(vector<int>& arr, int start) {
        for(int i=0; i<N; i++) g[i].clear();
        
        int n  = arr.size();
        for(int i=0; i<n; i++) {
            if(i-arr[i] >= 0) g[i].push_back(i-arr[i]);
            if(i+arr[i] < n) g[i].push_back(i+arr[i]);
        }
        
        vis.resize(n,0);
        dfs(start);
        for(int i=0; i<n; i++) {
            if(vis[i] && !arr[i]) return true;
        }
        return false;
    }
};
