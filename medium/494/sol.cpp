class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {
        int S = accumulate(a.begin(), a.end(), 0);
        int n = a.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));
        
        dp[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<=S; ++j) {
                dp[i][j] += dp[i-1][j];
                if (j - a[i-1] < 0) continue;
                dp[i][j] += dp[i-1][j - a[i-1]];
            }
        }
        
        int ans = 0;
        for (int j=0; j<=S/2; j++) {
            if (S - 2*j == target || 2*j - S == target) ans += dp[n][j];
        }
        
        return ans;
    }
};
