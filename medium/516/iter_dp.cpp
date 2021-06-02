class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i=0; i<n; ++i) dp[i][i] = 1;
        for (int i=0; i<n-1; ++i) {
            if (s[i] == s[i+1]) dp[i][i+1] = 2;
            else dp[i][i+1] = 1;
        }
        
        for (int l=3; l<=n; ++l) {
            for (int i=0; i <= n-l; ++i) {
                int j = i+l-1, val = 1;
                if (s[i] == s[j]) val = max(val, 2 + dp[i+1][j-1]);
                val = max(val, dp[i][j-1]);
                val = max(val, dp[i+1][j]);
                dp[i][j] = val;
            }
        }
        
        return dp[0][n-1];
    }
};
