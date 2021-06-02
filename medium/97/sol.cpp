class Solution {
public:
    bool isInterleave(string s, string t, string req) {
        if (s.length() + t.length() != req.length()) return false;
        
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        dp[0][0] = 1;
        for (int j=1; j<=m; ++j) {
            if (t[j-1] == req[j-1] && dp[0][j-1]) dp[0][j] = 1; 
        }
        for (int i=1; i<=n; ++i) {
            if (s[i-1] == req[i-1] && dp[i-1][0]) dp[i][0] = 1; 
        }
        
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (s[i-1] == req[i+j-1] && dp[i-1][j]) dp[i][j] = 1;
                if (t[j-1] == req[i+j-1] && dp[i][j-1]) dp[i][j] = 1;
            }
        }
        
        if (dp[n][m]) return true;
        return false;
    }
};
