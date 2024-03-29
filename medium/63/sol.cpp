class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        if (g[0][0]) return 0;
        
        dp[0][0] = 1;
        for (int j=1; j<m; ++j) {
            if (g[0][j]) break;
            dp[0][j] = 1;
        }
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (g[i][j]) continue;
                dp[i][j] = dp[i-1][j];
                if (j-1 >= 0) dp[i][j] += dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
};
