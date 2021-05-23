const int N = 102;

vector<int> g[N];
vector<int> cnt, vis;

void init(int n) {
    for (int i=0; i<N; i++) g[i].clear();
    cnt.assign(n, 0);
    vis.assign(n, 0);
}

class Solution {
public:
    int max_time;
    
    void helper(int v) {
        vis[v] = 1;
        for (int to: g[v]) {
            if (vis[to]) continue;
            cnt[v]++;
            helper(to);
        }
    }
    
    void auto_fill(int v, int t, vector<vector<double>>& dp) {
        for (int j = t; j <= max_time; j++) {
            dp[v][j] = dp[v][t-1];
        }
    }
    
    void dfs(int v, int t, vector<vector<double>>& dp) {
        if (t > max_time) return;
        if (cnt[v] == 0) {
            // leaf node - so prefill all the later entries for this
            auto_fill(v, t, dp);
        }
        vis[v] = 1;
        for (int to: g[v]) {
            if (vis[to]) continue;
            dp[to][t] = (dp[v][t-1] / cnt[v]);
            dfs(to, t + 1, dp);
        }
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        init(n + 1);
        max_time = t;
        
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        helper(1);
        
        vector<vector<double>> dp(n + 1, vector<double>(t + 1, 0.0));
        dp[1][0] = 1.0;
        
        vis.assign(n + 1, 0);
        dfs(1, 1, dp);
        return dp[target][t];
    }
};
