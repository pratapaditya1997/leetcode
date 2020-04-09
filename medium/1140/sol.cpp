class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        vector<int> suf(n+1,0);
        
        for(int i=n-1; i>=0; i--) suf[i] = suf[i+1] + piles[i];
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=1; j--) {
                for(int x=1; x<=2*j && i+x<=n; x++) {
                    dp[i][j] = max(dp[i][j], suf[i]-dp[i+x][max(x,j)]);
                }
            }
        }
        return dp[0][1];
    }
};
