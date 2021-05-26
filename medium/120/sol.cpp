const int INF = 1e7 + 5;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size(), m = a[n-1].size();
        if (n == 1) return a[0][0];
        
        vector<vector<int>> dp(n, vector<int>(n, INF));
        dp[0][0] = a[0][0];
        
        int ans = INF;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                int val = dp[i-1][j];
                if (j-1 >= 0) val = min(val, dp[i-1][j-1]);
                dp[i][j] = val + a[i][j];
                if (i == n-1) ans = min(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
