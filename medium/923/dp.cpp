class Solution {
public:
    const long mod = 1e9+7;
    
    void add(long& a, long b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<vector<long>>> dp(n+1, vector<vector<long>>(target+1, vector<long>(4,0)));
        
        for(int i=0; i<=n; i++) dp[i][0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j <= target; j++) {
                for(int k=1; k<=3; k++) {
                    dp[i][j][k] = dp[i-1][j][k];
                    int prev = j-arr[i-1];
                    if(prev >= 0) add(dp[i][j][k], dp[i-1][prev][k-1]);
                }
            }
        }
        
        return dp[n][target][3];
    }
};
