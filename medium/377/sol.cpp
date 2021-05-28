typedef long long int ll;

class Solution {
public:
    int combinationSum4(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        
        vector<ll> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i=1; i<=target; ++i) {
            for (int j: a) {
                if (i-j < 0) break;
                if (dp[i-j] <= (1LL<<32)) dp[i] += dp[i-j];
            }
        }
        
        return dp[target];
    }
};
