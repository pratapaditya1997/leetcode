class Solution {
public:
    int minCost(vector<vector<int>>& c) {
        int n = c.size();
        vector<int> old_dp(3, 0),
                    cur_dp(3, 0);
        
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<3; ++j) {
                int val = INT_MAX;
                for (int k=0; k<3; ++k) {
                    if (j == k) continue;
                    val = min(val, old_dp[k]);
                }
                cur_dp[j] = val + c[i-1][j];
            }
            old_dp = cur_dp;
            fill(cur_dp.begin(), cur_dp.end(), 0);
        }
        
        return min({old_dp[0], old_dp[1], old_dp[2]});
    }
};
