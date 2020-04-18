class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
        vector<vector<int>> dp(n, vector<int>(n,10005));
        
        for(int i=0; i<n; i++) dp[i][i] = 0;
        for(int i=0; i<m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            dp[u][v] = min(dp[u][v], w);
            dp[v][u] = min(dp[v][u], w);
        }
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int ans = 0, best = n;
        for(int i=0; i<n; i++) {
            int cur = 0;
            for(int j=0; j<n; j++) {
                if(dp[i][j] <= distanceThreshold) cur++;
            } 
            if(cur <= best) {
                best = cur;
                ans = i;
            }
        }
        return ans;
    }
};
