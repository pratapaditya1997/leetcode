class Solution {
public:
    int mod = 1e9+7;
    
    void add(int& a, int b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    void sub(int& a, int b) {
        a -= b;
        if(a<0) a += mod;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1, vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=d; i++) {
            int cur = 0;
            for(int j=1; j<=target; j++) {
                add(cur,dp[i-1][j-1]);
                if(j>f)  sub(cur,dp[i-1][j-f-1]);
                dp[i][j] = cur;
            }
        }
        return dp[d][target];
    }
};
