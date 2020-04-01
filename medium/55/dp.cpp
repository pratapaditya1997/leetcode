class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        dp[0] = 1;
        for(int i=0; i<n; i++) {
            if(dp[i]) {
                for(int j=0; j<=nums[i]; j++) {
                    if(i+j < n) dp[i+j] = 1;
                }
            }
        }
        
        return dp[n-1];
    }
};
