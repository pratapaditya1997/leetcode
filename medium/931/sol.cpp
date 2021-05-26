const int INF = 1e7;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int j=0; j<n; ++j) dp[0][j] = a[0][j];
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int ret = dp[i-1][j];
                if (j-1 >= 0) ret = min(ret, dp[i-1][j-1]);
                if (j+1 < n) ret = min(ret, dp[i-1][j+1]);
                dp[i][j] = ret + a[i][j];
            }
        }
        
        int ans = INF;
        for (int j=0; j<n; ++j) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
