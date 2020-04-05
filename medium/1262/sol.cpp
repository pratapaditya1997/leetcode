class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3,0));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<3; j++) dp[i][j] = dp[i-1][j];
            for(int j=0; j<3; j++) {
                int new_val = (dp[i-1][j] + nums[i-1]);
                dp[i][new_val%3] = max(dp[i][new_val%3], new_val);
            }
        }
        return dp[n][0];
    }
};
