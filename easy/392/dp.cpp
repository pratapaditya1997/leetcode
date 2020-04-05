class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length(), m = s.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
