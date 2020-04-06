class Solution {
public:
    int mod = 1e9+7;
    
    void add(int& a, int b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    int sub(int a, int b) {
        a -= b;
        if(a < 0) a += mod;
        return a;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<int>> dp(n+1, vector<int>(6,0));
        vector<int> sum(n+1,0);
        sum[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<6; j++) {
                for(int k=1; k<=rollMax[j] && i-k>=0; k++) {
                    add(dp[i][j], sub(sum[i-k],dp[i-k][j]));
                }
                add(sum[i], dp[i][j]);
            }
        }
        return sum[n];
    }
};
