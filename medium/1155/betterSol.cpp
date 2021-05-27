typedef long long int ll;

const ll MOD = 1e9 + 7;

inline ll Add(ll x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline ll Sub(ll x, ll y) {
    x -= y;
    if (x < 0) x += MOD;
    return x;
}

class Solution {
public:
    int numRollsToTarget(int n, int f, int target) {
        vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, 0));
        dp[0][0] = 1;
        
        for (int i=1; i <= n; ++i) {
            ll cur = 0;
            for (int j=1; j <= target; ++j) {
                cur = Add(cur, dp[i-1][j-1]);
                if (j-f-1 >= 0) cur = Sub(cur, dp[i-1][j-f-1]);
                dp[i][j] = cur;
            }
        }
        
        return dp[n][target];
    }
};
