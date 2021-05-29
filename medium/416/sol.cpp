class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int S = accumulate(a.begin(), a.end(), 0);
        
        if (S&1) return false;
        
        vector<bool> old_dp(S + 1, false), cur_dp(S + 1, false);
        old_dp[0] = true;
        
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<=S; ++j) {
                cur_dp[j] = old_dp[j];
                if (j - a[i-1] >= 0) cur_dp[j] = cur_dp[j] || old_dp[j-a[i-1]];
            }
            old_dp = cur_dp;
            fill(cur_dp.begin(), cur_dp.end(), false);
        }
        
        return old_dp[S/2];
    }
};
