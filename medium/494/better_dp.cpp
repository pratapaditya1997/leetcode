class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {
        int S = accumulate(a.begin(), a.end(), 0);
        int n = a.size();
        
        vector<int> old_dp(S + 1, 0), cur_dp(S + 1, 0);
        
        old_dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<=S; ++j) {
                cur_dp[j] += old_dp[j];
                if (j - a[i-1] < 0) continue;
                cur_dp[j] += old_dp[j - a[i-1]];
            }
            old_dp = cur_dp;
            cur_dp.assign(S + 1, 0);
        }
        
        int ans = 0;
        for (int j=0; j<=S/2; j++) {
            if (S - 2*j == target || 2*j - S == target) ans += old_dp[j];
        }
        
        return ans;
    }
};
