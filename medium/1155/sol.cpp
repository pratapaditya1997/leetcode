class Solution {
public:
    int mod = 1e9+7;
    
    void add(int& a, int b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1, vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1; i<=d; i++) {
            for(int j=1; j<=target; j++) {
                for(int cur=1; cur<=f; cur++) {
                    if(j-cur>=0) add(dp[i][j],dp[i-1][j-cur]);
                }
            }
        }
        return dp[d][target];
    }
};
