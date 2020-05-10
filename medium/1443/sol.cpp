const int N = 1e5+5;
vector<int> g[N];

class Solution {
public:
    int ans = 0;
    vector<int> sub_sum;
    
    void dfs(int u, int p, vector<bool>& hasApple) {
        sub_sum[u] = hasApple[u] ? 1 : 0;
        for(int v: g[u]) {
            if(v != p) {
                dfs(v, u, hasApple);
                sub_sum[u] += sub_sum[v];
            }
        }
        if(sub_sum[u] > 0 && p != -1) ans += 2;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i=0; i<n; i++) g[i].clear();
        sub_sum.assign(n, 0);
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1, hasApple);
        return ans;
    }
};
