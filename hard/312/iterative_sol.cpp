class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> a; // new array of balloon values with the padding at both ends
        
        a.push_back(1);
        for (int num: nums) {
            if (num > 0) a.push_back(num); // remove 0 value balloons, they anyway contribute 0 to the answer
        }
        a.push_back(1);
        
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // k is the number of balloons between l and r
        // the case when k=0 is already handled by assigning 0 to all DP states
        for (int k=1; k <= n-2; ++k) {
            for (int l=0; l+k+1<n; ++l) {
                int r = l+k+1; // interval (l,r) with k balloons in between
                for (int i=l+1; i<r; ++i) {
                    dp[l][r] = max(dp[l][r], a[l]*a[i]*a[r] + dp[l][i] + dp[i][r]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
