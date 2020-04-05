class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1,0);
        dp[2] = 1;
        for(int i=4; i<=n; i++) {
            for(int j=1; j<i; j++) {
                if(i%j==0 && dp[i-j] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
