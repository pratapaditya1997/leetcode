class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,0)), maxi(n, vector<int>(n,0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int cur = 0;
                for(int k=i; k<=j; k++) cur = max(cur,arr[k]);
                maxi[i][j] = cur;
            }
        }
        
        for(int len=2; len<=n; len++) {
            for(int i=0; i<n-len+1; i++) {
                int j = i+len-1, best = INT_MAX;
                for(int k=i; k<j; k++) {
                    int cur = maxi[i][k]*maxi[k+1][j] + dp[i][k] + dp[k+1][j];
                    best = min(best, cur);
                }
                dp[i][j] = best;
            }
        }
        return dp[0][n-1];
    }
};
