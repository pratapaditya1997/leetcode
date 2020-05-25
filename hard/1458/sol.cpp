const int MIN = -1e6;

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, MIN));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dp[i][j] = max(dp[i][j], a[i]*b[j]);
                if(i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(i && j) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]*b[j]);
            }
        }
        return dp[n-1][m-1];
    }
};
