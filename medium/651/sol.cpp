class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        for (int i=1; i<=n; ++i) {
            dp[i] = i; // just print i times
            
            for (int j=1; j <= i-3; ++j) {
                dp[i] = max(dp[i], dp[j]*(i-j-1));
            }
        }
        
        return dp[n];
    }
};
