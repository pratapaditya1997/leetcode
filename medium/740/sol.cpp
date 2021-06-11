class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int n = *max_element(a.begin(), a.end());
        vector<int> dp(n+1, 0), cnt(n+1, 0);
        
        for (int x: a) cnt[x]++;
        
        dp[1] = cnt[1];
        for (int i=2; i<=n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + i * cnt[i]);
        }
        return dp[n];
    }
};
