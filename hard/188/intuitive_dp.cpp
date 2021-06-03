const int INF = 1e7;

class Solution {
public:
    int Trivial(vector<int>& p) {
        int res = 0, n = p.size();
        for (int i=1; i<n; ++i) {
            if (p[i] - p[i-1] > 0) res += p[i] - p[i-1];
        }
        return res;
    }
    
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        
        if (n <= 0 || k <= 0) return 0;
        if (k >= n/2) return Trivial(p);
        
        // dp state: (days_covered, transactions_used, #stocks held (0 or 1))
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -INF)));
        
        dp[0][0][0] = 0; dp[0][1][1] = -p[0];
        
        for (int i=1; i<n; ++i) {
            for (int j=0; j<=k; ++j) {
                // not holding stock
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + p[i]);
                
                // holding a stock, requires atleast one transaction
                if (j > 0) {
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - p[i]);
                }
            }
        }
        
        int ans = 0;
        for (int j=0; j<=k; ++j) {
            ans = max(ans, dp[n-1][j][0]);
        }
        return ans;
    }
};
