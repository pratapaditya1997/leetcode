const int MAX_COST = 1e5+5;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {
        vector<int> g[n+1];
        vector<vector<int>> dp(n+1, vector<int>(n+1, MAX_COST));
        
        for(int i=0; i<=n; i++) dp[i][i] = 0;
        for(auto vec: times) {
            int u = vec[0], v = vec[1], w = vec[2];
            dp[u][v] = min(dp[u][v], w);
        }
        
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int maxi = 0;
        for(int i=1; i<=n; i++) maxi = max(maxi, dp[source][i]);
        if(maxi == MAX_COST) return -1;
        return maxi;
    }
};
