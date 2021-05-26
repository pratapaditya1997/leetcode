const int inf = 1e7;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount + 1, inf);
        dp[0] = 0; 
        
        for (int i=1; i<=amount; ++i) {
            for (int j: coins) {
                if (i - j < 0) break;
                dp[i] = min(dp[i], dp[i-j] + 1);
            }
        }
        
        if (dp[amount] == inf) return -1;
        return dp[amount];
    }
};
