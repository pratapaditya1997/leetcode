class Solution {
public:
    int mctFromLeafValues(vector<int>& a) {
        int n = a.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0)),
                            maxi(n, vector<int>(n, 0));
        
        for (int i=0; i<n; ++i) {
            int val = a[i];
            for (int j=i; j<n; ++j) {
                val = max(val, a[j]);
                maxi[i][j] = val;
            }
        }
        
        for (int l=2; l<=n; ++l) {
            for (int i=0; i+l-1 < n; ++i) {
                int j = i+l-1, val = INT_MAX;
                for (int k=i; k<j; ++k) {
                    val = min(val, dp[i][k] + dp[k+1][j] + maxi[i][k] * maxi[k+1][j]);
                }
                dp[i][j] = val;
            }
        }
        
        return dp[0][n-1];
    }
};
