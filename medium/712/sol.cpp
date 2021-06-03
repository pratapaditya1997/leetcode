class Solution {
public:
    
    int minimumDeleteSum(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i=1; i<=n; ++i) dp[i][0] = dp[i-1][0] + (int)a[i-1];
        for (int j=1; j<=m; ++j) dp[0][j] = dp[0][j-1] + (int)b[j-1];
        
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int ret = dp[i-1][j-1] + (int)a[i-1] + (int)b[j-1];
                    ret = min(ret, dp[i-1][j] + (int)a[i-1]);
                    ret = min(ret, dp[i][j-1] + (int)b[j-1]);
                    dp[i][j] = ret;
                }
            }
        }
        
        return dp[n][m];
    }
};
