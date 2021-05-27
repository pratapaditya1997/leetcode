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
        vector<ll> cur_dp(target + 1, 0), old_dp(target + 1, 0);
        old_dp[0] = 1;
        
        for (int i=1; i <= n; ++i) {
            ll cur = 0;
            for (int j=1; j <= target; ++j) {
                cur = Add(cur, old_dp[j-1]);
                if (j-f-1 >= 0) cur = Sub(cur, old_dp[j-f-1]);
                cur_dp[j] = cur;
            }
            old_dp = cur_dp;
            cur_dp.assign(target + 1, 0);
        }
        
        return old_dp[target];
    }
};
